//#include "ImageManager.h"
#include "Image.h"

HRESULT ImageManager::Init()
{
#pragma region KING Image Load
	this->mImage.insert(make_pair("KING_LEFT_IDLE", new Image()));
	this->mImage["KING_LEFT_IDLE"]->Init("Image/Character/KING/KING_LEFT_IDLE.bmp", 448, 112, 7, 1, 7, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_IDLE", new Image()));
	this->mImage["KING_RIGHT_IDLE"]->Init("Image/Character/KING/KING_RIGHT_IDLE.bmp", 448, 112, 7, 1, 7, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_MOVE", new Image()));
	this->mImage["KING_LEFT_MOVE"]->Init("Image/Character/KING/KING_LEFT_MOVE.bmp", 256, 112, 4, 1, 4, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_MOVE", new Image()));
	this->mImage["KING_RIGHT_MOVE"]->Init("Image/Character/KING/KING_RIGHT_MOVE.bmp", 256, 112, 4, 1, 4, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_DEAD", new Image()));
	this->mImage["KING_LEFT_DEAD"]->Init("Image/Character/KING/KING_LEFT_DEAD.bmp", 1536, 112, 12, 1, 12, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_DEAD", new Image()));
	this->mImage["KING_RIGHT_DEAD"]->Init("Image/Character/KING/KING_RIGHT_DEAD.bmp", 1536, 112, 12, 1, 12, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_HIT1", new Image()));
	this->mImage["KING_LEFT_HIT1"]->Init("Image/Character/KING/KING_LEFT_HIT1.bmp", 400, 112, 5, 1, 5, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_HIT1", new Image()));
	this->mImage["KING_RIGHT_HIT1"]->Init("Image/Character/KING/KING_RIGHT_HIT1.bmp", 400, 112, 5, 1, 5, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_HIT2", new Image()));
	this->mImage["KING_LEFT_HIT2"]->Init("Image/Character/KING/KING_LEFT_HIT2.bmp", 448, 96, 7, 1, 7, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_HIT2", new Image()));
	this->mImage["KING_RIGHT_HIT2"]->Init("Image/Character/KING/KING_RIGHT_HIT2.bmp", 448, 96, 7, 1, 7, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_GUARD", new Image()));
	this->mImage["KING_LEFT_GUARD"]->Init("Image/Character/KING/KING_LEFT_GUARD.bmp", 128, 112, 2, 1, 2, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_GUARD", new Image()));
	this->mImage["KING_RIGHT_GUARD"]->Init("Image/Character/KING/KING_RIGHT_GUARD.bmp", 128, 112, 2, 1, 2, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_SKILL", new Image()));
	this->mImage["KING_LEFT_SKILL"]->Init("Image/Character/KING/KING_LEFT_SKILL.bmp", 384, 112, 4, 1, 4, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_SKILL", new Image()));
	this->mImage["KING_RIGHT_SKILL"]->Init("Image/Character/KING/KING_RIGHT_SKILL.bmp", 384, 112, 4, 1, 4, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_STRONGKICK", new Image()));
	this->mImage["KING_LEFT_STRONGKICK"]->Init("Image/Character/KING/KING_LEFT_STRONGKICK.bmp", 1008, 112, 9, 1, 9, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_STRONGKICK", new Image()));
	this->mImage["KING_RIGHT_STRONGKICK"]->Init("Image/Character/KING/KING_RIGHT_STRONGKICK.bmp", 1008, 112, 9, 1, 9, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_STRONGPUNCH", new Image()));
	this->mImage["KING_LEFT_STRONGPUNCH"]->Init("Image/Character/KING/KING_LEFT_STRONGPUNCH.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_STRONGPUNCH", new Image()));
	this->mImage["KING_RIGHT_STRONGPUNCH"]->Init("Image/Character/KING/KING_RIGHT_STRONGPUNCH.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_WEAKKICK", new Image()));
	this->mImage["KING_LEFT_WEAKKICK"]->Init("Image/Character/KING/KING_LEFT_WEAKKICK.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_WEAKKICK", new Image()));
	this->mImage["KING_RIGHT_WEAKKICK"]->Init("Image/Character/KING/KING_RIGHT_WEAKKICK.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_WEAKPUNCH", new Image()));
	this->mImage["KING_LEFT_WEAKPUNCH"]->Init("Image/Character/KING/KING_LEFT_WEAKPUNCH.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_WEAKPUNCH", new Image()));
	this->mImage["KING_RIGHT_WEAKPUNCH"]->Init("Image/Character/KING/KING_RIGHT_WEAKPUNCH.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));
#pragma endregion

#pragma region DIO Image Load
	this->mImage.insert(make_pair("DIO_LEFT_HIT", new Image()));
	this->mImage["DIO_LEFT_HIT"]->Init("Image/Character/DIO/DIO_LEFT_HIT.bmp", 234, 333, 2, 3, 5, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_HIT", new Image()));
	this->mImage["DIO_RIGHT_HIT"]->Init("Image/Character/DIO/DIO_RIGHT_HIT.bmp", 234, 333, 2, 3, 5, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_HIT2", new Image()));
	this->mImage["DIO_LEFT_HIT2"]->Init("Image/Character/DIO/DIO_LEFT_HIT2.bmp", 188, 128, 2, 1, 2, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_HIT2", new Image()));
	this->mImage["DIO_RIGHT_HIT2"]->Init("Image/Character/DIO/DIO_RIGHT_HIT2.bmp", 188, 128, 2, 1, 2, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_ATTACK_WEAK", new Image()));
	this->mImage["DIO_LEFT_ATTACK_WEAK"]->Init("Image/Character/DIO/DIO_LEFT_ATTACK_WEAK.bmp", 230, 110, 2, 1, 2, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_ATTACK_WEAK", new Image()));
	this->mImage["DIO_RIGHT_ATTACK_WEAK"]->Init("Image/Character/DIO/DIO_RIGHT_ATTACK_WEAK.bmp", 230, 110, 2, 1, 2, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_ATTACK_STRONG", new Image()));
	this->mImage["DIO_LEFT_ATTACK_STRONG"]->Init("Image/Character/DIO/DIO_LEFT_ATTACK_STRONG.bmp", 474, 472, 3, 4, 10, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_ATTACK_STRONG", new Image()));
	this->mImage["DIO_RIGHT_ATTACK_STRONG"]->Init("Image/Character/DIO/DIO_RIGHT_ATTACK_STRONG.bmp", 474, 472, 3, 4, 10, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_ATTACK_KICK", new Image()));
	this->mImage["DIO_LEFT_ATTACK_KICK"]->Init("Image/Character/DIO/DIO_LEFT_ATTACK_KICK.bmp", 360, 560, 2, 5, 9, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_ATTACK_KICK", new Image()));
	this->mImage["DIO_RIGHT_ATTACK_KICK"]->Init("Image/Character/DIO/DIO_RIGHT_ATTACK_KICK.bmp", 360, 560, 2, 5, 9, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_GUARD", new Image()));
	this->mImage["DIO_LEFT_GUARD"]->Init("Image/Character/DIO/DIO_LEFT_GUARD.bmp", 142, 117, 2, 1, 2, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_GUARD", new Image()));
	this->mImage["DIO_RIGHT_GUARD"]->Init("Image/Character/DIO/DIO_RIGHT_GUARD.bmp", 142, 117, 2, 1, 2, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_DEATH", new Image()));
	this->mImage["DIO_LEFT_DEATH"]->Init("Image/Character/DIO/DIO_LEFT_DEATH.bmp", 456, 540, 3, 5, 13, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_DEATH", new Image()));
	this->mImage["DIO_RIGHT_DEATH"]->Init("Image/Character/DIO/DIO_RIGHT_DEATH.bmp", 456, 540, 3, 5, 13, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_IDLE", new Image()));
	this->mImage["DIO_LEFT_IDLE"]->Init("Image/Character/DIO/DIO_LEFT_IDLE.bmp", 198, 240, 3, 2, 6, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_IDLE", new Image()));
	this->mImage["DIO_RIGHT_IDLE"]->Init("Image/Character/DIO/DIO_RIGHT_IDLE.bmp", 198, 240, 3, 2, 6, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_MOVE", new Image()));
	this->mImage["DIO_LEFT_MOVE"]->Init("Image/Character/DIO/DIO_LEFT_MOVE.bmp", 316, 460, 4, 4, 16, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_MOVE", new Image()));
	this->mImage["DIO_RIGHT_MOVE"]->Init("Image/Character/DIO/DIO_RIGHT_MOVE.bmp", 316, 460, 4, 4, 16, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_LEFT_RANGE_ATTACK", new Image()));
	this->mImage["DIO_LEFT_RANGE_ATTACK"]->Init("Image/Character/DIO/DIO_LEFT_RANGE_ATTACK.bmp", 438, 292, 3, 2, 6, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_RANGE_ATTACK", new Image()));
	this->mImage["DIO_RIGHT_RANGE_ATTACK"]->Init("Image/Character/DIO/DIO_RIGHT_RANGE_ATTACK.bmp", 438, 292, 3, 2, 6, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("DIO_LEFT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["DIO_LEFT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/DIO/DIO_LEFT_RANGE_ATTACK_COLLIDER.bmp", 208, 5, 4, 1, 4, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("DIO_RIGHT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["DIO_RIGHT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/DIO/DIO_RIGHT_RANGE_ATTACK_COLLIDER.bmp", 208, 5, 4, 1, 4, true, RGB(255, 0, 255));

#pragma endregion

#pragma region Chang Image Load
	this->mImage.insert(make_pair("Chang_LEFT_IDLE", new Image()));
	this->mImage["Chang_LEFT_IDLE"]->Init("Image/Character/Chang/Chang_LEFT_IDLE.bmp", 900, 172, 6, 1, 6, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_IDLE", new Image()));
	this->mImage["Chang_RIGHT_IDLE"]->Init("Image/Character/Chang/Chang_RIGHT_IDLE.bmp", 900, 172, 6, 1, 6, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_MOVE", new Image()));
	this->mImage["Chang_LEFT_MOVE"]->Init("Image/Character/Chang/Chang_LEFT_MOVE.bmp", 1500, 172, 10, 1, 10, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_MOVE", new Image()));
	this->mImage["Chang_RIGHT_MOVE"]->Init("Image/Character/Chang/Chang_RIGHT_MOVE.bmp", 1500, 172, 10, 1, 10, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_GUARD", new Image()));
	this->mImage["Chang_LEFT_GUARD"]->Init("Image/Character/Chang/Chang_LEFT_GUARD.bmp", 450, 170, 3, 1, 3, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_GUARD", new Image()));
	this->mImage["Chang_RIGHT_GUARD"]->Init("Image/Character/Chang/Chang_RIGHT_GUARD.bmp", 450, 170, 3, 1, 3, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_ATTACK_WEAK", new Image()));
	this->mImage["Chang_LEFT_ATTACK_WEAK"]->Init("Image/Character/Chang/Chang_LEFT_ATTACK_WEAK.bmp", 875, 175, 5, 1, 5, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_ATTACK_WEAK", new Image()));
	this->mImage["Chang_RIGHT_ATTACK_WEAK"]->Init("Image/Character/Chang/Chang_RIGHT_ATTACK_WEAK.bmp", 875, 175, 5, 1, 5, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_ATTACK_STRONG", new Image()));
	this->mImage["Chang_LEFT_ATTACK_STRONG"]->Init("Image/Character/Chang/Chang_LEFT_ATTACK_STRONG.bmp", 3000, 170, 12, 1, 12, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_ATTACK_STRONG", new Image()));
	this->mImage["Chang_RIGHT_ATTACK_STRONG"]->Init("Image/Character/Chang/Chang_RIGHT_ATTACK_STRONG.bmp", 3000, 170, 12, 1, 12, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_ATTACK_KICK", new Image()));
	this->mImage["Chang_LEFT_ATTACK_KICK"]->Init("Image/Character/Chang/Chang_LEFT_ATTACK_KICK.bmp", 1760, 170, 8, 1, 8, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_ATTACK_KICK", new Image()));
	this->mImage["Chang_RIGHT_ATTACK_KICK"]->Init("Image/Character/Chang/Chang_RIGHT_ATTACK_KICK.bmp", 1760, 170, 8, 1, 8, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_RANGE_ATTACK", new Image()));
	this->mImage["Chang_LEFT_RANGE_ATTACK"]->Init("Image/Character/Chang/Chang_LEFT_RANGE_ATTACK.bmp", 1800, 175, 12, 1, 12, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_RANGE_ATTACK", new Image()));
	this->mImage["Chang_RIGHT_RANGE_ATTACK"]->Init("Image/Character/Chang/Chang_RIGHT_RANGE_ATTACK.bmp", 1800, 175, 12, 1, 12, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_DOWN", new Image()));
	this->mImage["Chang_LEFT_DOWN"]->Init("Image/Character/Chang/Chang_LEFT_DOWN.bmp", 4000, 200, 16, 1, 16, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_DOWN", new Image()));
	this->mImage["Chang_RIGHT_DOWN"]->Init("Image/Character/Chang/Chang_RIGHT_DOWN.bmp", 4000, 200, 16, 1, 16, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("Chang_LEFT_HIT", new Image()));
	this->mImage["Chang_LEFT_HIT"]->Init("Image/Character/Chang/Chang_LEFT_HIT.bmp", 1400, 175, 7, 1, 7, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_HIT", new Image()));
	this->mImage["Chang_RIGHT_HIT"]->Init("Image/Character/Chang/Chang_RIGHT_HIT.bmp", 1400, 175, 7, 1, 7, true, RGB(255, 0, 255));


	this->mImage.insert(make_pair("Chang_LEFT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["Chang_LEFT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/Chang/Chang_LEFT_RANGE_ATTACK_COLLIDER.bmp", 52, 53, 1, 1, 1, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["Chang_RIGHT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/Chang/Chang_RIGHT_RANGE_ATTACK_COLLIDER.bmp", 52, 53, 1, 1, 1, true, RGB(255, 0, 255));
	
	this->mImage.insert(make_pair("Chang_LEFT_BACKMOVE", new Image()));
	this->mImage["Chang_LEFT_BACKMOVE"]->Init("Image/Character/Chang/Chang_LEFT_BACKMOVE.bmp", 1500, 170, 10, 1, 10, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Chang_RIGHT_BACKMOVE", new Image()));
	this->mImage["Chang_RIGHT_BACKMOVE"]->Init("Image/Character/Chang/Chang_RIGHT_BACKMOVE.bmp", 1500, 170, 10, 1, 10, true, RGB(255, 0, 255));
#pragma endregion

#pragma region Effect Image Load

#pragma endregion

	return S_OK;
}

void ImageManager::Release()
{
	for (auto iter = mImage.begin(); iter != mImage.end(); iter++) 
	{
		mImage[iter->first]->Release(); 

		delete mImage[iter->first];
		mImage[iter->first] = nullptr;
	}
}

void ImageManager::Update()
{
	
}

Image* ImageManager::GetImage(string key)
{
	return this->mImage[key];
}
