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
#include "GameData.h"
#include "SceneManager.h"
#include "FileManager.h"

extern bool isDebugMode;
extern HINSTANCE g_hInstance;
extern HWND g_hWnd;

extern bool isDebugMode;

using namespace std;

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

inline bool CollisionRectInPoint(RECT self, POINT other)
{
	if (other.x < self.left || self.right < other.x
		|| other.y < self.top || self.bottom < other.y)
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

inline string GetKey(string name, CHARACTER_DIRECTION dir = CHARACTER_DIRECTION::NONE, CHARACTER_STATE state = CHARACTER_STATE::NONE, string col = "")
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

	return (key.length() > 0 && key[0] == '_')?key.substr(1):key;
}