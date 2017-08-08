#pragma once

class Render
{
public:
	Render::Render(HWND hwnd);

public:
	void DrawBoard(Boarder* boarder);
	void DrawBlocks(BlockGroup* blocks);

private:
	void DrawBlock(Block* block);

private:
	HWND m_hWnd;
};