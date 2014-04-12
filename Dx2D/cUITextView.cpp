#include "StdAfx.h"
#include "cUITextView.h"
#include "cDeviceManager.h"

cUITextView::cUITextView(LPD3DXSPRITE pSprite)
: cUIObject(pSprite)
, m_pFont(NULL)
, m_nDT(DT_LEFT)
{
	D3DXFONT_DESC desc;
	memset(&desc, 0, sizeof(D3DXFONT_DESC));
	desc.CharSet = HANGUL_CHARSET;
	strcpy(desc.FaceName, "±Ã¼­Ã¼");
	desc.Height = 20;
	desc.Width = 10;
	desc.Weight = FW_NORMAL;
	desc.Quality = DEFAULT_QUALITY;
	desc.MipLevels = 1;
	desc.Italic = 0;
	desc.OutputPrecision = OUT_DEFAULT_PRECIS;
	desc.PitchAndFamily = FF_DONTCARE;

	D3DXCreateFontIndirect(g_pD3DDevice, &desc, &m_pFont);
}

cUITextView::~cUITextView(void)
{
}

void cUITextView::Render()
{
	m_pFont->DrawTextA(NULL, m_sText.c_str(), -1, &m_rc, m_nDT, m_dwColor);
}

void cUITextView::Update( float fDeltaTime )
{
	cUIObject::Update(fDeltaTime);
	SetRect(&m_rc,
		(int)m_mTransform._41,
		(int)m_mTransform._42,
		(int)(m_mTransform._41 + m_stSize.fWidth),
		(int)(m_mTransform._42 + m_stSize.fHeight));
	
}