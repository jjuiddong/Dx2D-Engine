// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// Dx2D.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"

// TODO: �ʿ��� �߰� �����
// �� ������ �ƴ� STDAFX.H���� �����մϴ�.

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