#include "StdAfx.h"
#include "cTextureManager.h"
#include "cTexture.h"

cTextureManager::cTextureManager(void)
{
}

cTextureManager::~cTextureManager(void)
{
}

cTexture* cTextureManager::GetTexture( std::string sFileName, DWORD dwColorKey )
{
	if(m_mapTexture.find(sFileName) == m_mapTexture.end())
	{
		m_mapTexture[sFileName] = new cTexture(sFileName, dwColorKey);
	}

	return m_mapTexture[sFileName];
}

void cTextureManager::Destroy()
{
	std::map<std::string, cTexture*>::iterator it;
	for (it = m_mapTexture.begin(); it != m_mapTexture.end(); ++it)
	{
		SAFE_RELEASE(it->second);
	}
	m_mapTexture.clear();
}