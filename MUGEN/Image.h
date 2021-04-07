#pragma once
#include "Mugen.h"

class Image
{
public:
	enum class IMAGE_LOAD_TYPE 
	{
		RESOURCE,
		FILE,
		EMPTY,
		NONE
	};

	typedef struct tagImageInfo
	{
		IMAGE_LOAD_TYPE loadType;
		DWORD resID;
		HDC hMemDC;
		int width;
		int height;
		int maxFrameX;
		int maxFrameY;
		int maxFrame;
		int currentFrame;
		HBITMAP hBitmap;
		HBITMAP hOldBit;

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = IMAGE_LOAD_TYPE::NONE;

			maxFrameX = 0;
			maxFrameY = 0;
			maxFrame = 0;
			currentFrame = 0;
		};
	}	IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO lpImageInfo;
	bool isTransparent;
	COLORREF transColor;
	int elapsedTime;

	// 이미지 회전 처리할때 사용할 변수들
	int tempSize;
	HDC tempDC = NULL;
	HBITMAP hBitmap = NULL;
	HBRUSH hTempBrush = NULL;
	XFORM xForm, xOldForm;
public:
	HRESULT Init(int width, int height);
	HRESULT Init(string fileName, int width, int height, bool isTransparent = false, COLORREF transColor = RGB(0, 0, 0));
	HRESULT Init(string fileName, int width, int height, int maxFrameX, int maxFrameY, int maxFrame, bool isTransparent = false, COLORREF transColor = RGB(0, 0, 0));

	HRESULT Reverse(string key);

	void Render(HDC hdc, int destX = 0, int destY = 0);
	void Render(HDC hdc, int destX, int destY, int frameIndex, int angle = 0);
	void Render(HDC hdc, POINT offset, float widthRatio, float heightRatio, int frameIndex = 0);

	HDC Render(int alpha, HDC hdc, HDC lastHdc);

	void Release();

	inline LPIMAGE_INFO GetImageInfo() { return this->lpImageInfo; }

	inline HDC GetMemDC()
	{
		if (this->lpImageInfo) return this->lpImageInfo->hMemDC;
		return NULL;
	}
};

