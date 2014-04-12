#include "StdAfx.h"
#include "cMessgeCenter.h"
#include "cObject.h"

cMessgeCenter::cMessgeCenter(void)
{
}

cMessgeCenter::~cMessgeCenter(void)
{
}

void cMessgeCenter::PostMessage( std::string& sKey, cObject* pSender )
{
	if(m_mapObserver.find(sKey) == m_mapObserver.end())
		return;

	std::list<cObject*>::iterator it;
	for (it = m_mapObserver[sKey].begin();
		it != m_mapObserver[sKey].end();
		++it)
	{
		(*it)->OnRecieveMessage(sKey, pSender);
	}
}