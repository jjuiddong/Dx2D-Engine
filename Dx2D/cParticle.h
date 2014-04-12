#pragma once
#include "cSprite.h"

class cParticle;

class iParticleDelegate
{
public:
	virtual void OnDead(cParticle* pParticle) = 0;
};

class cParticle : public cSprite
{
protected:
	SYNTHESIZE(float,		m_fPassedTime,		PassedTime);
	SYNTHESIZE(float,		m_fLifespan,		Lifespan);
	SYNTHESIZE(float,		m_fStartSize,		StartSize);	
	SYNTHESIZE(float,		m_fFinishSize,		FinishSize);	
	SYNTHESIZE(float,		m_fEmitterAngle,	EmitterAngle);		
	SYNTHESIZE(float,		m_fStartRot,		StartRot);			
	SYNTHESIZE(float,		m_fEndRot,			EndRot);	
	SYNTHESIZE(float,		m_fSpeed,			Speed);
	SYNTHESIZE(D3DXVECTOR3,	m_vDirection,		Direction);
	SYNTHESIZE(float,		m_fGravityX,		GravityX);	
	SYNTHESIZE(float,		m_fGravityY,		GravityY);	
	SYNTHESIZE(float,		m_fTanAcc,			TanAcc);
	SYNTHESIZE(float,		m_fRadAcc,			RadAcc);
	SYNTHESIZE(D3DXCOLOR,	m_stStartColor,		StartColor);
	SYNTHESIZE(D3DXCOLOR,	m_stFinishColor,	FinishColor);
	SYNTHESIZE(iParticleDelegate*,	m_pDelegate,Delegate);


	D3DXVECTOR3 m_vFinishPosition;
	D3DXVECTOR3 m_vStartPosition;
public:
	virtual void SetStartPosition(D3DXVECTOR3& vStartPosition)
	{
		m_vPosition = vStartPosition;
		m_vStartPosition = vStartPosition;
	}

public:
	cParticle(LPD3DXSPRITE pSprite);
	~cParticle(void);

	virtual std::string Description() override
	{
		return "";
	}

	virtual void Update(float fDeltaTime) override;
	
	virtual void Render() override;

	bool IsFinish()
	{
		return m_fPassedTime > m_fLifespan;
	}

	
};

