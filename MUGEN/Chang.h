#pragma once
#include "Character.h"

class Chang : public Character
{
public:
	Chang();
	~Chang();

	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

