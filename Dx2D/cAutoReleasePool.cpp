#include "StdAfx.h"
#include "cAutoReleasePool.h"
#include "cObject.h"

cAutoReleasePool::cAutoReleasePool(void)
{
}

cAutoReleasePool::~cAutoReleasePool(void)
{
}

void cAutoReleasePool::AddObject( cObject* pObject )
{
	m_lstObjects.push_back(pObject);
}

void cAutoReleasePool::Drain()
{
	std::list<cObject*>::iterator it;
	for (it = m_lstObjects.begin(); it != m_lstObjects.end(); ++it)
	{
		(*it)->Release();
	}
	m_lstObjects.clear();
}