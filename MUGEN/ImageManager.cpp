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

	this->mImage.insert(make_pair("KING_LEFT_MOVE_GUARD", new Image()));
	this->mImage["KING_LEFT_MOVE_GUARD"]->Init("Image/Character/KING/KING_LEFT_MOVE_GUARD.bmp", 256, 112, 4, 1, 4, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_MOVE_GUARD", new Image()));
	this->mImage["KING_RIGHT_MOVE_GUARD"]->Init("Image/Character/KING/KING_RIGHT_MOVE_GUARD.bmp", 256, 112, 4, 1, 4, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_DEATH", new Image()));
	this->mImage["KING_LEFT_DEATH"]->Init("Image/Character/KING/KING_LEFT_DEATH.bmp", 1536, 112, 12, 1, 12, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_DEATH", new Image()));
	this->mImage["KING_RIGHT_DEATH"]->Init("Image/Character/KING/KING_RIGHT_DEATH.bmp", 1536, 112, 12, 1, 12, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_HIT", new Image()));
	this->mImage["KING_LEFT_HIT"]->Init("Image/Character/KING/KING_LEFT_HIT.bmp", 448, 96, 7, 1, 7, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_HIT", new Image()));
	this->mImage["KING_RIGHT_HIT"]->Init("Image/Character/KING/KING_RIGHT_HIT.bmp", 448, 96, 7, 1, 7, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_GUARD", new Image()));
	this->mImage["KING_LEFT_GUARD"]->Init("Image/Character/KING/KING_LEFT_GUARD.bmp", 128, 112, 2, 1, 2, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_GUARD", new Image()));
	this->mImage["KING_RIGHT_GUARD"]->Init("Image/Character/KING/KING_RIGHT_GUARD.bmp", 128, 112, 2, 1, 2, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_ATTACK_RANGE", new Image()));
	this->mImage["KING_LEFT_ATTACK_RANGE"]->Init("Image/Character/KING/KING_LEFT_ATTACK_RANGE.bmp", 384, 112, 4, 1, 4, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_ATTACK_RANGE", new Image()));
	this->mImage["KING_RIGHT_ATTACK_RANGE"]->Init("Image/Character/KING/KING_RIGHT_ATTACK_RANGE.bmp", 384, 112, 4, 1, 4, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_ATTACK_KICK", new Image()));
	this->mImage["KING_LEFT_ATTACK_KICK"]->Init("Image/Character/KING/KING_LEFT_ATTACK_KICK.bmp", 1008, 112, 9, 1, 9, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_ATTACK_KICK", new Image()));
	this->mImage["KING_RIGHT_ATTACK_KICK"]->Init("Image/Character/KING/KING_RIGHT_ATTACK_KICK.bmp", 1008, 112, 9, 1, 9, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_ATTACK_STRONG", new Image()));
	this->mImage["KING_LEFT_ATTACK_STRONG"]->Init("Image/Character/KING/KING_LEFT_ATTACK_STRONG.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_ATTACK_STRONG", new Image()));
	this->mImage["KING_RIGHT_ATTACK_STRONG"]->Init("Image/Character/KING/KING_RIGHT_ATTACK_STRONG.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_ATTACK_WEAK", new Image()));
	this->mImage["KING_LEFT_ATTACK_WEAK"]->Init("Image/Character/KING/KING_LEFT_ATTACK_WEAK.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));
	this->mImage.insert(make_pair("KING_RIGHT_ATTACK_WEAK", new Image()));
	this->mImage["KING_RIGHT_ATTACK_WEAK"]->Init("Image/Character/KING/KING_RIGHT_ATTACK_WEAK.bmp", 480, 112, 5, 1, 5, true, RGB(140, 206, 156));

	this->mImage.insert(make_pair("KING_LEFT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["KING_LEFT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/KING/KING_LEFT_RANGE_ATTACK_COLLIDER.bmp", 320, 48, 4, 1, 4, true, RGB(255, 0, 0));
	this->mImage.insert(make_pair("KING_RIGHT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["KING_RIGHT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/KING/KING_RIGHT_RANGE_ATTACK_COLLIDER.bmp", 320, 48, 4, 1, 4, true, RGB(255, 0, 0));
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
	this->mImage.insert(make_pair("KING_LEFT_RANGE_ATTACK_EFFECT", new Image()));
	this->mImage["KING_LEFT_RANGE_ATTACK_EFFECT"]->Init("Image/Character/KING/KING_LEFT_RANGE_ATTACK_EFFECT.bmp", 800, 144, 10, 1, 10, true, RGB(255, 0, 0));
	this->mImage.insert(make_pair("KING_RIGHT_RANGE_ATTACK_EFFECT", new Image()));
	this->mImage["KING_RIGHT_RANGE_ATTACK_EFFECT"]->Init("Image/Character/KING/KING_RIGHT_RANGE_ATTACK_EFFECT.bmp", 800, 144, 10, 1, 10, true, RGB(255, 0, 0));
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

Image* ImageManager::GetImage(string name, CHARACTER_DIRECTION dir, CHARACTER_STATE state)
{
	string key = "";
	key += name;

	switch (dir)
	{
	case CHARACTER_DIRECTION::RIGHT:
		key += "_RIGHT";
		break;
	case CHARACTER_DIRECTION::LEFT:
		key += "_LEFT";
		break;
	case CHARACTER_DIRECTION::NONE:
		break;
	}

	switch (state)
	{
		case CHARACTER_STATE::IDLE:
			key += "_IDLE";
			break;
		case CHARACTER_STATE::MOVE:
			key += "_MOVE";
			break;
		case CHARACTER_STATE::MOVE_GUARD:
			key += "_MOVE_GUARD";
			break;
		case CHARACTER_STATE::GUARD:
			key += "_GUARD";
			break;
		case CHARACTER_STATE::ATTACK_WEAK:
			key += "_ATTACK_WEAK";
			break;
		case CHARACTER_STATE::ATTACK_STRONG:
			key += "_ATTACK_STRONG";
			break;
		case CHARACTER_STATE::ATTACK_KICK:
			key += "_ATTACK_KICK";
			break;
		case CHARACTER_STATE::ATTACK_RANGE:
			key += "_ATTACK_RANGE";
			break;
		case CHARACTER_STATE::HIT:
			key += "_HIT";
			break;
		case CHARACTER_STATE::DEATH:
			key += "_DEATH";
			break;
		case CHARACTER_STATE::NONE:
			break;
	}
	return this->mImage[key];
}
