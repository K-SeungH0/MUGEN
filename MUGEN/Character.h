#pragma once
#include "config.h"

class Image;
class Character
{
private:
	enum class Direction
	{
		LEFT,
		RIGHT
	};
	enum class CharacterState
	{
		IDLE,
		MOVE,
		ATTACK,
		HIT,

	};
	struct CharacterAttackInfo
	{
		int left;
		int top;
		int right;
		int bottom;
		int damage;
	};
	

	Direction dir;
	CharacterAttackInfo charAtkInfo;
	POINTFLOAT pos;
	int hp;
	string pathName;
	
	struct RendInfo
	{
		Image* lpimage;
		RECT hitRc;
		map<int, CharacterAttackInfo> mAtkRc;
		POINTFLOAT offsetPos;
	};
};

