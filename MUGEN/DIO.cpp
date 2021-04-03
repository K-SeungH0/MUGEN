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
	dir = DIRECTION::RIGHT;
	// 캐릭터 상태
	state = CHARACTER_STATE::MOVE;
	// 캐릭터 체력
	hp = 100;
	// 캐릭터 위치
	pos = { 100, WINSIZE_HEIGHT - 100 };
	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	name = "DIO";
	// Init 모션별 초기화
	// IDLE
	motions[(int)CHARACTER_STATE::IDLE].offsetDrawPos = { -33, -120 };
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_IDLE", 0);
	motions[(int)CHARACTER_STATE::IDLE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_IDLE", 0);
	motions[(int)CHARACTER_STATE::IDLE].offsetHitPos = { -25, -120 };
	motions[(int)CHARACTER_STATE::IDLE].width = 50;
	motions[(int)CHARACTER_STATE::IDLE].height = 120;
	motions[(int)CHARACTER_STATE::IDLE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::IDLE].offsetHitPos, 50, 120);

	// MOVE
	motions[(int)CHARACTER_STATE::MOVE].offsetDrawPos = { -40, -115 };
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_MOVE", 0);
	motions[(int)CHARACTER_STATE::MOVE].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_MOVE", 0);
	motions[(int)CHARACTER_STATE::MOVE].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::MOVE].width = 50;
	motions[(int)CHARACTER_STATE::MOVE].height = 115;
	motions[(int)CHARACTER_STATE::MOVE].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE].offsetHitPos, 50, 115);
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetDrawPos = { -40, -115 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_MOVE", 0);
	motions[(int)CHARACTER_STATE::MOVE_GUARD].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_MOVE", 0);
	motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::MOVE_GUARD].width = 50;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].height = 115;
	motions[(int)CHARACTER_STATE::MOVE_GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::MOVE_GUARD].offsetHitPos, 50, 115);

	// HIT
	motions[(int)CHARACTER_STATE::HIT].offsetDrawPos = { -47, -128 };
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_HIT2", 0);
	motions[(int)CHARACTER_STATE::HIT].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_HIT2", 0);
	motions[(int)CHARACTER_STATE::HIT].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::HIT].width = 100;
	motions[(int)CHARACTER_STATE::HIT].height = 115;
	motions[(int)CHARACTER_STATE::HIT].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::HIT].offsetHitPos, 100, 115);

	// ATTACK_WEAK
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetDrawPos = { -30, -110 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_ATTACK_WEAK", 0);
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_ATTACK_WEAK", 0);
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].offsetHitPos = { -33, -110 };
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].height = 110;
	motions[(int)CHARACTER_STATE::ATTACK_WEAK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 66, 110);

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {75,-92}, 90, 50, 5 }));

	// ATTACK_STRONG
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetDrawPos = { -36, -117 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_ATTACK_STRONG", 0);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_ATTACK_STRONG", 0);
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos = { -33, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].height = 112;
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_STRONG].offsetHitPos, 66, 112);
	
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {107,-75}, 80, 50, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {92,-33}, 50, 80, 10 }));

	// ATTACK_KICK
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetDrawPos = { -95, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_ATTACK_KICK", 0);
	motions[(int)CHARACTER_STATE::ATTACK_KICK].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_ATTACK_KICK", 0);
	motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos = { -33, -112 };
	motions[(int)CHARACTER_STATE::ATTACK_KICK].width = 66;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].height = 112;
	motions[(int)CHARACTER_STATE::ATTACK_KICK].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::ATTACK_KICK].offsetHitPos, 66, 112);

	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {71,-91}, 50, 50, 10 }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {71,-91}, 50, 50, 10 }));

	// 가드
	motions[(int)CHARACTER_STATE::GUARD].offsetDrawPos = { -36, -117 };
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_GUARD", 0);
	motions[(int)CHARACTER_STATE::GUARD].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_GUARD", 0);
	motions[(int)CHARACTER_STATE::GUARD].offsetHitPos = { -25, -115 };
	motions[(int)CHARACTER_STATE::GUARD].width = 50;
	motions[(int)CHARACTER_STATE::GUARD].height = 115;
	motions[(int)CHARACTER_STATE::GUARD].hitRc = GetRectOffset(pos, motions[(int)CHARACTER_STATE::GUARD].offsetHitPos, 50, 115);

	// 죽음
	motions[(int)CHARACTER_STATE::DEATH].offsetDrawPos = { -80, -108 };
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)DIRECTION::RIGHT] = ImageManager::GetLpInstance()->Play("DIO_RIGHT_DEATH", 0);
	motions[(int)CHARACTER_STATE::DEATH].lpImages[(int)DIRECTION::LEFT] = ImageManager::GetLpInstance()->Play("DIO_LEFT_DEATH", 0);
	motions[(int)CHARACTER_STATE::DEATH].offsetHitPos = { -80, -112 };
	motions[(int)CHARACTER_STATE::DEATH].width = 152;
	motions[(int)CHARACTER_STATE::DEATH].height = 108;
	motions[(int)CHARACTER_STATE::DEATH].hitRc = {0, 0, 0, 0};

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;
}