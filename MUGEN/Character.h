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
		// ������ġ(����)
		// �������� �ٶ󺸴� �������� ����
		POINTFLOAT offsetPos;
		int width;
		int height;
		// ������
		int damage;
		string imageKey[(int)CHARACTER_DIRECTION::NONE];
		string hitEffectKey[(int)CHARACTER_DIRECTION::NONE];
	};
	struct MotionInfo
	{
		// ����� �̹����� �����ġ �׻� �������� �ٶ󺸴� �������� �����Ѵ�.
		// IMAGE RENDER StartX = pos.x + offsetDrawPos.x
		POINTFLOAT offsetDrawPos[(int)CHARACTER_DIRECTION::NONE];
		// �̹��������� ����
		Image* lpImages[(int)CHARACTER_DIRECTION::NONE];
		// �ִϸ��̼� �ӵ� Ŭ���� ���� 1 ~ 100
		int motionSpeed = 10;

		// ��Ʈ�ڽ� ����
		POINTFLOAT offsetHitPos;
		int width;
		int height;
		// ���� �ǰ� ���� ������ ����
		RECT hitRc;

		// ������, ��Ʈ����/������
		map<int, vector<AttackInfo>> mAtkInfos;
	};

	// �ִϸ��̼� ó���� ���� ����
	int elapsedTime;
	int frame;
	int priority;

	PLAYER_TYPE type = PLAYER_TYPE::NONE;
	// �ٶ󺸴� ����
	CHARACTER_DIRECTION dir;
	// ĳ���� ����
	CHARACTER_STATE state;
	// ĳ���� ü��
	int hp;
	// ĳ���� ���ǵ�
	int moveSpeed;
	// ĳ���� ��ġ
	POINTFLOAT pos;
	// ĳ���� �̸�
	// /Image/Character/ĳ�����̸�/*.bmp
	string name;

	// Render�� image
	Image* lpImage;
	RECT hitRc;

	// Init ��Ǻ� �ʱ�ȭ
	MotionInfo motions[(int)CHARACTER_STATE::NONE];

public:
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void Stay();
	void Hit(int damage, POINTFLOAT hitPoint, string hitEffectKey);
	void Guard();

	void LeftMove(int priority);
	void RightMove(int priority);
	void WeakAttack(int priority);
	void StrongAttack(int priority);
	void KickAttack(int priority);
	void RangeAttack(int priority);

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
	void LoadData();
};

