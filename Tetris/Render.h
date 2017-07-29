#pragma once

class Boarder;

class Render
{
public:
	Render::Render(HWND hwnd);

private:
	void DrawBoard();

public:
	void Draw();

private:
	HWND m_hWnd;
};