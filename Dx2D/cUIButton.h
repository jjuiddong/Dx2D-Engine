#pragma once
#include "cUIImageView.h"

class iUIButtonDelegate
{
public:
	virtual void OnClick(cUIObject* pSender) = 0;
};

class cUIButton : public cUIImageView
{
protected:
	enum eButtonState
	{
		E_NORMAL,
		E_MOVER,
		E_SELECTED
	};
	
	eButtonState	m_eButtonState;

	SYNTHESIZE(iUIButtonDelegate*, m_pDelegate, Delegate);
	SYNTHESIZE_ADDREF(cTexture*, m_pNormalTexture, NormalTexture);
	SYNTHESIZE_ADDREF(cTexture*, m_pMouseOverTexture, MouseOverTexture);
	SYNTHESIZE_ADDREF(cTexture*, m_pSelectedTexture, SelectedTexture);
public:
	cUIButton(LPD3DXSPRITE pSprite);
	virtual ~cUIButton(void);

	virtual void Render() override;
	virtual bool MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
};
