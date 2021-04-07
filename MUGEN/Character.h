#pragma once
#include "Mugen.h"
#include "GameObject.h"

class Image;
class Character : public GameObject
{
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

		// 공격시 나올 이미지 정보들
		string imageKey[(int)CHARACTER_DIRECTION::NONE];
		string hitEffectKey[(int)CHARACTER_DIRECTION::NONE];
	};
	struct MotionInfo
	{
		// 출력할 이미지의 상대위치 항상 오른쪽을 바라보는 기준으로 설정한다.
		// IMAGE RENDER StartX = pos.x + offsetDrawPos.x
		POINTFLOAT offsetDrawPos[(int)CHARACTER_DIRECTION::NONE];
		// 애니메이션 속도 클수록 느림 1 ~ 100
		int motionSpeed = 10;

		// 히트박스 정보
		POINTFLOAT offsetHitPos;
		int width;
		int height;
		// 프레임, 히트판정/데미지
		map<int, vector<AttackInfo>> mAtkInfos;
	};

protected:
	// 애니메이션 처리를 위한 변수
	int elapsedTime;
	int frame;
	int priority;

	// 캐릭터의 타입 - 1P / 2P
	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	// 캐릭터가 바라볼 방향 / 공격할 방향
	CHARACTER_DIRECTION dir;
	// 캐릭터 상태
	CHARACTER_STATE state;
	// 캐릭터의 현재 상태의 이미지
	Image* lpImage;
	// 캐릭터의 히트박스
	RECT hitRc;

	// 캐릭터 위치
	POINTFLOAT pos;
	// 캐릭터 체력
	int hp;
	// 캐릭터 스피드
	int moveSpeed;

	// 캐릭터 이름
	// /Image/Character/캐릭터이름/*.bmp
	string name;

	// 모션별 공격정보
	MotionInfo motions[(int)CHARACTER_STATE::NONE];

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	// 행동
	void Stay();
	void Hit(int damage, POINTFLOAT hitPoint, string hitEffectKey);
	void Guard();

	// 커맨드
	void LeftMove(int priority);
	void RightMove(int priority);
	void WeakAttack(int priority);
	void StrongAttack(int priority);
	void KickAttack(int priority);
	void RangeAttack(int priority);

	// 바라보는 방향으로 이동
	void Translate(POINTFLOAT delta);

	inline void RefreshImage() { lpImage = ImageManager::GetLpInstance()->GetImage(GetKey(name, dir, state)); }
	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }
	inline void SetType(PLAYER_TYPE type) { this->type = type; }
	inline void SetDirection(CHARACTER_DIRECTION dir) { this->dir = dir; }
	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
	inline int GetHp() { return hp; }
	inline POINTFLOAT GetPos() { return pos; }
	inline RECT GetHitRect() { return hitRc; }
	inline PLAYER_TYPE GetPlayerType() { return type; }

protected:
	// INI파일 로드
	void LoadData();
};

