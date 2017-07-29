#pragma once

class Block
{
private:
	int m_x;
	int m_y;

public:
	Block(int x=0, int y=0);

	int getPosX();
	int getPosY();
};