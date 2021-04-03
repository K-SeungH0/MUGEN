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
	if (lpCharacter && lpCharacter->IsAlive())
	{
		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::LEFT]))
		{
			CommandInput(SKILL_KIND::LEFT);
		}
		else if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::LEFT]))
		{
			if (skills[(int)SKILL_KIND::LEFT].lpfnCmd) skills[(int)SKILL_KIND::LEFT].lpfnCmd(*lpCharacter);
		}

		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::RIGHT]))
		{
			CommandInput(SKILL_KIND::RIGHT);
		}
		else if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::RIGHT]))
		{
			if (skills[(int)SKILL_KIND::RIGHT].lpfnCmd) skills[(int)SKILL_KIND::RIGHT].lpfnCmd(*lpCharacter);
		}

		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::DOWN]))
		{
			CommandInput(SKILL_KIND::DOWN);
		}
		else if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::DOWN]))
		{
			if (skills[(int)SKILL_KIND::DOWN].lpfnCmd) skills[(int)SKILL_KIND::DOWN].lpfnCmd(*lpCharacter);
		}

		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::UP]))
		{
			CommandInput(SKILL_KIND::UP);
		}
		else if (KeyManager::GetLpInstance()->IsStayKeyDown(mSkillKey[SKILL_KIND::UP]))
		{
			if (skills[(int)SKILL_KIND::UP].lpfnCmd) skills[(int)SKILL_KIND::UP].lpfnCmd(*lpCharacter);
		}

		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::ATTACK_WEAK]))
		{
			CommandInput(SKILL_KIND::ATTACK_WEAK);
		}
		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::ATTACK_STRONG]))
		{
			CommandInput(SKILL_KIND::ATTACK_STRONG);
		}
		if (KeyManager::GetLpInstance()->IsOnceKeyDown(mSkillKey[SKILL_KIND::ATTACK_KICK]))
		{
			CommandInput(SKILL_KIND::ATTACK_KICK);
		}
	}

	if (lpCharacter) lpCharacter->Update();
	

	if (elapsedTime++ > 50)
	{
		// 0.5�� ���� Ŀ�ǵ� �Է��� �ȵǾ��ٸ� ���� Ŀ�ǵ� �ʱ�ȭ
		elapsedTime = 0;
		lpmCommands = nullptr;
	}
}

void Controller::Render(HDC hdc)
{
	if (lpCharacter) lpCharacter->Render(hdc);
}

void Controller::SetController(PLAYER_TYPE type, Character* lpCharacter)
{
	this->type = type;
	this->lpCharacter = lpCharacter;
	this->lpCharacter->SetType(type);


	skills[(int)SKILL_KIND::LEFT].lpfnCmd = &Character::LeftMove;
	skills[(int)SKILL_KIND::RIGHT].lpfnCmd = &Character::RightMove;
	skills[(int)SKILL_KIND::ATTACK_WEAK].lpfnCmd = &Character::WeakAttack;
	skills[(int)SKILL_KIND::ATTACK_STRONG].lpfnCmd = &Character::StrongAttack;
	skills[(int)SKILL_KIND::ATTACK_KICK].lpfnCmd = &Character::KickAttack;
	skills[(int)SKILL_KIND::ATTACK_RANGE].lpfnCmd = &Character::RangeAttack;

	switch (type)
	{
	case PLAYER_TYPE::P1:
		// 1P �ʱ���ġ����
		this->lpCharacter->SetDirection(Character::DIRECTION::RIGHT);
		this->lpCharacter->SetPos({ 100, WINSIZE_HEIGHT - 100 });
		// W A S D // H J K
		mSkillKey.insert(make_pair(SKILL_KIND::LEFT, 'A'));
		mSkillKey.insert(make_pair(SKILL_KIND::RIGHT, 'D'));
		mSkillKey.insert(make_pair(SKILL_KIND::DOWN, 'S'));
		mSkillKey.insert(make_pair(SKILL_KIND::UP, 'W'));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_WEAK, 'H'));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_STRONG, 'J'));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_KICK, 'K'));
		break;
	case PLAYER_TYPE::P2:
		// 2P �ʱ���ġ ����
		this->lpCharacter->SetDirection(Character::DIRECTION::LEFT);
		this->lpCharacter->SetPos({ WINSIZE_WIDTH - 100, WINSIZE_HEIGHT - 100 });
		// ����Ű // ����Ű�е� 1 2 3
		mSkillKey.insert(make_pair(SKILL_KIND::LEFT, VK_LEFT));
		mSkillKey.insert(make_pair(SKILL_KIND::RIGHT, VK_RIGHT));
		mSkillKey.insert(make_pair(SKILL_KIND::DOWN, VK_DOWN));
		mSkillKey.insert(make_pair(SKILL_KIND::UP, VK_UP));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_WEAK, VK_NUMPAD1));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_STRONG, VK_NUMPAD2));
		mSkillKey.insert(make_pair(SKILL_KIND::ATTACK_KICK, VK_NUMPAD3));
		break;
	}

	mCommands.insert(make_pair(SKILL_KIND::LEFT, Command{ &skills[(int)SKILL_KIND::LEFT] }));
	mCommands.insert(make_pair(SKILL_KIND::RIGHT, Command{ &skills[(int)SKILL_KIND::RIGHT] }));
	mCommands.insert(make_pair(SKILL_KIND::DOWN, Command{ nullptr }));
	mCommands.insert(make_pair(SKILL_KIND::UP, Command{ nullptr }));
	mCommands.insert(make_pair(SKILL_KIND::ATTACK_WEAK, Command{ &skills[(int)SKILL_KIND::ATTACK_WEAK] }));
	mCommands.insert(make_pair(SKILL_KIND::ATTACK_STRONG, Command{ &skills[(int)SKILL_KIND::ATTACK_STRONG] }));

	// �Ʒ�Ű�� �Ϲ� ������ ������ ���Ÿ� ��������
	mCommands[SKILL_KIND::DOWN].mCombo.insert(make_pair(SKILL_KIND::ATTACK_WEAK, Command{ &skills[(int)SKILL_KIND::ATTACK_WEAK] }));
	mCommands[SKILL_KIND::DOWN].mCombo[SKILL_KIND::ATTACK_WEAK].mCombo.insert(make_pair(SKILL_KIND::ATTACK_WEAK, Command{ &skills[(int)SKILL_KIND::ATTACK_RANGE] }));
}

void Controller::CommandInput(SKILL_KIND kind)
{
	elapsedTime = 0;
	if (!lpmCommands)
	{
		// ���� �Էµ� ������ ����
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
			// ���� �޺��� �����ϸ� ��ų ����
			if ((*lpmCommands)[kind].skill->lpfnCmd)
				(*lpmCommands)[kind].skill->lpfnCmd(*lpCharacter);

			if (!(*lpmCommands)[kind].mCombo.empty())
			{
				lpmCommands = &(*lpmCommands)[kind].mCombo;
			}
			else
			{
				lpmCommands = nullptr;
			}
		}
		else
		{
			// �����޺��� �������� ������ �޺� �ʱ�ȭ
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