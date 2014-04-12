#include "StdAfx.h"
#include "cNode.h"

cNode::cNode(void)
: m_pParent(NULL)
, m_pAction(NULL)
, m_vCenter(0.0f, 0.0f, 0.0f)
, m_vAnchorPoint(0.5f, 0.5f)
, m_nTag(0)
, m_isHidden(false)
, m_fAngle(0.0f)
, m_vPosition(0.0f, 0.0f, 0.0f)
, m_vScale(1.0f, 1.0f, 1.0f)
, m_stSize(0.0f, 0.0f)
{
}

cNode::~cNode(void)
{
	std::list<cNode*>::iterator it;
	for (it = m_lstChild.begin(); it != m_lstChild.end(); ++it)
	{
		SAFE_RELEASE((*it));
	}
	m_lstChild.clear();

	SAFE_RELEASE(m_pAction);
}

void cNode::Update( float fDeltaTime )
{
	if(m_pAction)
		m_pAction->Update(fDeltaTime, this);

	D3DXMATRIXA16 mS, mR, mT;
	D3DXMatrixScaling(&mS, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixRotationZ(&mR, m_fAngle);
	D3DXMatrixTranslation(&mT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_mTransform = mS * mR * mT;
	if(m_pParent)
		m_mTransform = m_mTransform * m_pParent->m_mTransform;
	
	std::list<cNode*>::iterator it;
	for (it = m_lstChild.begin(); it != m_lstChild.end(); ++it)
	{
		(*it)->Update(fDeltaTime);
	}
}