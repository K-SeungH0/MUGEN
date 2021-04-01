#include "Image.h"

HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd);

	imageInfo = new IMAGE_INFO();
	imageInfo->resID = 0;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = IMAGE_LOAD_TYPE::EMPTY;

	this->isTransparent = FALSE;
	this->transColor = FALSE;

	ReleaseDC(g_hWnd, hdc);

	if (imageInfo->hBitmap)
	{
		Release();
		return	E_FAIL;
	}
	
	return S_OK;
}

HRESULT Image::Init(string fileName, int width, int height, bool isTransparent, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd);

	imageInfo = new IMAGE_INFO();
	imageInfo->resID = 0;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName.c_str(), IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imageInfo->hOldBit = (HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = IMAGE_LOAD_TYPE::FILE;

	this->isTransparent = isTransparent;
	this->transColor = transColor;

	ReleaseDC(g_hWnd, hdc);

	if (imageInfo->hBitmap)
	{
		Release();
		return	E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(string fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd);

	imageInfo = new IMAGE_INFO();
	imageInfo->resID = 0;
	imageInfo->hMemDC = CreateCompatibleDC(hdc);
	imageInfo->hBitmap =
		(HBITMAP)LoadImage(g_hInstance, fileName.c_str(), IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDC, imageInfo->hBitmap);
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = IMAGE_LOAD_TYPE::FILE;

	imageInfo->maxFrameX = maxFrameX;
	imageInfo->maxFrameY = maxFrameY;
	imageInfo->frameWidth = width / maxFrameX;
	imageInfo->frameHeight = height / maxFrameY;
	imageInfo->currentFrameX = 0;
	imageInfo->currentFrameY = 0;

	this->isTransparent = FALSE;
	this->transColor = FALSE;

	ReleaseDC(g_hWnd, hdc);

	if (imageInfo->hBitmap)
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
			imageInfo->width, imageInfo->height,
			imageInfo->hMemDC,
			0, 0,
			imageInfo->width, imageInfo->height,
			transColor
		);
	}
	else
	{
		BitBlt(
			hdc,
			destX, destY,
			imageInfo->width,
			imageInfo->height,
			imageInfo->hMemDC,
			0, 0,
			SRCCOPY
		);
	}
}

void Image::Render(HDC hdc, int destX, int destY, int frameIndex)
{
	imageInfo->currentFrameX = frameIndex;

	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,
			destX, destY,
			imageInfo->frameWidth, imageInfo->frameHeight,
			imageInfo->hMemDC,
			imageInfo->frameWidth * imageInfo->currentFrameX,
			imageInfo->frameHeight * imageInfo->currentFrameY,
			imageInfo->frameWidth, imageInfo->frameHeight,
			transColor
		);
	}
	else
	{
		BitBlt(
			hdc,
			destX, destY,
			imageInfo->frameWidth,
			imageInfo->frameHeight,
			imageInfo->hMemDC,
			imageInfo->frameWidth * imageInfo->currentFrameX,
			imageInfo->frameHeight * imageInfo->currentFrameY,
			SRCCOPY
		);
	}
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDC, imageInfo->hOldBit);
		DeleteObject(imageInfo->hBitmap);
		DeleteDC(imageInfo->hMemDC);

		delete imageInfo;
		imageInfo = nullptr;
	}
}