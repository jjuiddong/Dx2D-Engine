#include "StdAfx.h"
#include "cTexture.h"
#include "cDeviceManager.h"

cTexture::cTexture(char* szFileName, D3DCOLOR dwColorKey/* = 0*/)
: m_pTexture(NULL)
{
	LoadTexture(szFileName, dwColorKey);
}

cTexture::cTexture( std::string sFileName, D3DCOLOR dwColorKey /*= 0*/ )
: m_pTexture(NULL)
{
	LoadTexture(sFileName.c_str(), dwColorKey);
}
cTexture::~cTexture(void)
{
	SAFE_RELEASE(m_pTexture);
}

void cTexture::LoadTexture(const char* szFileName, D3DCOLOR dwColorKey/* = 0*/)
{
	D3DXCreateTextureFromFileEx(
		g_pD3DDevice,
		szFileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		NULL,
		NULL,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		dwColorKey,
		&m_stImageInfo,
		NULL,
		&m_pTexture);
}

D3DCOLOR cTexture::GetColor( POINT pt )
{
	D3DLOCKED_RECT LockedRect;
	m_pTexture->LockRect(0, &LockedRect, NULL, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockedRect.pBits;
	int nIdx = pt.y * m_stImageInfo.Width + pt.x;
	D3DCOLOR c = pColor[nIdx];
	m_pTexture->UnlockRect(NULL);

	return c;
}

void cTexture::SetColor( D3DCOLOR c )
{
	D3DLOCKED_RECT LockedRect;
	m_pTexture->LockRect(0, &LockedRect, NULL, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockedRect.pBits;
	
	for (int i = 0; i < (int)m_stImageInfo.Height; ++i)
	{
		for (int j = 0; j < (int)m_stImageInfo.Width; ++j)
		{
			pColor[i * m_stImageInfo.Width + j] = c;
		}
	}

	m_pTexture->UnlockRect(NULL);
}

void cTexture::SetColorCircle( D3DCOLOR c, POINT ptCenter, float fRadius )
{
	D3DLOCKED_RECT LockedRect;
	m_pTexture->LockRect(0, &LockedRect, NULL, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockedRect.pBits;

	for (int i = 0; i < (int)m_stImageInfo.Height; ++i)
	{
		for (int j = 0; j < (int)m_stImageInfo.Width; ++j)
		{
			POINT p;
			p.x = j;
			p.y = i;
			if(SqLength(p, ptCenter) < fRadius * fRadius)
			{
				pColor[i * m_stImageInfo.Width + j] = c;
			}
		}
	}

	m_pTexture->UnlockRect(NULL);
}

void cTexture::MirroredImage()
{
	D3DLOCKED_RECT LockedRect;
	m_pTexture->LockRect(0, &LockedRect, NULL, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockedRect.pBits;

	for (int i = 0; i < (int)m_stImageInfo.Height; ++i)
	{
		for (int j = 0; j < (int)m_stImageInfo.Width / 2; ++j)
		{
			POINT p;
			p.x = j;
			p.y = i;

			DWORD* pColor = (DWORD*)LockedRect.pBits;
			int nIdx1 = p.y * m_stImageInfo.Width + p.x;
			int nIdx2 = p.y * m_stImageInfo.Width + m_stImageInfo.Width - 1 - p.x;
			D3DCOLOR c = pColor[nIdx1];
			pColor[nIdx1] = pColor[nIdx2];
			pColor[nIdx2] = c;

		}
	}

	m_pTexture->UnlockRect(NULL);
}

void cTexture::GetHeightAndAngle( IN int nTopBound,
								 IN int nX,
								 OUT int& nHeight,
								 OUT float& fAngle )
{
	D3DLOCKED_RECT LockedRect;
	m_pTexture->LockRect(0, &LockedRect, NULL, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockedRect.pBits;
	m_pTexture->UnlockRect(NULL);

	for (int i = nTopBound; i < (int)m_stImageInfo.Height; ++i)
	{
		int nIdx = i * m_stImageInfo.Width + nX;
		D3DCOLOR c = pColor[nIdx];
		if(0xff000000 & c)
		{
			m_pTexture->UnlockRect(NULL);
			nHeight = i;
			break;
		}
	}

	int nLeftHeight = nTopBound;
	int nRightHeight = nTopBound;
	
	for (int i = nTopBound; i < (int)m_stImageInfo.Height; ++i)
	{
		int nIdx = i * m_stImageInfo.Width + nX - 3;
		D3DCOLOR c = pColor[nIdx];
		if(0xff000000 & c)
		{
			m_pTexture->UnlockRect(NULL);
			nLeftHeight = i;
			break;
		}
	}

	for (int i = nTopBound; i < (int)m_stImageInfo.Height; ++i)
	{
		int nIdx = i * m_stImageInfo.Width + nX + 3;
		D3DCOLOR c = pColor[nIdx];
		if(0xff000000 & c)
		{
			m_pTexture->UnlockRect(NULL);
			nRightHeight = i;
			break;
		}
	}

	float fDeltaX = 6.0f;
	float fDeltaY = nRightHeight - nLeftHeight;
	fAngle = atan2(fDeltaY, fDeltaX);
}