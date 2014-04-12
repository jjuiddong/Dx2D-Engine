#include "StdAfx.h"
#include "cUIButton.h"
#include "cDeviceManager.h"


cUIButton::cUIButton(LPD3DXSPRITE pSprite)
: cUIImageView(pSprite)
, m_pNormalTexture(NULL)
, m_pMouseOverTexture(NULL)
, m_pSelectedTexture(NULL)
, m_eButtonState(E_NORMAL)
, m_pDelegate(NULL)
{
}

cUIButton::~cUIButton(void)
{
	SAFE_RELEASE(m_pNormalTexture);
	SAFE_RELEASE(m_pMouseOverTexture);
	SAFE_RELEASE(m_pSelectedTexture);
}

void cUIButton::Render()
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_BORDER);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER);
	m_pSprite->SetTransform(&m_mTransform);
	LPDIRECT3DTEXTURE9 pTexture = NULL;
	if(m_eButtonState == E_NORMAL)
	{
		pTexture = m_pNormalTexture->GetTexture();
	}
	else if(m_eButtonState == E_MOVER)
	{
		pTexture = m_pMouseOverTexture->GetTexture();
	}
	else if(m_eButtonState == E_SELECTED)
	{
		pTexture = m_pSelectedTexture->GetTexture();
	}

	m_pSprite->Draw(pTexture, &m_rc, &m_vCenter, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	m_pSprite->End();

	cUIImageView::Render();
}

bool cUIButton::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			RECT rc = m_rc;
			rc.left += m_mTransform._41;
			rc.top += m_mTransform._42;
			rc.right += m_mTransform._41;
			rc.bottom += m_mTransform._42;

			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			if(PtInRect(&rc, pt))
			{
				m_eButtonState = E_SELECTED;
			}
		}
		break;
	case WM_LBUTTONUP:
		{
			RECT rc = m_rc;
			rc.left += m_mTransform._41;
			rc.top += m_mTransform._42;
			rc.right += m_mTransform._41;
			rc.bottom += m_mTransform._42;

			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			if(PtInRect(&rc, pt))
			{
				if(m_eButtonState == E_SELECTED)
				{
					if(m_pDelegate)
						m_pDelegate->OnClick(this);
				}

				m_eButtonState = E_MOVER;
			}
			else
			{
				m_eButtonState = E_NORMAL;
			}
		}
		break;
	case WM_MOUSEMOVE:
		{
			RECT rc = m_rc;
			rc.left += m_mTransform._41;
			rc.top += m_mTransform._42;
			rc.right += m_mTransform._41;
			rc.bottom += m_mTransform._42;

			POINT pt;
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);

			if(PtInRect(&rc, pt))
			{
				if(m_eButtonState == E_NORMAL)
				{
					m_eButtonState = E_MOVER;
				}
			}
			else
			{
				if(m_eButtonState == E_MOVER)
				{
					m_eButtonState = E_NORMAL;
				}
			}
		}
		break;
	}
	return false;
}