#pragma once
#include "cUIObject.h"

class cUITextView : public cUIObject
{
protected:
	LPD3DXFONT m_pFont;
	SYNTHESIZE(int, m_nDT, DrawTextFormat);
	SYNTHESIZE(D3DCOLOR, m_dwColor, TextColor);
	SYNTHESIZE(std::string, m_sText, Text);
public:
	cUITextView(LPD3DXSPRITE pSprite);
	~cUITextView(void);

	virtual void Update(float fDeltaTime) override;
	virtual void Render() override;
};
