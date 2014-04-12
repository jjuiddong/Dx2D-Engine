#include "StdAfx.h"
#include "cUIObject.h"

cUIObject::cUIObject(LPD3DXSPRITE pSprite)
: cSprite(pSprite)
{
}

cUIObject::~cUIObject(void)
{
}

bool cUIObject::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	std::list<cNode*>::iterator it;
	for (it = m_lstChild.begin(); it != m_lstChild.end(); ++it)
	{
		((cUIObject*)(*it))->MsgProc(hWnd, message, wParam, lParam);
	}
	return false;
}