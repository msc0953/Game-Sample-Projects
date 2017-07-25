#ifndef __TETRIS_BODER_H__
#define __TETRIS_BODER_H__
#pragma once

class Boarder
{
public:
	Boarder(int width, int height);
	virtual ~Boarder() {};

private:
	int x;
	int y;
	int xblock;
	int yblock;

	int map[10][20];

public:
	void DrawBoarder(HDC hdc);
};

#endif