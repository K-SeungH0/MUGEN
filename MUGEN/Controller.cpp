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
	if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::LEFT]))
	{
		CommandInput(SKILL_KIND::LEFT);
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::RIGHT]))
	{
		CommandInput(SKILL_KIND::RIGHT);
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::DOWN]))
	{
		CommandInput(SKILL_KIND::DOWN);
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::UP]))
	{
		CommandInput(SKILL_KIND::UP);
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::ATTACK_NORMAL]))
	{
		CommandInput(SKILL_KIND::ATTACK_NORMAL);
	}
	if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::ATTACK_STRONG]))
	{
		CommandInput(SKILL_KIND::ATTACK_STRONG);
	}
	
	lpCharacter->Update();

	if (elapsedTime++ > 50)
	{
		// 0.5초 정도 커맨드 입력이 안되었다면 이전 커맨드 초기화
		elapsedTime = 0;
		lpmCommands = nullptr;
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

	skills[(int)SKILL_KIND::LEFT].lpfnCmd = &Character::LeftMove;
	skills[(int)SKILL_KIND::RIGHT].lpfnCmd = &Character::RightMove;
	skills[(int)SKILL_KIND::ATTACK_NORMAL].lpfnCmd = &Character::NormalAttack;
	skills[(int)SKILL_KIND::ATTACK_STRONG].lpfnCmd = &Character::StrongAttack;
	skills[(int)SKILL_KIND::ATTACK_RANGE].lpfnCmd = &Character::RangeAttack;

	switch (type)
	{
	case PLAYER_TYPE::P1:
		// 1P
		// W A S D // H J
		mSkillKey.insert(make_pair(SKILL_KIND::LEFT, 'A'));
		mSkillKey.insert(make_pair(SKILL_KIND::RIGHT, 'D'));
		mSkillKey.insert(make_pair(SKILL_KIND::DOWN, 'S'));
		mSkillKey.insert(make_pair(SKILL_KIND::UP, 'W'));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_NORMAL, 'H'));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_STRONG, 'J'));
		break;
	case PLAYER_TYPE::P2:
		// 2P
		// 방향키 // 숫자키패드 2 3
		mSkillKey.insert(make_pair(SKILL_KIND::LEFT, VK_LEFT));
		mSkillKey.insert(make_pair(SKILL_KIND::RIGHT, VK_RIGHT));
		mSkillKey.insert(make_pair(SKILL_KIND::DOWN, VK_DOWN));
		mSkillKey.insert(make_pair(SKILL_KIND::UP, VK_UP));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_NORMAL, VK_NUMPAD2));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_STRONG, VK_NUMPAD3));
		break;
	}

	mCommands.insert(make_pair(SKILL_KIND::LEFT, Command{ &skills[(int)SKILL_KIND::LEFT] }));
	mCommands.insert(make_pair(SKILL_KIND::RIGHT, Command{ &skills[(int)SKILL_KIND::RIGHT] }));
	mCommands.insert(make_pair(SKILL_KIND::DOWN, Command{ nullptr }));
	mCommands.insert(make_pair(SKILL_KIND::UP, Command{ nullptr }));
	mCommands.insert(make_pair(SKILL_KIND::ATTACK_NORMAL, Command{ &skills[(int)SKILL_KIND::ATTACK_NORMAL] }));
	mCommands.insert(make_pair(SKILL_KIND::ATTACK_STRONG, Command{ &skills[(int)SKILL_KIND::ATTACK_STRONG] }));

	// 아래키와 일반 공격을 누르면 원거리 공격으로
	mCommands[SKILL_KIND::DOWN].mCombo.insert(make_pair(SKILL_KIND::ATTACK_NORMAL, Command{ &skills[(int)SKILL_KIND::ATTACK_RANGE] }));
}

void Controller::CommandInput(SKILL_KIND kind)
{
	elapsedTime = 0;
	if (!lpmCommands)
	{
		// 현재 입력된 명령이 없음
		if (skills[(int)kind].lpfnCmd) skills[(int)kind].lpfnCmd(*lpCharacter);
		if (!mCommands[kind].mCombo.empty())
		{
			lpmCommands = &mCommands[kind].mCombo;
		}
	}
	else
	{
		if (lpmCommands->find(kind) != lpmCommands->end())
		{
			// 다음 콤보가 존재하면 스킬 실행
			if ((*lpmCommands)[kind].skill->lpfnCmd)
				(*lpmCommands)[kind].skill->lpfnCmd(*lpCharacter);

			if ((*lpmCommands)[kind].mCombo.empty())
			{
				lpmCommands = nullptr;
			}
		}
		else
		{
			if (skills[(int)kind].lpfnCmd) skills[(int)kind].lpfnCmd(*lpCharacter);
			if (!mCommands[kind].mCombo.empty())
			{
				lpmCommands = &mCommands[kind].mCombo;
			}
			else
			{
				lpmCommands = nullptr;
			}
		}
	}
}
