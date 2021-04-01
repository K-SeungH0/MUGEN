#pragma once
#include <Windows.h>

class GameObject
{
public:
	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
};