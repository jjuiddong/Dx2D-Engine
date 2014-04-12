#include "StdAfx.h"
#include "cActionSpawn.h"

cActionSpawn::cActionSpawn(void)
{
}

cActionSpawn::~cActionSpawn(void)
{
	for (int i = 0; i < m_vecActions.size(); ++i)
	{
		SAFE_RELEASE(m_vecActions[i]);
	}
	m_vecActions.clear();
}

void cActionSpawn::Update( float fDeltaTime, cNode* pTarget )
{
	if(m_vecActions.empty())
		return;
	for (int i = 0; i < m_vecActions.size(); ++i)
	{
		m_vecActions[i]->Update(fDeltaTime, pTarget);
	}
}