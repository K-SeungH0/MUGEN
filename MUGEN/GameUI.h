#pragma once
#include "Mugen.h"

class GameUI
{
protected:
	POINT pos;

protected:
	virtual void Init() {}
	virtual void Release() {}
	virtual void Update() {}
	virtual void Render(HDC hdc) {}
};

