#include "StdAfx.h"
#include "board.h"
#include "confing.h"

Boarder::Boarder(int width, int height)
	: x(width /Configure::XBlockWidth), y(height/Configure::YBlockHeight)
{
	int x = width / Configure::XBlockWidth;
	int y = height / Configure::YBlockHeight;

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 20; ++j)
			map[i][j] = 0;
}

void Boarder::DrawBoarder(HDC hdc)
{
	HPEN hpen;
	HBRUSH hbrush;

	hpen = CreatePen(PS_SOLID, 0, Configure::FieldBoundColor);
	hbrush = CreateSolidBrush(Configure::FieldInnerColor);
	SelectObject(hdc, hpen);
	SelectObject(hdc, hbrush);

	hpen = CreatePen(PS_SOLID, 0, Configure::FieldBoundColor);

	for (int i = Configure::BorderLeft + Configure::XBlockWidth; i < Configure::BorderRight; i += Configure::SmallestLength)
	{
		MoveToEx(hdc, i, 0, NULL);
		LineTo(hdc, i, Configure::BorderBottom);
	}

	for (int j = Configure::BorderTop + Configure::YBlockHeight; j < Configure::BorderBottom; j += Configure::SmallestLength)
	{
		MoveToEx(hdc, Configure::BorderLeft, j, NULL);
		LineTo(hdc, Configure::BorderRight, j);
	}
	DeleteObject(hbrush);
	DeleteObject(hpen);
}