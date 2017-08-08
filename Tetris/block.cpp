#include "StdAfx.h"
#include "confing.h"
#include "block.h"


Block::Block(int x, int y) 
	: m_x(x), m_y(y)
{

}

Block& Block::operator=(const Block& src)
{
	m_x = src.m_x;
	m_y = src.m_y;

	return *this;
}

int Block::getPosX()
{
	return m_x;
}

int Block::getPosY()
{
	return m_y;
}

