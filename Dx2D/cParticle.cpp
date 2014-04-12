#include "StdAfx.h"
#include "cParticle.h"
#include "cDeviceManager.h"

cParticle::cParticle(LPD3DXSPRITE pSprite)
: cSprite(pSprite)
, m_fPassedTime(0.0f)
, m_fLifespan(0.0f)
, m_fStartSize(0.0f)
, m_fFinishSize(0.0f)
, m_fEmitterAngle(0.0f)
, m_fStartRot(0.0f)
, m_fEndRot(0.0f)
, m_fSpeed(0.0f)
, m_vDirection(0,0,0)
, m_fGravityX(0.0f)
, m_fGravityY(0.0f)
, m_fTanAcc(0.0f)
, m_fRadAcc(0.0f)
, m_stStartColor(0,0,0,0)
, m_stFinishColor(0,0,0,0)
, m_pDelegate(NULL)
{
}

cParticle::~cParticle(void)
{
}

void cParticle::Update( float fDeltaTime )
{
	cSprite::Update(fDeltaTime);

	m_fPassedTime += fDeltaTime;

	if(IsFinish())
	{
		if(m_pDelegate)
			m_pDelegate->OnDead(this);
		return;
	}

	float t = m_fPassedTime / m_fLifespan;
	
	//if(t > 1.0f) t = 1.0f;
	// color
	D3DXCOLOR c = (1.0f - t) * m_stStartColor + t * m_stFinishColor;

	DWORD dwA = 255 * c.a;
	if(dwA > 255) dwA = 255;

	DWORD dwR = 255 * c.r;
	if(dwR > 255) dwR = 255;

	DWORD dwG = 255 * c.g;
	if(dwG > 255) dwG = 255;

	DWORD dwB = 255 * c.b;
	if(dwB > 255) dwB = 255;

	m_dwColor = D3DCOLOR_ARGB(dwA, dwR, dwG, dwB);
	
	// position
	m_vFinishPosition = m_vStartPosition + m_fLifespan * m_vDirection * m_fSpeed;
	D3DXVec3Lerp(&m_vPosition, &m_vStartPosition, &m_vFinishPosition, t);
	
	// scale
	float s = (1.0f - t) * m_fStartSize + t * m_fFinishSize;
	m_vScale.x = m_vScale.y = s;
}

void cParticle::Render()
{
	if(IsFinish())
	{
		return;
	}
	
	if(m_pTexture)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_BORDER);
		g_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_BORDER);

		g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

		m_pSprite->SetTransform(&m_mTransform);
		m_pSprite->Draw(m_pTexture->GetTexture(), &m_rc, &m_vCenter, NULL, m_dwColor);
		m_pSprite->End();
	}

	cNode::Render();
}


