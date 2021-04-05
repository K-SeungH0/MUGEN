#pragma once
#include "GameObject.h"

class GameUI
{
public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

