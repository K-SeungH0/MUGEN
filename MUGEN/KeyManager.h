#pragma once
#include "Singleton.h"
#include  <bitset>	   //config 작성후 제거
#include <windows.h>   //config 작성후 제거

#define MAX_KEY_COUNT	256

using namespace std;

class KeyManeger : public Singleton<KeyManeger>
{
private:
	bitset<MAX_KEY_COUNT>	keyUp;
	bitset<MAX_KEY_COUNT>	keyDown;

public:
	HRESULT Init();
	void Release();

	bool IsInceKeyDown(int key);
	bool IsOnceKeyUp(int key);
	bool IsStayKeyDown(int key);

	void SetKeyDown(int key, bool state) { this->keyDown.set(key, state); }
	void SetKeyUp(int key, bool state) { this->keyDown.set(key, state); }
};

