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

	// 두가지의 이미지 정보를 갖고있어야한다.
	// 해당 Collider의 이미지 Key
	// 히트시 나올 이펙트 Key
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

	// 움직이는 충돌체 생성
	void Fire(PLAYER_TYPE type, POINTFLOAT pos, int width, int height, float speed, float radian);
	// 정적 충돌체 생성
	void Create(PLAYER_TYPE type, POINTFLOAT pos, int width, int height);

	// 본인의 히트박스와 타격 콜백함수를 넘겨주고 맞았다면 타격함수 실행
	// 하나라도 맞았다면 true
	bool IsCollision(PLAYER_TYPE type, RECT selfHitBox, function<void(int)> lpfnHit = nullptr);
};

