#include "stdafx.h"


GameCore::GameCore()
	: m_previous(nullptr), m_current(nullptr), m_render(nullptr), m_boarder(nullptr)
{
	m_boarder = new Boarder(Configure::WindowWidth, Configure::WindowHeight);
}

GameCore::~GameCore()
{
	if (m_current)
		delete m_current;

	if (m_previous)
		delete m_previous;

	if (m_render)
		delete m_render;

	if (m_boarder)
		delete m_boarder;
}


void GameCore::Init()
{
	m_current = RandomBlocks();
}

void GameCore::Update()
{
	
}

void GameCore::draw(HDC hdc)
{
	m_boarder->DrawBoarder(hdc);
	m_current->Draw(hdc);
}

BlockGroup* GameCore::RandomBlocks()
{
	int randType = (int)(((double)rand() / (double)RAND_MAX)*(double)Configure::BlockGroupType);
	return new BlockGroup(Configure::XBlocks / 2 - 2, 0, randType);
}

