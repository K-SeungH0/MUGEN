#include "Image.h"

HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd);

	lpImageInfo = new IMAGE_INFO();
	lpImageInfo->resID = 0;
	lpImageInfo->hMemDC = CreateCompatibleDC(hdc);
	lpImageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	lpImageInfo->hOldBit = (HBITMAP)SelectObject(lpImageInfo->hMemDC, lpImageInfo->hBitmap);
	lpImageInfo->width = width;
	lpImageInfo->height = height;
	lpImageInfo->loadType = IMAGE_LOAD_TYPE::EMPTY;

	this->isTransparent = false;
	this->transColor = RGB(0, 0, 0);

	ReleaseDC(g_hWnd, hdc);

	if (lpImageInfo->hBitmap == NULL)
	{
		Release();
		return	E_FAIL;
	}
	
	return S_OK;
}

HRESULT Image::Init(string fileName, int width, int height, bool isTransparent, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd);

	lpImageInfo = new IMAGE_INFO();
	lpImageInfo->resID = 0;
	lpImageInfo->hMemDC = CreateCompatibleDC(hdc);
	lpImageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName.c_str(), IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	lpImageInfo->hOldBit = (HBITMAP)SelectObject(lpImageInfo->hMemDC, lpImageInfo->hBitmap);
	lpImageInfo->width = width;
	lpImageInfo->height = height;
	lpImageInfo->loadType = IMAGE_LOAD_TYPE::FILE;

	this->isTransparent = isTransparent;
	this->transColor = transColor;

	ReleaseDC(g_hWnd, hdc);

	if (lpImageInfo->hBitmap == NULL)
	{
		Release();
		return	E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(string fileName, int width, int height, int maxFrameX, int maxFrameY, int maxFrame, bool isTransparent, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd);

	lpImageInfo = new IMAGE_INFO();
	lpImageInfo->resID = 0;
	lpImageInfo->hMemDC = CreateCompatibleDC(hdc);
	lpImageInfo->hBitmap =
		(HBITMAP)LoadImage(g_hInstance, fileName.c_str(), IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	lpImageInfo->hOldBit =
		(HBITMAP)SelectObject(lpImageInfo->hMemDC, lpImageInfo->hBitmap);
	lpImageInfo->width = width / maxFrameX;
	lpImageInfo->height = height / maxFrameY;
	lpImageInfo->loadType = IMAGE_LOAD_TYPE::FILE;

	lpImageInfo->maxFrameX = maxFrameX;
	lpImageInfo->maxFrameY = maxFrameY;
	lpImageInfo->maxFrame = maxFrame;

	this->isTransparent = isTransparent;
	this->transColor = transColor;

	ReleaseDC(g_hWnd, hdc);

	if (lpImageInfo->hBitmap == NULL)
	{
		Release();
		return	E_FAIL;
	}

	return S_OK;
}

void Image::Render(HDC hdc, int destX, int destY)
{
	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,
			destX, destY,
			lpImageInfo->width, lpImageInfo->height,
			lpImageInfo->hMemDC,
			0, 0,
			lpImageInfo->width, lpImageInfo->height,
			transColor
		);
	}
	else
	{
		BitBlt(
			hdc,
			destX, destY,
			lpImageInfo->width,
			lpImageInfo->height,
			lpImageInfo->hMemDC,
			0, 0,
			SRCCOPY
		);
	}
}

void Image::Render(HDC hdc, int destX, int destY, int frameIndex)
{

	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,
			destX, destY,
			lpImageInfo->width, lpImageInfo->height,
			lpImageInfo->hMemDC,
			lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX),
			lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
			lpImageInfo->width, lpImageInfo->height,
			transColor
		);
	}
	else
	{
		BitBlt(
			hdc,
			destX, destY,
			lpImageInfo->width,
			lpImageInfo->height,
			lpImageInfo->hMemDC,
			lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX),
			lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
			SRCCOPY
		);
	}
}

void Image::Release()
{
	if (lpImageInfo)
	{
		SelectObject(lpImageInfo->hMemDC, lpImageInfo->hOldBit);
		DeleteObject(lpImageInfo->hBitmap);
		DeleteDC(lpImageInfo->hMemDC);

		delete lpImageInfo;
		lpImageInfo = nullptr;
	}
}