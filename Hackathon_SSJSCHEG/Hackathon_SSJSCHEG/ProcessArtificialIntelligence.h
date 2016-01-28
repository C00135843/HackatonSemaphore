#pragma once
#ifndef PROCESSARTIFICIALINTELLIGENCE_H
#define PROCESSARTIFICIALINTELLIGENCE_H

#include "Enemy.h"

class ProcessArtificialIntelligence
{
public:
	ProcessArtificialIntelligence();
	ProcessArtificialIntelligence(Enemy pEnemy);

	static int run(void* data);
private:
	//static SDL_mutex* m_mutex;

	Enemy * enemy;
};

#endif
