#pragma once

class Boarder;
class Input;
class Render;

class GameCore
{
public:
	GameCore::GameCore();
	GameCore::~GameCore();

public:
	void Init();
	void Update();
	void HandleKeyDown(HDC hdc, WPARAM wParam);
	bool isRunning() { return true; }
	void Draw(HDC hdc);

private:
	BlockGroup* RandomBlocks();

private:
	Render* m_render;
	Input* m_input;

	Boarder* m_boarder;
	BlockGroup* m_previous;
	BlockGroup* m_current;
	bool m_Running;
};