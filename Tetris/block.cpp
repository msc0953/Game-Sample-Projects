#include "StdAfx.h"
#include "confing.h"
#include "block.h"


Block::Block(int x, int y) : m_x(x), m_y(y)
{

}

void Block::draw(HDC hdc)
{
	COLORREF InnerColor = Configure::BLOCKBoundColor;

	HBRUSH hBrush = CreateSolidBrush(InnerColor);
	SelectObject(hdc, hBrush);

	int left = Configure::BorderLeft + m_x * Configure::SmallestLength + 1;
	int top  = Configure::BorderTop  + m_y * Configure::SmallestLength + 1;

	Rectangle(hdc, left, top, left + Configure::SmallestLength, top + Configure::SmallestLength);

	DeleteObject(hBrush);
}