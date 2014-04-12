#pragma once
#include "cAction.h"

class cMoveBy : public cAction
{
protected:
	float m_fPassedTime;
	SYNTHESIZE(float, m_fActionTime, ActionTime);
	SYNTHESIZE(D3DXVECTOR3, m_vAmount, Amount);

public:
	cMoveBy(void);
	virtual ~cMoveBy(void);

	virtual void Update(float fDeltaTime, cNode* pTarget) override;
};
