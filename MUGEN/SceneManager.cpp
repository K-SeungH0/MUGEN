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
	alpha = 0;
	isLoading = false;
	
	lpBuffer = new Image();
	lpBuffer->Init(WINSIZE_WIDTH, WINSIZE_HEIGHT);

	lpLoadingImage = new Image();
	lpLoadingImage = ImageManager::GetLpInstance()->GetImage("LOADING");
	
	currentScene = SCENE_STATE::TITLE;
	LoadScene(SCENE_STATE::TITLE, NULL);
    return S_OK;
}

void SceneManager::Release()
{
	for (int i = 0; i < (int)SCENE_STATE::NONE; i++)
	{
		delete scenes[i];
	}
	delete lpLoadingImage;
}

void SceneManager::Update()
{
	if(!isLoading)
		scenes[(int)currentScene]->Update();
	else
	{
		alpha += 10;
		if (alpha >= 250)
		{
			isLoading = false;
			alpha = 0;
		}
	}
}

void SceneManager::Render(HDC hdc)
{
	if (!isLoading)
		scenes[(int)currentScene]->Render(hdc);
	else
	{
		lastHdc = lpLoadingImage->Render(alpha, hdc, lastHdc);
	}
}

void SceneManager::LoadScene(SCENE_STATE loadScene, HDC lastHdc)
{
	if (loadScene == SCENE_STATE::TITLE)
	{
		GameData::GetLpInstance()->GameReset();
	}
	this->lastHdc = lastHdc;
	this->currentScene = loadScene;
	if(lastHdc)
	this->isLoading = true;
	scenes[(int)currentScene]->Init();
}