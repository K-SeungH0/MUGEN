#pragma once

#define WINSIZE_WIDTH 1200
#define WINSIZE_HEIGHT 600
#define PI 3.1415926f
#define MAX_HP 100

#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <functional>

#include "KeyManager.h"
#include "ColliderManager.h"
#include "ImageManager.h"
#include "EffectManager.h"

extern bool isDebugMode;
extern HINSTANCE g_hInstance;
extern HWND g_hWnd;

extern bool isDebugMode;

using namespace std;

enum class PLAYER_TYPE
{
	P1,
	P2,
	NONE
};

inline bool CollisionRect(RECT self, RECT other)
{
	if (other.right < self.left || other.bottom < self.top
		|| other.left > self.right || other.top > self.bottom)
	{
		return false;
	}

	return true;
}

inline RECT GetRectOffset(POINTFLOAT pos, POINTFLOAT offset, int width, int height)
{
	RECT rect = { (int)(pos.x + offset.x), (int)(pos.y + offset.y), (int)(pos.x + offset.x + width), (int)(pos.y + offset.y + height) };
	return rect;
}