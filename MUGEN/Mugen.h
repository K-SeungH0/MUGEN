#pragma once

#define WINSIZE_WIDTH 800
#define WINSIZE_HEIGHT 600
#define PI 3.1415926f

#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <functional>

#include "KeyManager.h"
#include "ColliderManager.h"
#include "ImageManager.h"

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
	if ((self.left < other.left && other.left < self.right && self.top < other.top && other.top < self.bottom)
		|| (self.left < other.left && other.left < self.right && self.top < other.bottom && other.bottom < self.bottom)
		|| (self.left < other.right && other.right < self.right && self.top < other.top && other.top < self.bottom)
		|| (self.left < other.right && other.right < self.right && self.top < other.bottom && other.bottom < self.bottom))
	{
		return true;
	}

	if ((self.left < other.left && other.right < self.right && self.top > other.top && other.bottom > self.bottom)
		|| (other.left < self.left && self.right < other.right && other.top > self.top && self.bottom > other.bottom))
	{
		return true;
	}

	return false;
}

inline RECT GetRectOffset(POINTFLOAT pos, POINTFLOAT offset, int width, int height)
{
	RECT rect = { (int)(pos.x + offset.x), (int)(pos.y + offset.y), (int)(pos.x + offset.x + width), (int)(pos.y + offset.y + height) };
	return rect;
}