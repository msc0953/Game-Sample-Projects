#include "stdafx.h"

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
	: m_x(0), m_y(0), m_blocks(nullptr)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m_pos[i][j] = false;

	m_blocks = new Block[4];
}

BlockGroup::BlockGroup(int x, int y, int type)
	: m_x(x), m_y(y), m_type(type), m_blocks(nullptr)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			m_pos[i][j] = BlockIndex[type][i][j];

	m_blocks = new Block[4];
}

BlockGroup::~BlockGroup()
{
	if (m_blocks)
		delete m_blocks;
}

Block* BlockGroup::GetBlocks()
{
	int ix = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (m_pos[i][j])
			{
				m_blocks[ix] = Block(i, j);
				++ix;
			}
		}
	}

	return m_blocks;
}

void BlockGroup::MoveDown()
{
	m_y++;

	for (int i = 0; i < 4; i++)
	{
		m_blocks[i].MoveNext();
	}
}

BlockGroup& BlockGroup::operator=(const BlockGroup& src)
{
	m_x = src.m_x;
	m_y = src.m_y;
	
	m_type = src.m_type;

	for (int i = 0; i < 4; ++i)
		m_blocks[i] = src.m_blocks[i];
	
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