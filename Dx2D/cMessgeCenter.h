#pragma once

#define g_MessgeCenter cMessgeCenter::GetInstance()

class cObject;

class cMessgeCenter
{
private:
	cMessgeCenter(void);
	~cMessgeCenter(void);

	std::map<std::string, std::list<cObject*>> m_mapObserver;

public:
	static cMessgeCenter& GetInstance()
	{
		static cMessgeCenter instance;
		return instance;
	}

	void AddObserver(std::string& sKey, cObject* pObject)
	{
		m_mapObserver[sKey].push_back(pObject);
	}

	void RemoveObserver(std::string& sKey, cObject* pObject)
	{
		m_mapObserver[sKey].remove(pObject);
	}

	void PostMessage(std::string& sKey, cObject* pSender);
};

