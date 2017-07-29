#pragma once

class Boarder
{
public:
	Boarder();
	virtual ~Boarder() {};

private:
	int x;
	int y;

	int map[10][20];

public:
};