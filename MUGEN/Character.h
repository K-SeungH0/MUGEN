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

protected:
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
		// ��������
		RECT rc;
		// ������
		int damage;
	};

	struct MotionInfo
	{
		// ����� �̹����� �����ġ
		// IMAGE RENDER StartX = pos.x + offsetPos.x
		POINTFLOAT offsetPos;
		// �̹���
		Image* lpImages[(int)DIRECTION::NONE];
		// ���� �ǰ� ����
		RECT hitRc;
		// ������, ��Ʈ����/������
		map<int, AttackInfo> mAtkInfo;
	};

	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	// �ٶ󺸴� ����
	DIRECTION dir;
	// ĳ���� ����
	CHARACTER_STATE state;
	int elapsedTime;
	int frame;
	// ĳ���� ü��
	int hp;
	int preHp;
	// ĳ���� ���ǵ�
	int moveSpeed;
	// ĳ���� ��ġ
	POINTFLOAT pos;
	// ĳ���� �̸�
	// /Image/Character/ĳ�����̸�/*.bmp
	string name;
	// Init ��Ǻ� �ʱ�ȭ
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

	inline void SetType(PLAYER_TYPE type) { this->type = type; }
	inline bool IsAlive() { return state != CHARACTER_STATE::DEATH; }
};

