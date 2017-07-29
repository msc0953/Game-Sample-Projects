#include "StdAfx.h"
#include "confing.h"
#include "block.h"


Block::Block(int x, int y) 
	: m_x(x), m_y(y)
{

}

int Block::getPosX()
{
	return m_x;
}

int Block::getPosY()
{
	return m_y;
}

