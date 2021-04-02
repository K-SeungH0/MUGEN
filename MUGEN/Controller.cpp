#include "Mugen.h"
#include "Controller.h"
#include "Character.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::Init()
{
	lpCharacter = nullptr;
	elapsedTime = 0;
}

void Controller::Release()
{
	if (lpCharacter)
	{
		lpCharacter->Release();
		delete lpCharacter;
		lpCharacter = nullptr;
	}
}

void Controller::Update()
{
	if (type == PLAYER_TYPE::P1)
	{
		// 1P
		// W A S D // H J
		if (KeyManager::GetLpInstance()->IsStayKeyDown('A'))
		{
			lpCharacter->Move(Character::DIRECTION::LEFT);
		}
		if (KeyManager::GetLpInstance()->IsStayKeyDown('D'))
		{
			lpCharacter->Move(Character::DIRECTION::RIGHT);
		}

		if (KeyManager::GetLpInstance()->IsStayKeyDown('H'))
		{

		}
		if (KeyManager::GetLpInstance()->IsStayKeyDown('J'))
		{

		}
	}
	else
	{
		// 2P
		// ����Ű // ����Ű�е� 2 3
		if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_LEFT))
		{
			lpCharacter->Move(Character::DIRECTION::LEFT);
		}
		if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_RIGHT))
		{
			lpCharacter->Move(Character::DIRECTION::RIGHT);
		}

		if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_NUMPAD2))
		{

		}
		if (KeyManager::GetLpInstance()->IsStayKeyDown(VK_NUMPAD3))
		{

		}
	}
	lpCharacter->Update();

	if (elapsedTime++ > 50)
	{
		// 0.5�� ���� Ŀ�ǵ� �Է��� �ȵǾ��ٸ� ���� Ŀ�ǵ� �ʱ�ȭ
		elapsedTime = 0;
	}
}

void Controller::Render(HDC hdc)
{
	lpCharacter->Render(hdc);
}

void Controller::SetController(PLAYER_TYPE type, Character* lpCharacter)
{
	this->type = type;
	this->lpCharacter = lpCharacter;
	this->lpCharacter->SetType(type);
}
