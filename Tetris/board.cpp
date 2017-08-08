#include "StdAfx.h"

Boarder::Boarder()
	: x(Configure::WindowWidth /Configure::XBlockWidth), y(Configure::WindowHeight /Configure::YBlockHeight)
{
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 20; ++j)
			map[i][j] = 0;
}

