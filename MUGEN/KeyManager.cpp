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
	
	�Լ� ȣ�� ������ ����Ű(VK_...)�� � �������� Ȯ��
	1. 0x0000 -> ���� �����ӿ� �������� ���� ȣ��������� �������� ����
	2. 0x0001 -> ���� �����ӿ� �������� �ְ� ȣ��������� �������� ����
	3. 0x8000 -> ���� �����ӿ� �������� ���� ȣ��������� �����ִ� ����
	4. 0x8001 -> ���� �����ӿ� �������� �ְ� ȣ��������� �����ִ� ����
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
