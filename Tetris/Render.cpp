#include "stdafx.h"

Render::Render(HWND hWnd)
	: m_hWnd(hWnd)
{


}

void Render::DrawBoard()
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

void Render::Draw()
{
	this->DrawBoard();
}

