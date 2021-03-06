#pragma once

class Render
{
public:
	Render::Render();

public:
	void DrawBoard(HDC hdc, Boarder* boarder);
	void DrawBlocks(HDC hdc, BlockGroup* blocks);
	void CleanBlocks(HDC hdc, BlockGroup* blocks);

private:
	void DrawBlock(HDC hdc, Block* block);
	void CleanBlock(HDC hdc, Block* block);
};