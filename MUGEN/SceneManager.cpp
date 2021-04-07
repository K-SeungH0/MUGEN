#include "SceneManager.h"
#include "Mugen.h"
#include "Image.h"
#include "Title.h"
#include "INGAME.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

HRESULT SceneManager::Init()
{
	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpBgImg = new Image();
	if (FAILED(lpBgImg->Init("Image/UI/Battle/bgImage.bmp", WINSIZE_WIDTH, WINSIZE_HEIGHT)))
	{
		MessageBox(g_hWnd, "배경 로드 실패", "Error", MB_OK);
	}

	for (int i = 0; i < (int)SCENE_STATE::NONE; i++)
	{
		switch (i)
		{
		case (int)SCENE_STATE::TITLE:
			scenes[i] = new Title();
			break;
		case (int)SCENE_STATE::INGAME:
			scenes[i] = new InGame();
			break;
		}
	}
	currentScene = SCENE_STATE::TITLE;
	LoadScene(SCENE_STATE::TITLE);
    return S_OK;
}

void SceneManager::Update()
{
	scenes[(int)currentScene]->Update();
}

void SceneManager::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();
	scenes[(int)currentScene]->Render(hBackDC);
	lpBuffer->Render(hdc);
}

void SceneManager::LoadScene(SCENE_STATE loadScene)
{
	if (loadScene == SCENE_STATE::TITLE)
	{
		GameData::GetLpInstance()->GameReset();
	}
	currentScene = loadScene;
	scenes[(int)currentScene]->Init();
}