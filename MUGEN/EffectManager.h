#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include "Singleton.h"
class EffectManager : public Singleton<EffectManager>
{

public:
	void Init();

};

