#pragma once
#include "iGameState.h"
#include "cUIButton.h"

class cMenuState
	: public iGameState
	, public iUIButtonDelegate

{
protected:
	cUIObject*				m_pUIRoot;
	iGameStateDelegate*		m_pDelegate;

public:
	cMenuState(void);
	virtual ~cMenuState(void);
	
	// iGameState
	virtual void SetDelegate(iGameStateDelegate* pDelegate);
	virtual void Setup(LPD3DXSPRITE pSprite) override;
	virtual void Update(float fDeltaTime) override;
	virtual void Render() override;
	virtual bool MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;

	// iUIButtonDelegate
	virtual void OnClick(cUIObject* pSender);

	// cObject
	virtual std::string Description()
	{
		return "";
	}
};
