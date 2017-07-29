#pragma once
#include "block.h"
#include "confing.h"


class BlockGroup 
{
public:
	BlockGroup();
	BlockGroup(int xpos, int ypos, int type);
	virtual ~BlockGroup();

public:
	void Draw(HDC hdc);
	
	BlockGroup& BlockGroup::operator = (const BlockGroup& src);

private:
	void GetBlockGroupByType(int type);
	void DrawBlock(HDC hdc);

private:
	bool  m_pos[4][4];

	Block m_block[4];

	int m_x;
	int m_y;
	int m_type;
};

