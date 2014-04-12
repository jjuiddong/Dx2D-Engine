#include "StdAfx.h"
#include "cParticleSystem.h"
#include "cParticle.h"
#include "cDeviceManager.h"

cParticleSystem::cParticleSystem(LPD3DXSPRITE pSprite)
: m_fLifespan(0.0f)
, m_fLifespanVar(0.0f)
, m_fStartSize(0.0f)
, m_fStartSizeVar(0.0f)
, m_fFinishSize(0.0f)
, m_fFinishSizeVar(0.0f)
, m_fEmitterAngle(0.0f)
, m_fEmitterAngleVar(0.0f)
, m_fStartRot(0.0f)
, m_fStartRotVar(0.0f)
, m_fEndRot(0.0f)
, m_fEndRotVar(0.0f)
, m_fXVar(0.0f)
, m_fYVar(0.0f)
, m_fSpeed(0.0f)
, m_fSpeedVar(0.0f)
, m_fGravityX(0.0f)
, m_fGravityY(0.0f)
, m_fTanAcc(0.0f)
, m_fTanAccVar(0.0f)
, m_fRadAcc(0.0f)
, m_fRadAccVar(0.0f)
, m_dwStartColor(0)
, m_dwStartColorVar(0)
, m_dwFinishColor(0)
, m_dwFinishColorVar(0)
{
	SAFE_ADDREF(pSprite);
	m_pSprite = pSprite;
}

cParticleSystem::~cParticleSystem(void)
{
	SAFE_RELEASE(m_pSprite);
}

void cParticleSystem::Setup( int nMaxParticles )
{
	m_vecParticles.resize(500);
	
}

void cParticleSystem::Update( float fDeltaTime )
{
	cNode::Update(fDeltaTime);

	cTexture* pTexture = g_TextureManager.GetTexture("./particle/circle.png");
	for (int i = 0; i < m_vecParticles.size(); ++i)
	{
		if(m_vecParticles[i] == NULL)
		{
			cParticle* pCircle = new cParticle(m_pSprite);
			pCircle->SetTexture(pTexture);
			pCircle->SetColor(D3DCOLOR_XRGB(255, 80, 30));

			D3DXVECTOR3 v1 = D3DXVECTOR3(300, 400, 0);
			float fAngle = (float)(rand() % 100000) / 10000.0f;
			D3DXVECTOR3 v2 = D3DXVECTOR3(cosf(fAngle),sinf(fAngle), 0);
			v2 *= (float)(rand() % 1000 - 500) / 50.0f;
			pCircle->SetStartPosition(v1 + v2);

			pCircle->SetRectangle(pTexture->GetImageRect());
			pCircle->SetAnchorPoint(D3DXVECTOR2(0.5,0.5));
			pCircle->SetSize(ST_SIZE(32, 32));
			pCircle->SetDirection(D3DXVECTOR3(0, -1, 0));
			pCircle->SetLifespan(1.5f + (rand() % 5) / 10.f);
			//pCircle->SetLifespanVar(1.9);
			pCircle->SetStartSize(3.0f);
			//pCircle->SetStartSizeVar(49.5f);
			pCircle->SetFinishSize(0.5f);
			//pCircle->SetFinishSizeVar(5.0f);
			pCircle->SetEmitterAngle(270.0f);
			pCircle->SetSpeed(150.0f);
			//pCircle->SetSpeedVar(30.0f);

			pCircle->SetStartColor(
				D3DCOLOR_ARGB(  (DWORD)(255 * 0.6f),
				(DWORD)(255 * 1.0f),
				(DWORD)(255 * 0.3f),
				(DWORD)(255 * 0.0f)));
			pCircle->SetFinishColor(
				D3DCOLOR_ARGB(	(DWORD)(255 * 0.0f),
				(DWORD)(255 * 1.0f),
				(DWORD)(255 * 0.3f),
				(DWORD)(255 * 0.0f)));

			m_vecParticles[i] = pCircle;

			pCircle->SetDelegate(this);
			this->AddChild(pCircle);

			pCircle->Release();
			break;
		}
		else if(m_vecParticles[i]->IsFinish())
		{
			
		}
		else
		{
			continue;
		}
	}
}

void cParticleSystem::OnDead( cParticle* pParticle )
{
	pParticle->SetPassedTime(0);
	pParticle->SetLifespan(1.5f + (rand() % 5) / 10.f);
}