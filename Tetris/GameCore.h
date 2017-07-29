#pragma once

class Boarder;
class Input;

class GameCore
{
public:
	GameCore::GameCore();

public:
	void update() {}
	void HandleKeyDown(WPARAM wParam) {}
	bool isRunning() { return true; }

private:
	Boarder* boarder;
	Input* input;
};