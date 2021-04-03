#pragma once
#include "Mugen.h"
#include "GameObject.h"

class Image;
class Character : public GameObject
{
public:
	enum class DIRECTION
	{
		RIGHT,
		LEFT,
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

protected:
	enum class ATTACK_TYPE
	{
		MELEE,
		RANGE,
		NONE
	};

	struct AttackInfo
	{
		ATTACK_TYPE type;
		// 공격위치(중점)
		// 오른쪽을 바라보는 기준으로 설정
		POINTFLOAT offsetPos;
		int width;
		int height;
		// 데미지
		int damage;
	};
	struct MotionInfo
	{
		// 출력할 이미지의 상대위치 항상 오른쪽을 바라보는 기준으로 설정한다.
		// IMAGE RENDER StartX = pos.x + offsetPos.x
		POINTFLOAT offsetPos;
		// 이미지
		Image* lpImages[(int)DIRECTION::NONE];
		// 나의 피격 판정
		RECT hitRc;
		// 프레임, 히트판정/데미지
		map<int, AttackInfo> mAtkInfo;
	};

	// 애니메이션 처리를 위한 변수
	int elapsedTime;
	int frame;

	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	// 바라보는 방향
	DIRECTION dir;
	// 캐릭터 상태
	CHARACTER_STATE state;
	// 캐릭터 체력
	int hp;
	// 캐릭터 스피드
	int moveSpeed;
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
	void Move(DIRECTION direction);
	void NormalAttack();
	void StrongAttack();
	void RangeAttack();

	inline void SetType(PLAYER_TYPE type) { this->type = type; }
	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
	inline int GetHp() { return hp; }
};

