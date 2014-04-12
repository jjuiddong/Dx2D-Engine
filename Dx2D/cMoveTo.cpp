#include "StdAfx.h"
#include "cMoveTo.h"
#include "cNode.h"
#include "cMessgeCenter.h"

cMoveTo::cMoveTo(void)
: m_fActionTime(0.0f)
, m_fPassedTime(0.0f)
, m_vStart(0.0f, 0.0f, 0.0f)
, m_vDest(0.0f, 0.0f, 0.0f)
{
}

cMoveTo::~cMoveTo(void)
{
}

void cMoveTo::Update( float fDeltaTime, cNode* pTarget )
{
	m_fPassedTime += fDeltaTime;
	
	if(m_fPassedTime < m_fActionTime)
	{
		float t = m_fPassedTime / m_fActionTime;
		D3DXVECTOR3 vPos = (1.0f - t) * m_vStart + t * m_vDest;
		pTarget->SetPosition(vPos);
	}
	else
	{
		g_MessgeCenter.PostMessage(std::string("cMoveToEnd"), this);
		pTarget->SetPosition(m_vDest);
		pTarget->SetAction(NULL);
	}	
}