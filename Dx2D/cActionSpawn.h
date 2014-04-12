#pragma once
#include "cAction.h"

class cActionSpawn : public cAction
{
protected:
	std::vector<cAction*> m_vecActions;

public:
	cActionSpawn(void);
	virtual ~cActionSpawn(void);

	virtual void AddAction(cAction* pAction)
	{
		SAFE_ADDREF(pAction);
		m_vecActions.push_back(pAction);
	}
	virtual void Update(float fDeltaTime, cNode* pTarget) override;
};
