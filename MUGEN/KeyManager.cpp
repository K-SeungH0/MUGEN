#include "KeyManeger.h"
//#include "config"

HRESULT KeyManeger::Init()
{
	keyUp.set();
	keyDown.reset();
	return S_OK;
}

void KeyManeger::Release()
{
	ReleaseSingleton();
}

bool KeyManeger::IsInceKeyDown(int key)
{
	/*
	GetAsyncKeyState(VK_...)
	
	함수 호출 시점에 가상키(VK_...)가 어떤 상태인지 확인
	1. 0x0000 -> 이전 프레임에 누른적이 없고 호출시점에도 눌려있지 않음
	2. 0x0001 -> 이전 프레임에 누른적이 있고 호출시점에도 눌려있지 않음
	3. 0x8000 -> 이전 프레임에 누른적이 없고 호출시점에도 눌려있는 상태
	4. 0x8001 -> 이전 프레임에 누른적이 있고 호출시점에도 눌려있는 상태
	*/

	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (keyDown[key] == false)
		{
			keyDown[key] = true;
			return true;
		}
	}
	else
	{
		keyDown[key] = false;
	}
	return false;
}

bool KeyManeger::IsOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		keyUp[key] = false;
	}
	else
	{
		if (keyUp[key] == false)
		{
			keyUp[key] = true;
			return true;
		}
	}
	return false;
}

bool KeyManeger::IsStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}

	return false;
}
