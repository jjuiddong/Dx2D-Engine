#pragma once
#include "iGameState.h"

class cSprite;

class cPlayState
	: public iGameState

{
private:
	cSprite*				m_pRoot;

public:
	cPlayState(void);
	virtual ~cPlayState(void);

	virtual void SetDelegate(iGameStateDelegate* pDelegate);
	virtual void Setup(LPD3DXSPRITE pSprite);
	virtual void Update(float fDeltaTime);
	virtual void Render();
	virtual bool MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	// cObject
	virtual std::string Description()
	{
		return "";
	}
};
