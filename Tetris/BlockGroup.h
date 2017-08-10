#pragma once

class Block;

class BlockGroup 
{
public:
	BlockGroup();
	BlockGroup(int xpos, int ypos, int type);
	BlockGroup& operator=(const BlockGroup& src);
	virtual ~BlockGroup();

public:
	Block* GetBlocks();
	void MoveDown();

private:
	void GetBlockGroupByType(int type);
	
private:
	bool  m_pos[4][4];

	Block* m_blocks;

	int m_x;
	int m_y;
	int m_type;
};

