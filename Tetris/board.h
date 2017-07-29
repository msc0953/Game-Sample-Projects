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