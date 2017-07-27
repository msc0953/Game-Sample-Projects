#pragma once
#include "block.h"
#include "confing.h"


class BlockGroup 
{
public:
	BlockGroup();
	virtual ~BlockGroup();

public:
	void Draw(HDC hdc);

private:
	void GetBlockGroupByType(int type);
	void DrawBlock(HDC hdc);

private:
	bool  m_pos[4][4];

	Block m_block[4];

	int m_x;
	int m_y;
};

