#pragma once

#include "block.h"

class BlockGroup 
{
public:
	BlockGroup();
	BlockGroup(int xpos, int ypos, int type);
	virtual ~BlockGroup();

public:
	Block GetBlocks(int index);
	BlockGroup& BlockGroup::operator=(const BlockGroup& src);

private:
	void GetBlockGroupByType(int type);

private:
	bool  m_pos[4][4];

	Block m_block[4];

	int m_x;
	int m_y;
	int m_type;
};

