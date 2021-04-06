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

	this->mImage.insert(make_pair("KING_LEFT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["KING_LEFT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/KING/KING_LEFT_RANGE_ATTACK_COLLIDER.bmp", 320, 48, 4, 1, 4, true, RGB(255, 0, 0));
	this->mImage.insert(make_pair("KING_RIGHT_RANGE_ATTACK_COLLIDER", new Image()));
	this->mImage["KING_RIGHT_RANGE_ATTACK_COLLIDER"]->Init("Image/Character/KING/KING_RIGHT_RANGE_ATTACK_COLLIDER.bmp", 320, 48, 4, 1, 4, true, RGB(255, 0, 0));

	this->mImage.insert(make_pair("KING_LEFT_RANGE_ATTACK_EFFECT", new Image()));
	this->mImage["KING_LEFT_RANGE_ATTACK_EFFECT"]->Init("Image/Character/KING/KING_LEFT_RANGE_ATTACK_EFFECT.bmp", 800, 144, 10, 1, 10, true, RGB(255, 0, 0));
	this->mImage.insert(make_pair("KING_RIGHT_RANGE_ATTACK_EFFECT", new Image()));
	this->mImage["KING_RIGHT_RANGE_ATTACK_EFFECT"]->Init("Image/Character/KING/KING_RIGHT_RANGE_ATTACK_EFFECT.bmp", 800, 144, 10, 1, 10, true, RGB(255, 0, 0));
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

#pragma region GameUI Image Load
	this->mImage.insert(make_pair("Player1_HPUI", new Image()));
	this->mImage["Player1_HPUI"]->Init("Image/UI/Player/Player1_HPUI.bmp", 701 / 2, 324 / 2, 1, 1, 1, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("Player2_HPUI", new Image()));
	this->mImage["Player2_HPUI"]->Init("Image/UI/Player/Player2_HPUI.bmp", 701 / 2, 324 / 2, 1, 1, 1, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("HP", new Image()));
	this->mImage["HP"]->Init("Image/UI/Player/HP.bmp", 499 / 2+1, 54/ 2);
	this->mImage.insert(make_pair("Delay_HP", new Image()));
	this->mImage["Delay_HP"]->Init("Image/UI/Player/Delay_HP.bmp", 499 / 2+1, 54/ 2);


	this->mImage.insert(make_pair("KO", new Image()));
	this->mImage["KO"]->Init("Image/UI/Round/KO.bmp", 17000*2*1200/WINSIZE_WIDTH, 288*2*600 / WINSIZE_WIDTH, 34, 1, 34, true, RGB(0, 255, 0));
	this->mImage.insert(make_pair("FINAL", new Image()));
	this->mImage["FINAL"]->Init("Image/UI/Round/FINALROUND.bmp", 3154, 1000, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("ROUND1", new Image()));
	this->mImage["ROUND1"]->Init("Image/UI/Round/ROUND1.bmp", 2000, 1000, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("ROUND2", new Image()));
	this->mImage["ROUND2"]->Init("Image/UI/Round/ROUND2.bmp", 2000, 1000, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("ROUND3", new Image()));
	this->mImage["ROUND3"]->Init("Image/UI/Round/ROUND3.bmp", 2000, 1000, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("ROUND4", new Image()));
	this->mImage["ROUND4"]->Init("Image/UI/Round/ROUND4.bmp", 2000, 1000, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("ROUND5", new Image()));
	this->mImage["ROUND5"]->Init("Image/UI/Round/ROUND5.bmp", 2000, 1000, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("READY", new Image()));
	this->mImage["READY"]->Init("Image/UI/Round/READY.bmp", 1429, 240, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("GO", new Image()));
	this->mImage["GO"]->Init("Image/UI/Round/GO.bmp", 497, 160, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("UI_Time", new Image()));
	this->mImage["UI_Time"]->Init("Image/UI/Number/UI_Time.bmp", 1200, 120, 10, 1, 10, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("UI_Player1_Chang", new Image()));
	this->mImage["UI_Player1_Chang"]->Init("Image/UI/Player/UI_Player1_Chang.bmp", 215, 136, 1, 1, 1, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("UI_Player2_Chang", new Image()));
	this->mImage["UI_Player2_Chang"]->Init("Image/UI/Player/UI_Player2_Chang.bmp", 215, 136, 1, 1, 1, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("UI_Player1_DIO", new Image()));
	this->mImage["UI_Player1_DIO"]->Init("Image/UI/Player/UI_Player1_DIO.bmp", 215, 143, 1, 1, 1, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("UI_Player2_DIO", new Image()));
	this->mImage["UI_Player2_DIO"]->Init("Image/UI/Player/UI_Player2_DIO.bmp", 215, 143, 1, 1, 1, true, RGB(255, 0, 255));

	this->mImage.insert(make_pair("UI_Player1_KING", new Image()));
	this->mImage["UI_Player1_KING"]->Init("Image/UI/Player/UI_Player1_KING.bmp", 215, 143, 1, 1, 1, true, RGB(255, 0, 255));
	this->mImage.insert(make_pair("UI_Player2_KING", new Image()));
	this->mImage["UI_Player2_KING"]->Init("Image/UI/Player/UI_Player2_KING.bmp", 215, 143, 1, 1, 1, true, RGB(255, 0, 255));

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
