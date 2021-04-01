#pragma once
#include "Character.h"
class King : public Character
{
public:
	void Init() final;
	void Release() final;
	void Update() final;
	void Render(HDC hdc) final;
};

