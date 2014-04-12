// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// Dx2D.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.

float Length( POINT p1, POINT p2 )
{
	return sqrt(SqLength(p1,p2));
}

float SqLength( POINT p1, POINT p2 )
{
	float fDeltaX = (float)(p2.x - p1.x);
	float fDeltaY = (float)(p2.y - p1.y);
	return fDeltaX * fDeltaX + fDeltaY * fDeltaY;
}