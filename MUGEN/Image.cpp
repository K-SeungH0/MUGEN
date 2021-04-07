#include "Image.h"

#pragma comment(lib, "msimg32.lib")
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

	lpImageInfo->maxFrameX = 1;
	lpImageInfo->maxFrameY = 1;
	lpImageInfo->maxFrame = 1;

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

	lpImageInfo->maxFrameX = 1;
	lpImageInfo->maxFrameY = 1;
	lpImageInfo->maxFrame = 1;

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

HRESULT Image::Reverse(string key)
{
	Image* targetImage = ImageManager::GetLpInstance()->GetImage(key);
	if (!targetImage || !targetImage->lpImageInfo)
	{
		return	E_FAIL;
	}

	IMAGE_INFO targetInfo = *targetImage->GetImageInfo();

	lpImageInfo = new IMAGE_INFO();
	lpImageInfo->resID = 0;
	lpImageInfo->hMemDC = CreateCompatibleDC(targetInfo.hMemDC);
	lpImageInfo->hBitmap = CreateCompatibleBitmap(targetInfo.hMemDC, targetInfo.width * targetInfo.maxFrameX, targetInfo.height * targetInfo.maxFrameY);
	lpImageInfo->hOldBit = (HBITMAP)SelectObject(lpImageInfo->hMemDC, lpImageInfo->hBitmap);
	lpImageInfo->width = targetInfo.width;
	lpImageInfo->height = targetInfo.height;
	lpImageInfo->loadType = IMAGE_LOAD_TYPE::FILE;

	lpImageInfo->maxFrameX = targetInfo.maxFrameX;
	lpImageInfo->maxFrameY = targetInfo.maxFrameY;
	lpImageInfo->maxFrame = targetInfo.maxFrame;

	this->isTransparent = targetImage->isTransparent;
	this->transColor = targetImage->transColor;

	HBRUSH hBrush = (HBRUSH)SelectObject(lpImageInfo->hMemDC, CreateSolidBrush(targetImage->transColor));
	PatBlt(lpImageInfo->hMemDC, 0, 0, targetInfo.width * targetInfo.maxFrameX, targetInfo.height * targetInfo.maxFrameY, PATCOPY);
	DeleteObject(SelectObject(lpImageInfo->hMemDC, hBrush));

	for (int y = 0; y < targetInfo.maxFrameY; ++y)
	{
		for (int x = 0; x < targetInfo.maxFrameX; ++x)
		{
			StretchBlt(lpImageInfo->hMemDC, (x + 1) * targetInfo.width, y * targetInfo.height, -targetInfo.width, targetInfo.height, targetInfo.hMemDC, x * targetInfo.width, y * targetInfo.height, targetInfo.width, targetInfo.height, SRCCOPY);
		}
	}

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

void Image::Render(HDC hdc, int destX, int destY, int frameIndex, int angle)
{
	lpImageInfo->currentFrame = frameIndex;
	if (angle != 0)
	{
		if (!tempDC)
		{
			tempSize = (int)sqrt(lpImageInfo->width * lpImageInfo->width + lpImageInfo->height * lpImageInfo->height);
			tempDC = CreateCompatibleDC(lpImageInfo->hMemDC);
			hBitmap = CreateCompatibleBitmap(lpImageInfo->hMemDC, tempSize, tempSize);
			hTempBrush = CreateSolidBrush(transColor);
			DeleteObject(SelectObject(tempDC, hBitmap));
			DeleteObject(SelectObject(tempDC, hTempBrush));
			PatBlt(tempDC, 0, 0, tempSize, tempSize, PATCOPY);
		}

		float radian = PI * angle / 180;
		xForm.eM11 = cosf(radian); xForm.eM12 = sinf(radian); xForm.eDx = (tempSize - cos(radian) * lpImageInfo->width + sin(radian) * lpImageInfo->height) / 2;
		xForm.eM21 = -sinf(radian); xForm.eM22 = cosf(radian); xForm.eDy = (tempSize - cos(radian) * lpImageInfo->height - sin(radian) * lpImageInfo->width) / 2;

		SetGraphicsMode(tempDC, GM_ADVANCED);
		GetWorldTransform(tempDC, &xOldForm);
		SetWorldTransform(tempDC, &xForm);

		StretchBlt(
			tempDC,
			0, 0,
			lpImageInfo->width,
			lpImageInfo->height,
			lpImageInfo->hMemDC,
			lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX),
			lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
			lpImageInfo->width,
			lpImageInfo->height,
			SRCCOPY
		);

		SetWorldTransform(tempDC, &xOldForm);

		if (isTransparent)
		{
			GdiTransparentBlt(
				hdc,
				destX + lpImageInfo->width / 2 - tempSize / 2, destY + lpImageInfo->height / 2 - tempSize / 2,
				tempSize, tempSize,
				tempDC,
				0, 0, tempSize, tempSize,
				transColor
			);
		}
		else
		{
			BitBlt(
				hdc,
				destX + lpImageInfo->width / 2 - tempSize / 2, destY + lpImageInfo->height / 2 - tempSize / 2,
				tempSize, tempSize,
				tempDC,
				0, 0,
				SRCCOPY
			);
		}

		SetGraphicsMode(hdc, GM_COMPATIBLE);
	}
	else
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
}

void Image::Render(HDC hdc, POINT offset, float widthRatio, float heightRatio, int frameIndex)
{
	lpImageInfo->currentFrame = frameIndex;
	if (isTransparent)
	{
		GdiTransparentBlt(hdc, (widthRatio <0)?(offset.x + (int)(lpImageInfo->width * widthRatio)):offset.x, offset.y, (int)(lpImageInfo->width * abs(widthRatio)), (int)(lpImageInfo->height * heightRatio),
			lpImageInfo->hMemDC, lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX), lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
			(int)(lpImageInfo->width * abs(widthRatio)), (int)(lpImageInfo->height * heightRatio), transColor);
	}
	else
	{
		StretchBlt(hdc, offset.x, offset.y, (int)(lpImageInfo->width * widthRatio), (int)(lpImageInfo->height * heightRatio),
			lpImageInfo->hMemDC, lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX), lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
			(int)(abs(widthRatio) * lpImageInfo->width), (int)(lpImageInfo->height * heightRatio), SRCCOPY);
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

	if (hBitmap) DeleteObject(hBitmap);
	if (tempDC) DeleteDC(tempDC);
	tempDC = NULL;
	hBitmap = NULL;
}

void Image::Render(int alpha, HDC hdc)
{
	BLENDFUNCTION bf;

	bf.AlphaFormat = 0;
	bf.BlendFlags = 0;
	bf.BlendOp = AC_SRC_OVER; 
	bf.SourceConstantAlpha = alpha;

	AlphaBlend(hdc, 0, 0, lpImageInfo->width, lpImageInfo->height, lpImageInfo->hMemDC, 0, 0, lpImageInfo->width, lpImageInfo->height, bf);
}
