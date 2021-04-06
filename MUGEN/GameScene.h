#pragma once
#include "Mugen.h"
#include <Windows.h>

class GameScene
{
public:

protected:

public:
	virtual HRESULT Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Load() = 0;
};

