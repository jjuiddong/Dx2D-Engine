#pragma once
#include "cSprite.h"

class cUIObject : public cSprite
{
public:
	cUIObject(LPD3DXSPRITE pSprite);
	virtual ~cUIObject(void);

	virtual bool MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
