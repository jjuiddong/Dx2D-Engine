#include "StdAfx.h"
#include "cObject.h"
#include "cAutoReleasePool.h"



// cObject
cObject::cObject(void)
: m_nRefCount(1)
{

	cObjectManager::GetInstance().Issue(this);
}

cObject::~cObject(void)
{
	cObjectManager::GetInstance().DeleteObject(this);
}

void cObject::AddRef()
{
	assert(m_nRefCount != 0);
	++m_nRefCount;
}

void cObject::Release()
{
	assert(m_nRefCount > 0);

	--m_nRefCount;
	if(m_nRefCount == 0)
	{
		delete this;
	}
}

void cObject::AutoRelease()
{
	cAutoReleasePool::GetInstance().AddObject(this);
}