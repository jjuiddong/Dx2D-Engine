#include "StdAfx.h"
#include "cPlayState.h"
#include "cDeviceManager.h"
#include "cSprite.h"
#include "cMoveBy.h"
#include "cMoveTo.h"
#include "cRotateBy.h"
#include "cActionSpawn.h"
#include "cAnimation.h"
#include "cTextureManager.h"
#include "cParticleSystem.h"

cPlayState::cPlayState(void)
: m_pRoot(NULL)
{
}

cPlayState::~cPlayState(void)
{
	SAFE_RELEASE(m_pRoot);
}

void cPlayState::SetDelegate( iGameStateDelegate* pDelegate )
{

}

void cPlayState::Setup( LPD3DXSPRITE pSprite )
{
	m_pRoot = new cSprite(pSprite);
	cTexture* pTexture = g_TextureManager.GetTexture(kGreen, D3DCOLOR_XRGB(255, 0, 255));
	m_pRoot->SetTexture(pTexture);
	m_pRoot->SetRectangle(pTexture->GetImageRect());
	m_pRoot->SetAnchorPoint(D3DXVECTOR2(0,0));
	m_pRoot->SetSize(ST_SIZE(WINSIZEX, WINSIZEY));

	cSprite* pTank = new cSprite(pSprite);
	pTexture = g_TextureManager.GetTexture(kTank, D3DCOLOR_XRGB(255, 0, 255));
	pTank->SetTexture(pTexture);
	pTank->SetPosition(D3DXVECTOR3(200, 200, 0));
	pTank->SetRectangle(pTexture->GetImageRect());
	pTank->SetAnchorPoint(D3DXVECTOR2(0.5,0.5));
	pTank->SetSize(ST_SIZE(59, 45));
	m_pRoot->AddChild(pTank);
	pTank->Release();

	cParticleSystem* pParticleSystem = new cParticleSystem(pSprite);
	pParticleSystem->Setup(500);
	m_pRoot->AddChild(pParticleSystem);
	pParticleSystem->Release();
}

void cPlayState::Update(float fDeltaTime)
{
	m_pRoot->Update(fDeltaTime);
}

void cPlayState::Render()
{
	m_pRoot->Render();
}

bool cPlayState::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	return false;
}