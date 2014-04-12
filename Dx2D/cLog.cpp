#include "StdAfx.h"
#include "cLog.h"

cLog::cLog(void)
{
}

cLog::~cLog(void)
{
}

void cLog::Output( D3DXMATRIXA16& mat )
{
	char szBuf[1024];
	sprintf_s(szBuf, "%.2f %.2f %.2f %.2f\n%.2f %.2f %.2f %.2f\n%.2f %.2f %.2f %.2f\n%.2f %.2f %.2f %.2f\n"
		, mat._11, mat._12, mat._13, mat._14
		, mat._21, mat._22, mat._23, mat._24
		, mat._31, mat._32, mat._33, mat._34
		, mat._41, mat._42, mat._43, mat._44);
	OutputDebugString(szBuf);
}