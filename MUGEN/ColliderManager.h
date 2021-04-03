#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <map>
#include <list>
#include <functional>

using namespace std;

enum class PLAYER_TYPE;

class Image;
class GameObject;
class ColliderManager : public Singleton<ColliderManager>
{
public:
	enum class COLLIDER_TYPE
	{
		STATIC,
		MOVEMENT,
		NONE
	};

	// �ΰ����� �̹��� ������ �����־���Ѵ�.
	// �ش� Collider�� �̹��� Key
	// ��Ʈ�� ���� ����Ʈ Key
	struct Collider
	{
		COLLIDER_TYPE type;
		string imageKey;
		string hitEffectKey;
		int damage;
		int width;
		int height;
		POINTFLOAT pos;
		float speed;
		float radian;
	};

private:
	map<PLAYER_TYPE, list<Collider>> mLstColliders;

public:
	ColliderManager();
	~ColliderManager();

	HRESULT Init();
	void Update();
	void Render(HDC hdc);

	// �����̴� �浹ü ����
	void Fire(PLAYER_TYPE type, POINTFLOAT pos, int width, int height, float speed, float radian);
	// ���� �浹ü ����
	void Create(PLAYER_TYPE type, POINTFLOAT pos, int width, int height);

	// ������ ��Ʈ�ڽ��� Ÿ�� �ݹ��Լ��� �Ѱ��ְ� �¾Ҵٸ� Ÿ���Լ� ����
	// �ϳ��� �¾Ҵٸ� true
	bool IsCollision(PLAYER_TYPE type, RECT selfHitBox, function<void(int)> lpfnHit = nullptr);
};

