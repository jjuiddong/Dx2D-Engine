#pragma once

class cObject
{
	friend class cObjectManager;

protected:
	int					m_nRefCount;
	unsigned long long	m_ullID;

public:
	cObject(void);
	virtual ~cObject(void);

	void AddRef();

	void Release();

	void AutoRelease();
	
	virtual std::string Description() = 0;

	virtual void OnRecieveMessage(std::string& sKey, cObject* pSender) {}
};


// cObjectManager
class cObjectManager
{
private:
	unsigned long long	m_ullID;
	std::set<cObject*>	m_setObjects;

	cObjectManager(){}
	~cObjectManager(){}

public:
	static cObjectManager& GetInstance()
	{
		static cObjectManager instance;
		return instance;
	}

	void Issue(cObject* pReqObject)
	{
		pReqObject->m_ullID = ++m_ullID;
		m_setObjects.insert(pReqObject);
	}

	void DeleteObject(cObject* pReqObject)
	{
		m_setObjects.erase(pReqObject);
	}

	void Destroy()
	{
		std::string sMsg("");
		std::set<cObject*>::iterator it;

		for (it = m_setObjects.begin(); it != m_setObjects.end(); ++it)
		{
			sMsg += (*it)->Description();
		}

		if(m_setObjects.empty() == false)
		{
			OutputDebugString(sMsg.c_str());
			assert(m_setObjects.empty() && "자세한 내용은 출력창을 참고!!!");
		}
	}
};