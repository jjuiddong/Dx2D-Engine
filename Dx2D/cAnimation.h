#pragma once
#include "cAction.h"

class cAnimation : public cAction
{
protected:
	float	m_fFrameTime;
	float	m_fPassedTime;
	//SYNTHESIZE_PASS_BY_REF(RECT, m_rc, Rect);
	SYNTHESIZE_PASS_BY_REF(ST_SIZE, m_stFrameSize, FrameSize);
	SYNTHESIZE(int, m_nNumHCells, NumHCells);	// °¡·Î Ä­ ¼ö
	SYNTHESIZE(int, m_nNumVCells, NumVCells);	// ¼¼·Î Ä­ ¼ö 
	SYNTHESIZE(int, m_nAnimIndex, AnimIndex);
	SYNTHESIZE(int, m_nMaxFrame, MaxFrame);
	SYNTHESIZE(float, m_fActionTime, ActionTime);
	SYNTHESIZE(float, m_fAnimInterval, AnimInterval);
	
public:
	cAnimation(void);
	~cAnimation(void);

	virtual void Update(float fDeltaTime, cNode* pTarget) override;
};

