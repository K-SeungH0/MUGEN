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
		};
	}	IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO lpImageInfo;
	bool isTransparent;
	COLORREF transColor;

public:
	HRESULT Init(int width, int height);
	HRESULT Init(string fileName, int width, int height, bool isTransparent = false, COLORREF transColor = RGB(0, 0, 0));
	HRESULT Init(string fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent = false, COLORREF transColor = RGB(0, 0, 0));

	void Render(HDC hdc, int destX = 0, int destY = 0);
	void Render(HDC hdc, int destX, int destY, int frameIndex);

	void Release();

	inline HDC GetMemDC()
	{
		if (this->lpImageInfo) return this->lpImageInfo->hMemDC;
		return NULL;
	}
};

