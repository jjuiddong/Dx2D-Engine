#pragma once
#include "cAction.h"

class cMoveTo : public cAction
{
private:
	float m_fPassedTime;
	SYNTHESIZE(float, m_fActionTime, ActionTime);
	SYNTHESIZE(D3DXVECTOR3, m_vStart, Start);
	SYNTHESIZE(D3DXVECTOR3, m_vDest, Dest);

public:
	cMoveTo(void);
	~cMoveTo(void);

	virtual void Update(float fDeltaTime, cNode* pTarget) override;
};
