#pragma once

#include <Windows.h>
#include <math.h>
#include <map>
#include <vector>
#include <string>

using namespace std;

#include "KeyManager.h"
#include "ImageManager.h"
#include "TimeManager.h"
#include "SoundManager.h"

// enum, struct, .h, #define
enum BOX
{
	BOX_First,
	BOX_Second,
	BOX_End
};

typedef struct tagFPOINT
{
	float x;
	float y;
} FPOINT, *PFPOINT;


#define FPS			30.0f
#define WINSIZE_X	600
#define WINSIZE_Y	800
#define WINSTART_X	50
#define WINSTART_Y	50

#define PI			3.141592

#define SAFE_DELETE(p)		{ if (p) { delete p; p = NULL; }}
#define SAFE_ARR_DELETE(p)	{ if (p) { delete [] p; p = NULL; }}

#define DEGREE_TO_RADIAN(x)	( x * PI / 180 )
#define RADIAN_TO_DEGREE(x) (int)( x * 180 / PI )

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;