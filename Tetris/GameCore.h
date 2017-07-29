#pragma once

class Boarder;
class Input;
class Render;

class GameCore
{
public:
	GameCore::GameCore(HWND hwnd);
	GameCore::~GameCore();

public:
	void Init();
	void Update();
	void HandleKeyDown(WPARAM wParam) {}
	bool isRunning() { return true; }
	void Draw();

private:
	BlockGroup* RandomBlocks();

private:
	HWND m_hwnd;

	Render* m_render;
	Input* m_input;

	Boarder* m_boarder;
	BlockGroup* m_previous;
	BlockGroup* m_current;
	bool m_Running;
};