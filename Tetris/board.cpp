#include "StdAfx.h"
#include "board.h"
#include "confing.h"

Boarder::Boarder(int width, int height)
	: x(width /Configure::XBlockWidth), y(height/Configure::YBlockHeight)
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 20; ++j)
			map[i][j] = 0;
}

void Boarder::DrawBoarder(HDC hdc)
{
	HPEN hpen;

	hpen = CreatePen(PS_SOLID, 0, Configure::FieldBoundColor);

	SelectObject(hdc, hpen);

	for (int i = Configure::BorderLeft; i <= Configure::BorderRight; i += Configure::SmallestLength)
	{
		MoveToEx(hdc, i, 0, NULL);
		LineTo(hdc, i, Configure::BorderBottom);
	}

	for (int j = Configure::BorderTop; j <= Configure::BorderBottom; j += Configure::SmallestLength)
	{
		MoveToEx(hdc, Configure::BorderLeft, j, NULL);
		LineTo(hdc, Configure::BorderRight, j);
	}

	DeleteObject(hpen);	
}