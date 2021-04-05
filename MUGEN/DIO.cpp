#include "Mugen.h"
#include "DIO.h"
#include "Image.h"

DIO::DIO()
{
}

DIO::~DIO()
{
}

void DIO::Init()
{
	// 바라보는 방향
	dir = CHARACTER_DIRECTION::RIGHT;
	// 캐릭터 상태
	state = CHARACTER_STATE::IDLE;
	// 캐릭터 체력
	hp = 100;
	// 캐릭터 위치
	pos = { 100, WINSIZE_HEIGHT - 100 };
	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	name = "DIO";
	// Init 모션별 초기화
	// IDLE
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -33, -120 };
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -33, -120 };
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -25, -120 };
	motions[(int)CHARACTER_STATE::IDLE].width = 50;
	motions[(int)CHARACTER_STATE::IDLE].height = 120;
	
	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -40, -115 };
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -40, -115 };
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::MOVE].width = 50;
	motions[(int)CHARACTER_STATE::MOVE].height = 115;
	motions[(int)CHARACTER_STATE::MOVE].motionSpeed = 6;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -40, -115 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -40, -115 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 50;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 115;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].motionSpeed = 6;

	// HIT
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -47, -128 };
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -47, -128 };
	motions[(int)CHARACTER_STATE::HIT].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::HIT].width = 50;
	motions[(int)CHARACTER_STATE::HIT].height = 115;

	// ATTACK_WEAK
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -30, -110 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -85, -110 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -33, -110 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 110;

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {75,-92}, 90, 50, 5, "", ""}));

	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -36, -117 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -132, -117 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -33, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 112;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].motionSpeed = 5;
	
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {107,-75}, 80, 50, 10, "", "" }));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {92,-33}, 50, 80, 10, "", "" }));

	// ATTACK_KICK
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -95, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -88, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos = { -33, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].height = 112;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].motionSpeed = 5;

	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {71,-91}, 50, 50, 10, "", "" }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {71,-91}, 50, 50, 10, "", "" }));

	// ATTACK_RANGE
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -27, -146 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -121, -146 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].offsetHitPos = { -33, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].height = 112;
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].motionSpeed = 7;

	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::RANGE, {110,-68}, 60, 30, 10, {"DIO_RIGHT_ATTACK_RANGE_COLLIDER", "DIO_LEFT_ATTACK_RANGE_COLLIDER"}, "" }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::RANGE, {100,-50}, 60, 30, 10, {"DIO_RIGHT_ATTACK_RANGE_COLLIDER", "DIO_LEFT_ATTACK_RANGE_COLLIDER"}, "" }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(5, AttackInfo{ ATTACK_TYPE::RANGE, {90,-62}, 60, 30, 10, {"DIO_RIGHT_ATTACK_RANGE_COLLIDER", "DIO_LEFT_ATTACK_RANGE_COLLIDER"}, "" }));

	// 가드
	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -36, -117 };
	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -36, -117 };
	motions[(int)CHARACTER_STATE::GUARD].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::GUARD].width = 50;
	motions[(int)CHARACTER_STATE::GUARD].height = 115;

	// 죽음
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)CHARACTER_DIRECTION::RIGHT] = { -80, -108 };
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos[(int)CHARACTER_DIRECTION::LEFT] = { -66, -108 };
	motions[(int)CHARACTER_STATE::DEATH].offsetHitPos = { -80, -112 };
	motions[(int)CHARACTER_STATE::DEATH].width = 152;
	motions[(int)CHARACTER_STATE::DEATH].height = 108;

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;

	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}