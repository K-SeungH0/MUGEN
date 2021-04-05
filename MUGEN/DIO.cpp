#include "Mugen.h"
#include "DIO.h"
#include "Image.h"
#include <fstream>

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

	// INI파일 로드
	if (FileManager::GetLpInstance()->ReadFile("INI/" + name + ".ini"))
	{
		int state;
		string group;
		vector<float> vFloats;
		for (int i = 0; i < (int)CHARACTER_STATE::NONE; ++i)
		{
			switch ((CHARACTER_STATE)i)
			{
			case CHARACTER_STATE::IDLE:
				group = "IDLE";
				break;
			case CHARACTER_STATE::MOVE:
				group = "MOVE";
				break;
			case CHARACTER_STATE::MOVE_GUARD:
				group = "MOVE_GUARD";
				break;
			case CHARACTER_STATE::GUARD:
				group = "GUARD";
				break;
			case CHARACTER_STATE::ATTACK_WEAK:
				group = "ATTACK_WEAK";
				break;
			case CHARACTER_STATE::ATTACK_STRONG:
				group = "ATTACK_STRONG";
				break;
			case CHARACTER_STATE::ATTACK_KICK:
				group = "ATTACK_KICK";
				break;
			case CHARACTER_STATE::ATTACK_RANGE:
				group = "ATTACK_RANGE";
				break;
			case CHARACTER_STATE::HIT:
				group = "HIT";
				break;
			case CHARACTER_STATE::DEATH:
				group = "DEATH";
				break;
			}

			state = FileManager::GetLpInstance()->GetData<int>(group, "characterState");
			vFloats = FileManager::GetLpInstance()->GetData<vector<float>>(group, "offsetDrawPos");
			for (int k = 0; k < vFloats.size(); ++k)
			{
				if (k % 2 == 0) motions[state].offsetDrawPos[k / 2].x = vFloats[k];
				else motions[state].offsetDrawPos[k / 2].y = vFloats[k];
			}
			vFloats = FileManager::GetLpInstance()->GetData<vector<float>>(group, "offsetHitPos");
			for (int k = 0; k < vFloats.size(); ++k)
			{
				if (k % 2 == 0) motions[state].offsetHitPos.x = vFloats[k];
				else motions[state].offsetHitPos.y = vFloats[k];
			}
			motions[state].width = FileManager::GetLpInstance()->GetData<int>(group, "width");
			motions[state].height = FileManager::GetLpInstance()->GetData<int>(group, "height");
			motions[state].motionSpeed = FileManager::GetLpInstance()->GetData<int>(group, "motionSpeed");
		}
	}
	else
	{
		MessageBox(g_hWnd, "INI파일을 읽지 못하였습니다.", "Error", MB_OK);
	}

	motions[(int)CHARACTER_STATE::ATTACK_WEAK].mAtkInfo.insert(make_pair(1, AttackInfo{ ATTACK_TYPE::MELEE, {75,-92}, 90, 50, 5, "", ""}));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(2, AttackInfo{ ATTACK_TYPE::MELEE, {107,-75}, 80, 50, 10, "", "" }));
	motions[(int)CHARACTER_STATE::ATTACK_STRONG].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {92,-33}, 50, 80, 10, "", "" }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::MELEE, {71,-91}, 50, 50, 10, "", "" }));
	motions[(int)CHARACTER_STATE::ATTACK_KICK].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::MELEE, {71,-91}, 50, 50, 10, "", "" }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(3, AttackInfo{ ATTACK_TYPE::RANGE, {110,-68}, 60, 30, 10, {"DIO_RIGHT_ATTACK_RANGE_COLLIDER", "DIO_LEFT_ATTACK_RANGE_COLLIDER"}, "" }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(4, AttackInfo{ ATTACK_TYPE::RANGE, {100,-50}, 60, 30, 10, {"DIO_RIGHT_ATTACK_RANGE_COLLIDER", "DIO_LEFT_ATTACK_RANGE_COLLIDER"}, "" }));
	motions[(int)CHARACTER_STATE::ATTACK_RANGE].mAtkInfo.insert(make_pair(5, AttackInfo{ ATTACK_TYPE::RANGE, {90,-62}, 60, 30, 10, {"DIO_RIGHT_ATTACK_RANGE_COLLIDER", "DIO_LEFT_ATTACK_RANGE_COLLIDER"}, "" }));

	elapsedTime = 0;
	frame = 0;

	moveSpeed = 5;

	lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state));
	hitRc = GetRectOffset(pos, motions[(int)state].offsetHitPos, motions[(int)state].width, motions[(int)state].height);
}