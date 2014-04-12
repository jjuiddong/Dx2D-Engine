#pragma once

class cTexture : public cObject
{
	friend class cSprite;

protected:
	D3DXIMAGE_INFO			m_stImageInfo;

	SYNTHESIZE(LPDIRECT3DTEXTURE9, m_pTexture, Texture);
	
	void LoadTexture(const char* szFileName, D3DCOLOR dwColorKey = 0);
	
public:
	cTexture(char* szFileName, D3DCOLOR dwColorKey = 0);
	cTexture(std::string sFileName, D3DCOLOR dwColorKey = 0);
	virtual ~cTexture(void);
	
	RECT GetImageRect()
	{
		RECT rc;
		SetRect(&rc, 0, 0, m_stImageInfo.Width, m_stImageInfo.Height);
		return rc;
	}

	virtual std::string Description() override
	{
		return "";
	}

	D3DCOLOR GetColor(POINT pt);
	void SetColor(D3DCOLOR c);
	void MirroredImage();
	void SetColorCircle(D3DCOLOR c, POINT ptCenter, float fRadius);
	void GetHeightAndAngle(
		IN int nTopBound,
		IN int nX,
		OUT int& nHeight,
		OUT float& fAngle);
};
