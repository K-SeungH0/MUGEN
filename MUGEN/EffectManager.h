#pragma once
#include "Singleton.h"

class Image;
class EffectManager : public Singleton<EffectManager>
{
private:
	struct EffectImageInfo
	{
		POINTFLOAT pos;
		Image* lpImage;
	};

	list<EffectImageInfo> lImage;
public:
	void Init();
	void Release();
	void Render(HDC hdc);
	void EffectRender(POINTFLOAT pos, Image* image);
	void EffectRender(POINTFLOAT pos, string key);
};