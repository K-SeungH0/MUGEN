#include "Ingame.h"
#include "Image.h"

Ingame::Ingame()
{
}

Ingame::~Ingame()
{
}

HRESULT Ingame::Init()
{
	lpHP1UIImg = new Image();
	if (FAILED(lpHP1UIImg->Init("Image/UI/Player/1P_UI.bmp", 701 , 324)))
	{
		MessageBox(g_hWnd, "HP로드 실패", "Error", MB_OK);
	}
	lpHP2UIImg = new Image();
	if (FAILED(lpHP2UIImg->Init("Image/UI/Player/1P_UI.bmp", 701, 324)))
	{
		MessageBox(g_hWnd, "HP로드 실패", "Error", MB_OK);
	}
	lpHP1Img = new Image();
	if (FAILED(lpHP1Img->Init("Image/UI/Player/HP.bmp", 100 * lpPlayer1->GetLpCharacter()->GetHp() / MAX_HP, 20)))
	{
		MessageBox(g_hWnd, "HP로드 실패", "Error", MB_OK);
	}
	lpHP2Img = new Image();
	if (FAILED(lpHP2Img->Init("Image/UI/Player/HP.bmp", 100 * lpPlayer2->GetLpCharacter()->GetHp() / MAX_HP, 20)))
	{
		MessageBox(g_hWnd, "HP로드 실패", "Error", MB_OK);
	}
	lpDelayHP1Img = new Image();
	if (FAILED(lpDelayHP1Img->Init("Image/UI/Player/Delay_HP.bmp", 100 * lpPlayer1->GetLpCharacter()->GetHp() / MAX_HP, 20)))
	{
		MessageBox(g_hWnd, "HPdelay로드 실패", "Error", MB_OK);
	}
	lpDelayHP2Img = new Image();
	if (FAILED(lpDelayHP2Img->Init("Image/UI/Player/Delay_HP.bmp", 100 * lpPlayer2->GetLpCharacter()->GetHp() / MAX_HP, 20)))
	{
		MessageBox(g_hWnd, "HPdelay로드 실패", "Error", MB_OK);
	}

	return S_OK;
}

void Ingame::Release()
{
}

void Ingame::Update()
{
}

void Ingame::Render(HDC hdc)
{
	HDC hBackDC = lpBuffer->GetMemDC();
	lpHP1UIImg->Render(hBackDC);
	lpHP2UIImg->Render(hBackDC);
	lpHP1Img->Render(hBackDC);
	lpHP2Img->Render(hBackDC);
	lpDelayHP1Img->Render(hBackDC);
	lpDelayHP2Img->Render(hBackDC);
}
