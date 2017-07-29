#include "stdafx.h"
#include "BlockGroup.h"

static const bool BlockIndex[Configure::BlockGroupType][4][4] =
{
	{ { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } },
	{ { 0,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } },
	{ { 0,0,0,0 },{ 0,1,0,0 },{ 0,1,1,1 },{ 0,0,0,0 } },
	{ { 0,0,1,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } },
	{ { 0,0,0,0 },{ 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 } },
	{ { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 } },
	{ { 0,1,0,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } },
	{ { 1,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,0,1,0 },{ 0,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 } },
	{ { 0,0,0,0 },{ 0,1,1,1 },{ 0,0,1,0 },{ 0,0,0,0 } },
	{ { 0,0,1,0 },{ 0,0,1,1 },{ 0,0,1,0 },{ 0,0,0,0 } },
	{ { 0,0,1,0 },{ 0,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } }
};

BlockGroup::BlockGroup()
	: m_x(0), m_y(0)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m_pos[i][j] = false;
}

BlockGroup::BlockGroup(int x, int y, int type)
	: m_x(x), m_y(y), m_type(type)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m_pos[i][j] = BlockIndex[type][i][j];
}

BlockGroup::~BlockGroup()
{

}

Block BlockGroup::GetBlocks(int index)
{
	int ix = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (m_pos[i][j])
			{
				m_block[index] = Block(i, j);
				++ix;
			}
		}
	}

	return m_block[ix];
}

BlockGroup& BlockGroup::operator = (const BlockGroup& src)
{
	m_x = src.m_x;
	m_y = src.m_y;
	
	m_type = src.m_type;

	for (int i = 0; i < 4; ++i)
		m_block[i] = src.m_block[i];
	
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m_pos[i][j] = src.m_pos[i][j];

	return *this;
}

void BlockGroup::GetBlockGroupByType(int type)
{
	m_type = type;

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j<4; ++j)
			m_pos[i][j] = BlockIndex[type][i][j];
}