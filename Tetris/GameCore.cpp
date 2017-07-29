#include "stdafx.h"


GameCore::GameCore(HWND hwnd)
	: m_hwnd(hwnd), m_previous(nullptr), m_current(nullptr), m_render(nullptr), m_boarder(nullptr)
{
	m_boarder = new Boarder();
	m_render = new Render(m_hwnd);
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
	
}

void GameCore::Update()
{
	
}

void GameCore::Draw()
{
	if (m_current == nullptr)
		m_current = RandomBlocks();

	m_render->Draw();
	//m_current->Draw(hdc);
}

BlockGroup* GameCore::RandomBlocks()
{
	srand(time_t(NULL));
	int randType = (int)(((double)rand() / (double)RAND_MAX)*(double)Configure::BlockGroupType);
	return new BlockGroup(Configure::XBlocks / 2 - 2, 0, randType);
}

