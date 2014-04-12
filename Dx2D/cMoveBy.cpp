#include "StdAfx.h"
#include "cMoveBy.h"
#include "cNode.h"

cMoveBy::cMoveBy(void)
: m_fActionTime(0.0f)
, m_fPassedTime(0.0f)
, m_vAmount(0.0f, 0.0f, 0.0f)
{
}

cMoveBy::~cMoveBy(void)
{
}

void cMoveBy::Update( float fDeltaTime, cNode* pTarget )
{
	m_fPassedTime += fDeltaTime;
	if(m_fPassedTime < m_fActionTime)
	{
		D3DXVECTOR3 vPos = pTarget->GetPosition();
		vPos += m_vAmount * (fDeltaTime / m_fActionTime);
		pTarget->SetPosition(vPos);
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