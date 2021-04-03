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
#pragma endregion

#pragma region Chang Image Load
	this->mImage.insert(make_pair("LeftChang_Idle", new Image()));
	this->mImage["LeftChang_Idle"]->Init("Image/Character/Chang/LeftChang_Idle.bmp", 3960, 532, 6, 1, 6, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_Idle", new Image()));
	this->mImage["RightChang_Idle"]->Init("Image/Character/Chang/RightChang_Idle.bmp", 3960, 532, 6, 1, 6, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_Move", new Image()));
	this->mImage["LeftChang_Move"]->Init("Image/Character/Chang/LeftChang_Move.bmp", 6600, 532, 10, 1, 10, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_Move", new Image()));
	this->mImage["RightChang_Move"]->Init("Image/Character/Chang/RightChang_Move.bmp", 6600, 532, 10, 1, 10, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_BackMove", new Image()));
	this->mImage["LeftChang_BackMove"]->Init("Image/Character/Chang/LeftChang_BackMove.bmp", 6600, 532, 10, 1, 10, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_BackMove", new Image()));
	this->mImage["RightChang_BackMove"]->Init("Image/Character/Chang/RightChang_BackMove.bmp", 6600, 532, 10, 1, 10, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_LeftKick", new Image()));
	this->mImage["LeftChang_LeftKick"]->Init("Image/Character/Chang/LeftChang_LeftKick.bmp", 1980, 532, 3, 1, 3, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_LeftKick", new Image()));
	this->mImage["RightChang_LeftKick"]->Init("Image/Character/Chang/RightChang_LeftKick.bmp", 1980, 532, 3, 1, 3, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_LeftPunch", new Image()));
	this->mImage["LeftChang_LeftPunch"]->Init("Image/Character/Chang/LeftChang_LeftPunch.bmp", 3300, 532, 5, 1, 5, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_LeftPunch", new Image()));
	this->mImage["RightChang_LeftPunch"]->Init("Image/Character/Chang/RightChang_LeftPunch.bmp", 3300, 532, 5, 1, 5, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_RightPunch", new Image()));
	this->mImage["LeftChang_RightPunch"]->Init("Image/Character/Chang/LeftChang_RightPunch.bmp", 7920, 531, 12, 1, 12, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_RightPunch", new Image()));
	this->mImage["RightChang_RightPunch"]->Init("Image/Character/Chang/RightChang_RightPunch.bmp", 7920, 531, 12, 1, 12, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_RightKick", new Image()));
	this->mImage["LeftChang_RightKick"]->Init("Image/Character/Chang/LeftChang_RightKick.bmp", 4620, 532, 7, 1, 7, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_RightKick", new Image()));
	this->mImage["RightChang_RightKick"]->Init("Image/Character/Chang/RightChang_RightKick.bmp", 4620, 532, 7, 1, 7, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("LeftChang_RangeAttack", new Image()));
	this->mImage["LeftChang_RangeAttack"]->Init("Image/Character/Chang/LeftChang_RangeAttack.bmp", 2640, 532, 4, 1, 4, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("RightChang_RangeAttack", new Image()));
	this->mImage["RightChang_RangeAttack"]->Init("Image/Character/Chang/RightChang_RangeAttack.bmp", 2640, 532, 4, 1, 4, true, RGB(255, 0, 255));
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
