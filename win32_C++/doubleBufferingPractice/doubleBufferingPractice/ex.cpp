#include "stdafx.h"
#include <iostream>
#include <string>

void main(void) {

	static HDC hMemDC;
	HBITMAP hOldBitmap;
	int bx, by;

	HDC hMemDC2;
	HBITMAP hOldBitmap2;

	hMemDC = CreateCompatibleDC(hdc);

	if (hDoubleBufferImage == NULL)
		hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hDoubleBufferImage);

	{
		hMemDC2 = CreateCompatibleDC(hMemDC);

		hOldBitmap2 = (HBITMAP)SelectObject(hMemDC2, hBackImage);
		bx = bitBack.bmWidth;
		by = bitBack.bmHeight;


		//BitBlt(hMemDC, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY);
		TransparentBlt(hMemDC, 0, 0, bx, by, hMemDC2, 0, 0, bx / 2, by / 2, RGB(255, 0, 255));

		SelectObject(hMemDC2, hOldBitmap2);
	}

	BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, SRCCOPY);
	SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hMemDC);
	DeleteDC(hMemDC2);

}