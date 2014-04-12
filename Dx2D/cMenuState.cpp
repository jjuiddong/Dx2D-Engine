#include "StdAfx.h"
#include "cMenuState.h"
#include "cDeviceManager.h"
#include "cSprite.h"
#include "cTextureManager.h"
#include "cUIObject.h"
#include "cUIImageView.h"
#include "cUITextView.h"
#include "cUIButton.h"
#include "cPlayState.h"

cMenuState::cMenuState(void)
: m_pUIRoot(NULL)
, m_pDelegate(NULL)
{
}

cMenuState::~cMenuState(void)
{
	SAFE_RELEASE(m_pUIRoot);
}

void cMenuState::SetDelegate( iGameStateDelegate* pDelegate )
{
	m_pDelegate = pDelegate;
}

void cMenuState::Setup( LPD3DXSPRITE pSprite )
{
	cTexture* pTexture;
	m_pUIRoot = new cUIImageView(pSprite);
	pTexture = g_TextureManager.GetTexture("back.bmp", D3DCOLOR_XRGB(255, 0, 255));
	m_pUIRoot->SetTexture(pTexture);
	m_pUIRoot->SetRectangle(pTexture->GetImageRect());
	m_pUIRoot->SetAnchorPoint(D3DXVECTOR2(0,0));
	m_pUIRoot->SetPosition(D3DXVECTOR3(200, 50, 0));
	m_pUIRoot->SetSize(ST_SIZE(300, 500));

	cUITextView* pTextView = new cUITextView(NULL);
	pTextView->SetAnchorPoint(D3DXVECTOR2(0,0));
	pTextView->SetPosition(D3DXVECTOR3(10, 10, 0));
	pTextView->SetSize(ST_SIZE(280, 480));
	pTextView->SetTextColor(D3DCOLOR_XRGB(0,0,0));
	pTextView->SetDrawTextFormat(DT_LEFT /*| DT_VCENTER */| DT_WORDBREAK);
	pTextView->SetText(std::string("동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 동해물과 백두산이 마르고 닳도록 "));
	m_pUIRoot->AddChild(pTextView);
	pTextView->Release();

	cUIButton* pButton = new cUIButton(pSprite);
	pTexture = g_TextureManager.GetTexture("btn_normal.bmp", D3DCOLOR_XRGB(255, 0, 255));
	pButton->SetNormalTexture(pTexture);
	pButton->SetRectangle(pTexture->GetImageRect());
	pTexture = g_TextureManager.GetTexture("btn_mover.bmp", D3DCOLOR_XRGB(255, 0, 255));
	pButton->SetMouseOverTexture(pTexture);
	pTexture = g_TextureManager.GetTexture("btn_selected.bmp", D3DCOLOR_XRGB(255, 0, 255));
	pButton->SetSelectedTexture(pTexture);
	pButton->SetAnchorPoint(D3DXVECTOR2(0,0));
	pButton->SetPosition(D3DXVECTOR3(25, 450, 0));
	pButton->SetSize(ST_SIZE(280, 480));
	pButton->SetDelegate(this);
	pButton->SetTag(2);
	m_pUIRoot->AddChild(pButton);
	pButton->Release();

	pButton = new cUIButton(pSprite);
	pTexture = g_TextureManager.GetTexture("btn_normal.bmp", D3DCOLOR_XRGB(255, 0, 255));
	pButton->SetNormalTexture(pTexture);
	pButton->SetRectangle(pTexture->GetImageRect());
	pTexture = g_TextureManager.GetTexture("btn_mover.bmp", D3DCOLOR_XRGB(255, 0, 255));
	pButton->SetMouseOverTexture(pTexture);
	pTexture = g_TextureManager.GetTexture("btn_selected.bmp", D3DCOLOR_XRGB(255, 0, 255));
	pButton->SetSelectedTexture(pTexture);
	pButton->SetAnchorPoint(D3DXVECTOR2(0,0));
	pButton->SetPosition(D3DXVECTOR3(25, 390, 0));
	pButton->SetSize(ST_SIZE(280, 480));
	pButton->SetDelegate(this);
	pButton->SetTag(1);
	m_pUIRoot->AddChild(pButton);
	pButton->Release();
}

void cMenuState::Update(float fDeltaTime)
{
	m_pUIRoot->Update(fDeltaTime);
}

void cMenuState::Render()
{
	m_pUIRoot->Render();
}

bool cMenuState::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	if(m_pUIRoot)
		m_pUIRoot->MsgProc(hWnd, message, wParam, lParam);
	return false;
}

void cMenuState::OnClick( cUIObject* pSender )
{
	if(m_pDelegate)
	{
		iGameState* pState = new cPlayState;
		m_pDelegate->OnChangeState(pState);
	}
}