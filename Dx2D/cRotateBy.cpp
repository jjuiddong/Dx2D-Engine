#include "StdAfx.h"
#include "cRotateBy.h"
#include "cNode.h"

cRotateBy::cRotateBy(void)
: m_fPassedTime(0.0f)
, m_fActionTime(0.0f)
, m_fDeltaAngle(0.0f)
{
}

cRotateBy::~cRotateBy(void)
{
}

void cRotateBy::Update( float fDeltaTime, cNode* pTarget )
{
	m_fPassedTime += fDeltaTime;
	if(m_fPassedTime < m_fActionTime)
	{
		float fAngle= pTarget->GetAngle();
		fAngle += m_fDeltaAngle * (fDeltaTime / m_fActionTime);
		pTarget->SetAngle(fAngle);
	}
	else
	{
		if (!m_bRepeat)
		{
			pTarget->SetAction(NULL);
		}
		else
		{
			m_fPassedTime = 0;
		}
	}
}