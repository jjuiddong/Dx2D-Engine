#pragma once

class iGameStateDelegate;

class iGameState : public cObject
{
public:
	virtual void SetDelegate(iGameStateDelegate* pDelegate) = 0;
	virtual void Setup(LPD3DXSPRITE pSprite) = 0;
	virtual void Update(float fDeltaTime) = 0;
	virtual void Render() = 0;
	virtual bool MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
};

class iGameStateDelegate
{
public:
	virtual void OnChangeState(iGameState* pGameState) = 0;
};