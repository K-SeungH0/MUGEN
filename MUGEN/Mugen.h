#pragma once

#define WINSIZE_WIDTH 800
#define WINSIZE_HEIGHT 600

#include <Windows.h>
#include <string>
#include <map>
#include <vector>

#include "KeyManager.h"

extern HINSTANCE g_hInstance;
extern HWND g_hWnd;

extern bool isDebugMode;

using namespace std;

inline RECT GetRectOffset(POINTFLOAT pos, POINTFLOAT offset, int width, int height)
{
	RECT rect = { pos.x + offset.x, pos.y + offset.y,pos.x + offset.x + width, pos.y + offset.y + height };
	return rect;
}
