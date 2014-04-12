#include "StdAfx.h"
#include "cSprite.h"
#include "cDeviceManager.h"
#include "cTexture.h"
#include "cMoveTo.h"

cSprite::cSprite(LPD3DXSPRITE pSprite)
: m_pSprite(NULL)
, m_pTexture(NULL)
{
	SAFE_ADDREF(pSprite);
	m_pSprite = pSprite;
	m_dwColor = D3DCOLOR_ARGB(255, 255, 255, 255);
}

cSprite::~cSprite(void)
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pTexture);
}

void cSprite::Update(float fDeltaTime)
{
	cNode::Update(fDeltaTime);

	m_vCenter.x = m_stSize.fWidth * m_vAnchorPoint.x;
	m_vCenter.y = m_stSize.fHeight * m_vAnchorPoint.y;
}

void cSprite::Render()
{
	if(m_pTexture)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_BORDER);
		g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER);
		
		m_pSprite->SetTransform(&m_mTransform);
		m_pSprite->Draw(m_pTexture->m_pTexture, &m_rc, &m_vCenter, NULL, m_dwColor);
		m_pSprite->End();
	}

	cNode::Render();
}

void cSprite::OnRecieveMessage( std::string& sKey, cObject* pSender )
{
	cMoveTo* pMoveTo = (cMoveTo*)pSender;
	int a = 0;
}