#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include "Singleton.h"
class Image;
class ImageManager : public Singleton<ImageManager>
{
private:
	map<string, Image*> mImage;
	
public:
	HRESULT Init();
	void Release();
	void Update();
	// »ç¿ë¹ý : ex) Play("KING_LEFT_IDLE")
	Image* GetImage(string key, int frame);
};