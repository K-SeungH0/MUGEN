#include "Mugen.h"
#include "ColliderManager.h"

ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}

HRESULT ColliderManager::Init()
{
	mLstColliders.insert(make_pair(PLAYER_TYPE::P1, list<Collider>()));
	mLstColliders.insert(make_pair(PLAYER_TYPE::P2, list<Collider>()));
	return S_OK;
}

void ColliderManager::Update()
{
	for (auto& pair : mLstColliders)
	{
		list<Collider>& lstColliders = pair.second;
		for (auto it = lstColliders.begin(); it != lstColliders.end();)
		{
			switch (it->type)
			{
			case COLLIDER_TYPE::STATIC:
				it = lstColliders.erase(it);
				break;
			case COLLIDER_TYPE::MOVEMENT:
				it->pos.x += cosf(it->radian) * it->speed;
				it->pos.y += sinf(it->radian) * it->speed;

				if (it->pos.x < 0 || it->pos.x > WINSIZE_WIDTH) it = lstColliders.erase(it);
				else ++it;
				break;
			}
		}
	}
}

void ColliderManager::Render(HDC hdc)
{
	if (isDebugMode)
	{
		for (auto pair : mLstColliders)
		{
			list<Collider> lstColliders = pair.second;
			for (auto it = lstColliders.begin(); it != lstColliders.end(); ++it)
			{
				RECT rect = {it->pos.x - it->width / 2, it->pos.y - it->height / 2, it->pos.x + it->width / 2, it->pos.y + it->height / 2 };
				Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
			}
		}
	}
}

void ColliderManager::Fire(PLAYER_TYPE type, POINTFLOAT pos, int width, int height, float speed, float radian, int damage)
{
	Collider collider;
	collider.type = COLLIDER_TYPE::MOVEMENT;
	collider.damage = damage;
	collider.width = width;
	collider.height = height;
	collider.pos = pos;
	collider.speed = speed;
	collider.radian = radian;

	mLstColliders[type].push_back(collider);
}

void ColliderManager::Create(PLAYER_TYPE type, POINTFLOAT pos, int width, int height, int damage)
{
	Collider collider;
	collider.type = COLLIDER_TYPE::STATIC;
	collider.damage = damage;
	collider.width = width;
	collider.height = height;
	collider.pos = pos;
	collider.speed = 0;
	collider.radian = 0;

	mLstColliders[type].push_back(collider);
}