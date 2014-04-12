#pragma once

class cObject;

class cAutoReleasePool
{
private:
	std::list<cObject*> m_lstObjects;

	cAutoReleasePool(void);
	~cAutoReleasePool(void);

public:
	static cAutoReleasePool& GetInstance()
	{
		static cAutoReleasePool insatance;
		return insatance;
	}
	void AddObject(cObject* pObject);
	void Drain();
};
