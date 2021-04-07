#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include "Singleton.h"

using namespace std;

class Image;
class ImageManager : public Singleton<ImageManager>
{
private:
	map<string, Image*> mImage;
	
public:
	HRESULT Init();
	void Release();
	// »ç¿ë¹ý : ex) GetImage("KING_LEFT_IDLE")
	Image* GetImage(string key);
};