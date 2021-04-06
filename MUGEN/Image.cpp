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
	lpImageInfo->currentFrame = frameIndex;
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

//void Image::Render(HDC hdc, int angle, int destX, int destY, int frameIndex)
//{
//	int size = (int)sqrt(lpImageInfo->width * lpImageInfo->width + lpImageInfo->height * lpImageInfo->height);
//	if (!tempDC)
//	{
//		tempDC = CreateCompatibleDC(lpImageInfo->hMemDC);
//		hBitmap = CreateCompatibleBitmap(lpImageInfo->hMemDC, size, size);
//		hOldBitmap = (HBITMAP)SelectObject(tempDC, hBitmap);
//		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
//		DeleteObject(SelectObject(tempDC, hBrush));
//		PatBlt(tempDC, 0, 0, size, size, PATCOPY);
//	}
//	SetGraphicsMode(tempDC, GM_ADVANCED);
//
//	XFORM xForm, oldXForm;
//	GetWorldTransform(tempDC, &oldXForm);
//	POINT p = { (size - lpImageInfo->width) / 2, (size - lpImageInfo->height) / 2 };
//	float radian = PI * angle / 180;
//	xForm.eM11 = cosf(radian); xForm.eM12 = sinf(radian); xForm.eDx = (size - cos(radian) * lpImageInfo->width + sin(radian) * lpImageInfo->height) / 2;
//	xForm.eM21 = -sinf(radian); xForm.eM22 = cosf(radian); xForm.eDy = (size - cos(radian) * lpImageInfo->height - sin(radian) * lpImageInfo->width) / 2;
//	SetWorldTransform(tempDC, &xForm);
//	
//	StretchBlt(
//		tempDC,
//		0, 0,
//		lpImageInfo->width,
//		lpImageInfo->height,
//		lpImageInfo->hMemDC,
//		lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX),
//		lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
//		lpImageInfo->width,
//		lpImageInfo->height,
//		SRCCOPY
//	);
//
//	SetWorldTransform(tempDC, &oldXForm);
//
//	//GdiTransparentBlt(
//	//	hdc,
//	//	destX + lpImageInfo->width / 2 - size / 2, destY + lpImageInfo->height / 2 - size / 2,
//	//	size, size,
//	//	tempDC,
//	//	0, 0, size, size,
//	//	transColor
//	//);
//
//	BitBlt(
//		hdc,
//		destX + lpImageInfo->width / 2 - size / 2, destY + lpImageInfo->height / 2 - size / 2,
//		size, size,
//		tempDC,
//		0, 0,
//		SRCCOPY
//	);
//	
//	SetGraphicsMode(hdc, GM_COMPATIBLE);
//}
//
//void Image::Render(HDC hdc, bool flip, int destX, int destY, int frameIndex)
//{
//	StretchBlt(
//		hdc,
//		destX + lpImageInfo->width, destY,
//		-lpImageInfo->width,
//		lpImageInfo->height,
//		lpImageInfo->hMemDC,
//		lpImageInfo->width * (frameIndex % lpImageInfo->maxFrameX),
//		lpImageInfo->height * (frameIndex / lpImageInfo->maxFrameX),
//		lpImageInfo->width,
//		lpImageInfo->height,
//		SRCCOPY
//	);
//}

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

	if (hBitmap) DeleteObject(SelectObject(tempDC, hOldBitmap));
	if (tempDC) DeleteDC(tempDC);
}