#include "stdafx.h"

Render::Render(HWND hWnd)
	: m_hWnd(hWnd)
{


}


void Render::DrawBoard(Boarder* boarder)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(m_hWnd, &ps);

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

	EndPaint(m_hWnd, &ps);
}

void Render::DrawBlocks(BlockGroup* blocks)
{
	for (int i = 0; i < 4; i++)
		DrawBlock(&blocks->GetBlocks(i));
}

void Render::DrawBlock(Block* block)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(m_hWnd, &ps);

	COLORREF InnerColor = Configure::BLOCKBoundColor;

	HBRUSH hBrush = CreateSolidBrush(InnerColor);
	SelectObject(hdc, hBrush);

	int left = Configure::BorderLeft + block->getPosX() * Configure::SmallestLength + 1;
	int top = Configure::BorderTop + block->getPosY() * Configure::SmallestLength + 1;

	Rectangle(hdc, left, top, left + Configure::SmallestLength, top + Configure::SmallestLength);

	DeleteObject(hBrush);

	EndPaint(m_hWnd, &ps);
}

