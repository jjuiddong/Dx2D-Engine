#pragma once
#include "cObject.h"

class cNode;

class cAction : public cObject
{
protected:
	SYNTHESIZE(bool, m_bRepeat, Repeat);

public:
	cAction(void);
	virtual ~cAction(void);

	virtual void Update(float fDeltaTime, cNode* pTarget) = 0;
	virtual std::string Description() { return ""; }
};
