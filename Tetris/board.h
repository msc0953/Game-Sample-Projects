#ifndef __TETRIS_BOARDER_H__
#define __TETRIS_BOARDER_H__
#pragma once

class Boarder
{
public:
	Boarder(int width, int height);
	virtual ~Boarder() {};

private:
	int x;
	int y;

	int map[10][20];

public:
	void DrawBoarder(HDC hdc);
};

#endif