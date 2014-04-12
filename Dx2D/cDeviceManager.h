#pragma once

#define g_pD3DDevice cDeviceManager::GetInstance()->GetDevice()

class cDeviceManager
{
private:
	LPDIRECT3D9				m_pD3D;
	LPDIRECT3DDEVICE9		m_pD3DDevice;

	cDeviceManager(void);
	~cDeviceManager(void);

public:
	static cDeviceManager* GetInstance()
	{
		static cDeviceManager instance;
		return &instance;
	}

	LPDIRECT3DDEVICE9 GetDevice()
	{
		return m_pD3DDevice;
	}
};
