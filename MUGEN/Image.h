#pragma once
#include "config.h"

class Image
{
public:
	enum class IMAGE_LOAD_TYPE 
	{
		RESOURCE,
		FILE,
		EMPTY,
		END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBitmap;
		HBITMAP hOldBit;
		int width;
		int height;
		IMAGE_LOAD_TYPE loadType;

		int maxFrameX;
		int maxFrameY;
		int frameWidth;
		int frameHeight;
		int currentFrameX;
		int currentFrameY;

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = IMAGE_LOAD_TYPE::EMPTY;

			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			currentFrameX = 0;
			currentFrameY = 0;
		};
	}	IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO imageInfo;
	bool isTransparent;
	COLORREF transColor;

public:
	HRESULT Init(int width, int height);
	HRESULT Init(string fileName, int width, int height, bool isTransparent = FALSE, COLORREF transColor = FALSE);
	HRESULT Init(string fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent = FALSE, COLORREF transColor = FALSE);

	void Render(HDC hdc, int destX = 0, int destY = 0);
	void Render(HDC hdc, int destX, int destY, int frameIndex);

	void Release();

	HDC GetMemDC()
	{
		if (this->imageInfo)
			return this->imageInfo->hMemDC;
		return NULL;
	}
};

