#include "StdAfx.h"
#include "cAnimation.h"
#include "cNode.h"

cAnimation::cAnimation(void)
: m_fFrameTime(0.0f)
, m_fPassedTime(0.0f)
, m_stFrameSize(0.0f, 0.0f)
, m_nNumHCells(0)
, m_nNumVCells(0)
, m_nAnimIndex(0)
, m_nMaxFrame(0)
, m_fActionTime(0) 
, m_fAnimInterval(0)
{
}

cAnimation::~cAnimation(void)
{
}

void cAnimation::Update( float fDeltaTime, cNode* pTarget )
{
	m_fPassedTime += fDeltaTime;
	m_fFrameTime += fDeltaTime;
	if(m_fPassedTime < m_fActionTime)
	{
		if(m_fFrameTime >= m_fAnimInterval)
		{
			m_fFrameTime -= m_fAnimInterval;
			++m_nAnimIndex;
			m_nAnimIndex %= m_nMaxFrame;

			float fLeft = (m_nAnimIndex % m_nNumHCells) * m_stFrameSize.fWidth;
			float fTop = (m_nAnimIndex / m_nNumHCells) * m_stFrameSize.fHeight;
			RECT rc;
			::SetRect(&rc,
				fLeft,
				fTop,
				fLeft + m_stFrameSize.fWidth,
				fTop + m_stFrameSize.fHeight);
			pTarget->SetRectangle(rc);
		}
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