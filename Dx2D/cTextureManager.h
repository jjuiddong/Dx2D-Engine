#pragma once

#define g_TextureManager cTextureManager::GetInstance()

class cTexture;

class cTextureManager
{
private:
	cTextureManager(void);
	~cTextureManager(void);

	std::map<std::string, cTexture*> m_mapTexture;

public:
	static cTextureManager& GetInstance()
	{
		static cTextureManager instance;
		return instance;
	}

	cTexture* GetTexture(std::string sFileName, DWORD dwColorKey = 0);
	void Destroy();
};
