#include "stdafx.h"

Render::Render()
{


}


void Render::DrawBoard(HDC hdc, Boarder* boarder)
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

void Render::DrawBlocks(HDC hdc, BlockGroup* blocks)
{
	Block* b = blocks->GetBlocks();
	for (int i = 0; i < 4; i++) 
	{
		DrawBlock(hdc, &b[i]);
	}
}

void Render::CleanBlocks(HDC hdc, BlockGroup* blocks)
{
	Block* b = blocks->GetBlocks();
	for (int i = 0; i < 4; i++)
	{
		CleanBlock(hdc, &b[i]);
	}
}

void Render::CleanBlock(HDC hdc, Block* block)
{
	COLORREF BoundColor = RGB(255, 0, 0);
	COLORREF InnerColor = RGB(255, 255, 255);

	HPEN hPen = CreatePen(PS_SOLID, 0, BoundColor);
	SelectObject(hdc, hPen);

	HBRUSH hBrush = CreateSolidBrush(InnerColor);
	SelectObject(hdc, hBrush);

	int left = Configure::BorderLeft + block->getPosX() * Configure::SmallestLength;
	int top = Configure::BorderTop + block->getPosY() * Configure::SmallestLength;

	Rectangle(hdc, left - 1, top - 1, left + Configure::SmallestLength + 1, top + Configure::SmallestLength + 1);

	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void Render::DrawBlock(HDC hdc, Block* block)
{
	COLORREF InnerColor = Configure::BLOCKBoundColor;

	HBRUSH hBrush = CreateSolidBrush(InnerColor);
	SelectObject(hdc, hBrush);

	int left = Configure::BorderLeft + block->getPosX() * Configure::SmallestLength + 1;
	int top = Configure::BorderTop + block->getPosY() * Configure::SmallestLength + 1;

	Rectangle(hdc, left, top, left + Configure::SmallestLength, top + Configure::SmallestLength);

	DeleteObject(hBrush);
}

