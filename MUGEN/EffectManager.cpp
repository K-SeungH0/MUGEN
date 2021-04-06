#include "Image.h"

void EffectManager::Init()
{

}

void EffectManager::Release()
{

}

void EffectManager::Render(HDC hdc)
{
	for (auto iter = lImage.begin(); iter != lImage.end();)
	{
		iter->lpImage->Render(hdc, iter->pos.x - iter->lpImage->GetImageInfo()->width / 2, iter->pos.y - iter->lpImage->GetImageInfo()->height / 2, iter->lpImage->GetImageInfo()->currentFrame);
		iter->lpImage->GetImageInfo()->currentFrame++;
		if (iter->lpImage->GetImageInfo()->currentFrame >= iter->lpImage->GetImageInfo()->maxFrame)
		{
			iter->lpImage->GetImageInfo()->currentFrame = 0;
			iter->lpImage = nullptr;
			iter = lImage.erase(iter);
		}
		else
			iter++;
	}
}

void EffectManager::EffectRender(POINTFLOAT pos, Image* image)
{
	EffectImageInfo addEffect;
	addEffect.pos = pos;
	addEffect.lpImage = image;
	lImage.push_back(addEffect);
}

void EffectManager::EffectRender(POINTFLOAT pos, string key)
{
	EffectImageInfo addEffect;
	addEffect.pos = pos;
	addEffect.lpImage = ImageManager::GetLpInstance()->GetImage(key);
	lImage.push_back(addEffect);
}
