#pragma once
#include "cUIButton.h"
#include "iGameState.h"

class cMainGame : public iGameStateDelegate
{
private:
	LPD3DXSPRITE			m_pSprite;
	DWORD					m_dwPrevTime;
	
	SYNTHESIZE_ADDREF(iGameState*, m_pGameState, GameState);
	
public:	
	cMainGame(void);
	~cMainGame(void);

	void Setup();
	void Update();
	void Render();
	void Destroy();
	bool WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	// iGameStateDelegate 
	virtual void OnChangeState(iGameState* pGameState) override;
	
};



