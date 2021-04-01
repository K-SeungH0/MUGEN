#pragma once
#include "Mugen.h"
#include "GameObject.h"

class Image;
class Character : public GameObject
{
protected:
	enum class DIRECTION
	{
		LEFT,
		RIGHT,
		NONE
	};
	enum class CHARACTER_STATE
	{
		IDLE,
		MOVE,
		ATTACK_WEAK,
		ATTACK_STRONG,
		HIT,
		DEATH,
		NONE
	};
	struct AttackInfo
	{
		// 공격판정
		RECT rc;
		// 데미지
		int damage;
	};

	struct MotionInfo
	{
		// 출력할 이미지의 상대위치
		// IMAGE RENDER StartX = pos.x + offsetPos.x
		POINTFLOAT offsetPos;
		// 이미지
		Image* lpImages[(int)DIRECTION::NONE];
		// 나의 피격 판정
		RECT hitRc;
		// 프레임, 히트판정/데미지
		map<int, AttackInfo> mAtkInfo;
	};

	// 바라보는 방향
	DIRECTION dir;
	// 캐릭터 상태
	CHARACTER_STATE state;
	// 캐릭터 체력
	int hp;
	int preHp;
	// 캐릭터 위치
	POINTFLOAT pos;
	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	string name;
	// Init 모션별 초기화
	MotionInfo motions[(int)CHARACTER_STATE::NONE];

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Hit(int damage);

	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
};

