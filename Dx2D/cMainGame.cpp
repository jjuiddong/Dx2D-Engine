#include "StdAfx.h"
#include "cMainGame.h"
#include "cDeviceManager.h"
#include "cSprite.h"
//#include "cTest.h"
#include "cMoveBy.h"
#include "cMoveTo.h"
#include "cRotateBy.h"
#include "cActionSpawn.h"
#include "cAnimation.h"
#include "cTextureManager.h"
#include "cMessgeCenter.h"
#include "cUIObject.h"
#include "cUIImageView.h"
#include "cUITextView.h"
#include "cUIButton.h"
#include "cPlayState.h"

cMainGame::cMainGame(void)
: m_pSprite(NULL)
, m_pGameState(NULL)
, m_dwPrevTime(0)
{
}

cMainGame::~cMainGame(void)
{
	
}

void cMainGame::Setup()
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);
	m_pGameState = new cPlayState;
	m_pGameState->Setup(m_pSprite);
	m_pGameState->SetDelegate(this);
	m_dwPrevTime = GetTickCount();
}

void cMainGame::Update()
{
	DWORD dwCurrentTime = GetTickCount();
	float fDeltaTime = (dwCurrentTime - m_dwPrevTime) / 1000.f;

	m_pGameState->Update(fDeltaTime);

	m_dwPrevTime = dwCurrentTime;
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(
		0,
		0,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0,0,0),
		1.0f,
		0);
	g_pD3DDevice->BeginScene();
	
	m_pGameState->Render();

	g_pD3DDevice->EndScene();
	g_pD3DDevice->Present(0,0,0,0);
}

bool cMainGame::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	if(m_pGameState)
		m_pGameState->MsgProc(hWnd, message, wParam, lParam);
	switch (message)
	{
	case WM_KEYDOWN:
		{
			switch(wParam)
			{
			case VK_SPACE:
				{
				}
				break;
			}
		}
		return true;
	case WM_LBUTTONDOWN:
		{
			
		}
		return true;
	case WM_RBUTTONDOWN:
		{
			
		}
		return true;
	}
	return false;
}

void cMainGame::Destroy()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pGameState);
	g_TextureManager.Destroy();
}

void cMainGame::OnChangeState( iGameState* pGameState )
{
	if(m_pGameState != pGameState)
	{
		m_pGameState->AutoRelease();
		m_pGameState = pGameState;
	}
	
	m_pGameState->Setup(m_pSprite);
}