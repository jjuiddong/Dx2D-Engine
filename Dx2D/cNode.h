#pragma once
#include "cAction.h"

class cNode : public cObject
{
protected:
	std::list<cNode*>	m_lstChild;
	D3DXMATRIXA16		m_mTransform;
	D3DXVECTOR3			m_vCenter;
	D3DXVECTOR2			m_vAnchorPoint;
	SYNTHESIZE(int, m_nTag, Tag);
	SYNTHESIZE_PASS_BY_REF(RECT, m_rc, Rectangle);
	SYNTHESIZE_ADDREF(cAction*, m_pAction, Action);
	SYNTHESIZE(bool, m_isHidden, Hidden);
	SYNTHESIZE(float, m_fAngle, Angle);
	SYNTHESIZE(cNode*, m_pParent, Parent);
	SYNTHESIZE_PASS_BY_REF(D3DXVECTOR3, m_vPosition, Position);
	SYNTHESIZE_PASS_BY_REF(D3DXVECTOR3, m_vScale, Scale);
	SYNTHESIZE_PASS_BY_REF(ST_SIZE, m_stSize, Size);
	
public:
	cNode(void);
	virtual ~cNode(void);

	virtual void Update(float fDeltaTime);

	virtual void AddChild(cNode* pChild)
	{
		SAFE_ADDREF(pChild);
		m_lstChild.push_back(pChild);
		pChild->m_pParent = this;
	}
	
	virtual void RemoveChild(cNode* pChild)
	{
		m_lstChild.remove(pChild);
		SAFE_RELEASE(pChild);
	}

	virtual void Render()
	{
		std::list<cNode*>::iterator it;
		for (it = m_lstChild.begin(); it != m_lstChild.end(); ++it)
		{
			(*it)->Render();
		}
	}

	virtual cNode* GetChildByTag(int nTag)
	{
		if(m_nTag == nTag)
			return this;

		std::list<cNode*>::iterator it;
		for (it = m_lstChild.begin(); it != m_lstChild.end(); ++it)
		{
			cNode* pNode = (*it)->GetChildByTag(nTag);
			if(pNode)
				return pNode;
		}
		return NULL;
	}
};


