#include "Mugen.h"
#include "King.h"
#include "Image.h"
#include <fstream>

King::King()
{
}

King::~King()
{
}

void King::Init()
{
	// 바라보는 방향
	dir = CHARACTER_DIRECTION::RIGHT;
	// 캐릭터 상태
	state = CHARACTER_STATE::IDLE;
	// 캐릭터 체력
	hp = 100;
	// 캐릭터 위치
	pos = { 0, 0 };
	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	name = "KING";
	elapsedTime = 0;
	frame = 0;
	moveSpeed = 5;

	LoadData();

	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}