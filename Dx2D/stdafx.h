// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C의 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <d3d9.h>
//#pragma comment(lib, "d3d9.lib") 
//#pragma comment(lib, "d3dx9d.lib") 

extern HWND g_hWnd;

#include <vector>
#include <iostream>
#include <map>
#include <list>
#include <set>
#include <string>
#include <d3dx9.h>
#include <assert.h>

#include <MMSystem.h>

#include "cLog.h"


#define WINSIZEX 1024
#define WINSIZEY 768


#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif
#ifndef SAFE_ADDREF
#define SAFE_ADDREF(p)       { if(p) { (p)->AddRef(); } }
#endif

#define SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType Get##funName(void) const { return varName; }\
public: virtual void Set##funName(varType var){ varName = var; }

#define SYNTHESIZE_PASS_BY_REF(varType, varName, funName)\
protected: varType varName;\
public: virtual const varType& Get##funName(void) const { return varName; }\
public: virtual void Set##funName(const varType& var){ varName = var; }

#define SYNTHESIZE_ADDREF(varType, varName, funName)    \
protected: varType varName; \
public: virtual varType Get##funName(void) const { return varName; } \
public: virtual void Set##funName(varType var)   \
{ \
	if (varName != var) \
{ \
	SAFE_ADDREF(var); \
	SAFE_RELEASE(varName); \
	varName = var; \
} \
} 



struct ST_SIZE
{
	float fWidth;
	float fHeight;
	ST_SIZE(float _fWidth, float _fHeight) : fWidth(_fWidth), fHeight(_fHeight) {}
	ST_SIZE() : fWidth(0.0f), fHeight(0.0f) {}
};

const std::string kMapFar = "map_far.bmp";
const std::string kMapNear = "map_near.png";
const std::string kPlayer = "player.png";
const std::string kHPBar = "cur.png";
const std::string kBlue = "blue.bmp";
const std::string kGreen = "green.png";
const std::string kTank = "tank.bmp";

#include "cObject.h"

float Length(POINT p1, POINT p2);
float SqLength(POINT p1, POINT p2);