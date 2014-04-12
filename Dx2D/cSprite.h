#pragma once
#include "cNode.h"
#include "cTexture.h"

class cSprite : public cNode
{
protected:
	LPD3DXSPRITE		m_pSprite;			// 스프라이트
	
	SYNTHESIZE_ADDREF(cTexture*, m_pTexture, Texture);
	SYNTHESIZE(D3DCOLOR, m_dwColor, Color);

public:
	cSprite(LPD3DXSPRITE pSprite);
	virtual ~cSprite(void);
	
	virtual void Update(float fDeltaTime) override;
	virtual void Render() override;
	
	void SetSize(ST_SIZE& stSize)
	{
		m_stSize = stSize;
	}

	void SetAngle(float fAngle)
	{
		m_fAngle = fAngle;
	}

	void SetAnchorPoint(D3DXVECTOR2& vAnchorPoint)
	{
		m_vAnchorPoint = vAnchorPoint;
	}

	virtual std::string Description() override
	{
		return "";
	}
	virtual void OnRecieveMessage(std::string& sKey, cObject* pSender);
};

