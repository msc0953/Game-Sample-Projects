#pragma once

class Block
{
private:
	int m_x;
	int m_y;

public:
	Block();
	Block(int x, int y);
	Block(const Block& b);
	Block& operator=(const Block& src);

	int getPosX();
	int getPosY();
	
	void MoveNext();
};