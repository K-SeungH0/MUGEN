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
enum class CHARACTER_DIRECTION
{
	RIGHT,
	LEFT,
	NONE
};
enum class CHARACTER_STATE
{
	IDLE,
	MOVE,
	MOVE_GUARD,
	GUARD,
	ATTACK_WEAK,
	ATTACK_STRONG,
	ATTACK_KICK,
	ATTACK_RANGE,
	HIT,
	DEATH,
	NONE
};
enum class SCENE_STATE
{
	TITLE,
	SELECTION,
	BATTLE,
	END,
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


inline string GetKey(string name, CHARACTER_DIRECTION dir, CHARACTER_STATE state, string col = "")
{
	string key = "";
	key += name;

	switch (dir)
	{
	case CHARACTER_DIRECTION::RIGHT:
		key += "_RIGHT";
		break;
	case CHARACTER_DIRECTION::LEFT:
		key += "_LEFT";
		break;
	case CHARACTER_DIRECTION::NONE:
		break;
	}

	switch (state)
	{
	case CHARACTER_STATE::IDLE:
		key += "_IDLE";
		break;
	case CHARACTER_STATE::MOVE:
		key += "_MOVE";
		break;
	case CHARACTER_STATE::MOVE_GUARD:
		key += "_MOVE_GUARD";
		break;
	case CHARACTER_STATE::GUARD:
		key += "_GUARD";
		break;
	case CHARACTER_STATE::ATTACK_WEAK:
		key += "_ATTACK_WEAK";
		break;
	case CHARACTER_STATE::ATTACK_STRONG:
		key += "_ATTACK_STRONG";
		break;
	case CHARACTER_STATE::ATTACK_KICK:
		key += "_ATTACK_KICK";
		break;
	case CHARACTER_STATE::ATTACK_RANGE:
		key += "_ATTACK_RANGE";
		break;
	case CHARACTER_STATE::HIT:
		key += "_HIT";
		break;
	case CHARACTER_STATE::DEATH:
		key += "_DEATH";
		break;
	case CHARACTER_STATE::NONE:
		break;
	}

	if (!col.empty())
		key += "_" + col;

	return key;
}