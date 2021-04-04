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
		int elpasedTime;
		int frame;
		Image* lpImage;
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
	void Fire(PLAYER_TYPE type, POINTFLOAT pos, int width, int height, float speed, float radian, string colliderKey = "", string hitEffectKey = "", int damage = 0);
	// 정적 충돌체 생성
	void Create(PLAYER_TYPE type, POINTFLOAT pos, int width, int height, string hitEffectKey = "", int damage = 0);

	inline list<Collider>& GetLstColliders(PLAYER_TYPE type) { return mLstColliders[type]; }
};

