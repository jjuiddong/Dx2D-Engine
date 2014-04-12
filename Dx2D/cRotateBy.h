#pragma once
#include "cAction.h"

class cRotateBy : public cAction
{
protected:
	float m_fPassedTime;
	SYNTHESIZE(float, m_fActionTime, ActionTime);
	SYNTHESIZE(float, m_fDeltaAngle, DeltaAngle);

public:
	cRotateBy(void);
	virtual ~cRotateBy(void);

	virtual void Update(float fDeltaTime, cNode* pTarget) override;
};
