#pragma once

class Boarder;

class Render
{
public:
	Render::Render(HDC hdc) {}

public:
	void DrawBoard(Boarder* boarder);
};