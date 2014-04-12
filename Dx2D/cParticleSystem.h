#pragma once
#include "cNode.h"
#include "cTexture.h"
#include "cTextureManager.h"
#include "cParticle.h"

class cParticleSystem
	: public cNode
	, public iParticleDelegate
{
protected:
	LPD3DXSPRITE			m_pSprite;
	std::vector<cParticle*>	m_vecParticles;
	//SYNTHESIZE(int, m_nMaxParticles, MaxParticles);

	SYNTHESIZE(float,	m_fPassedTime,		PassedTime);
	SYNTHESIZE(float,	m_fLifespan,		Lifespan);
	SYNTHESIZE(float,	m_fStartSize,		StartSize);	
	SYNTHESIZE(float,	m_fFinishSize,		FinishSize);	
	SYNTHESIZE(float,	m_fEmitterAngle,	EmitterAngle);		
	SYNTHESIZE(float,	m_fStartRot,		StartRot);			
	SYNTHESIZE(float,	m_fEndRot,			EndRot);	
	SYNTHESIZE(float,	m_fSpeed,			Speed);
	SYNTHESIZE(float,	m_fGravityX,		GravityX);	
	SYNTHESIZE(float,	m_fGravityY,		GravityY);	
	SYNTHESIZE(float,	m_fTanAcc,			TanAcc);
	SYNTHESIZE(float,	m_fRadAcc,			RadAcc);
	SYNTHESIZE(D3DCOLOR,m_dwStartColor,		StartColor);
	SYNTHESIZE(D3DCOLOR,m_dwFinishColor,	FinishColor);

	SYNTHESIZE(float,	m_fLifespanVar,		LifespanVar);
	SYNTHESIZE(float,	m_fStartSizeVar,	StartSizeVar);		
	SYNTHESIZE(float,	m_fFinishSizeVar,	FinishSizeVar);	
	SYNTHESIZE(float,	m_fEmitterAngleVar,	EmitterAngleVar);			 
	SYNTHESIZE(float,	m_fStartRotVar,		StartRotVar);
	SYNTHESIZE(float,	m_fEndRotVar,		EndRotVar);	
	SYNTHESIZE(float,	m_fXVar,			XVar);		
	SYNTHESIZE(float,	m_fYVar,			YVar);
	SYNTHESIZE(float,	m_fSpeedVar,		SpeedVar);	
	SYNTHESIZE(float,	m_fTanAccVar,		TanAccVar);	
	SYNTHESIZE(float,	m_fRadAccVar,		RadAccVar);	
	SYNTHESIZE(D3DCOLOR,m_dwStartColorVar,	StartColorVar);
	SYNTHESIZE(D3DCOLOR,m_dwFinishColorVar, FinishColorVar);

public:
	cParticleSystem(LPD3DXSPRITE pSprite);
	~cParticleSystem(void);

	void Setup(int nMaxParticles);
	
	virtual std::string Description() override
	{
		return "";
	}

	// cNode
	virtual void Update(float fDeltaTime) override;

	// iParticleDelegate
	virtual void OnDead(cParticle* pParticle) override;
};
