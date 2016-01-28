#include "stdafx.h"
#include "ProcessArtificialIntelligence.h"
#include <thread>
#include <iostream>

ProcessArtificialIntelligence::ProcessArtificialIntelligence()
{

}

ProcessArtificialIntelligence::ProcessArtificialIntelligence(Enemy pEnemy)
{
	enemy = &pEnemy;
}

int ProcessArtificialIntelligence::run(void * data)
{
	/*Enemy* enemy = (Enemy*)data;
	std::string myString = enemy->GetString();

	unsigned int result = 0;
	cout << "Process Artificial Intelligence Running" << endl;

	Uint32 update, elapsed = 0;
	update = 1000;
	
	while (true)
	{
		elapsed = SDL_GetTicks();

		if (elapsed >= update)
		{
			if (SDL_mutexP(m_mutex) == -1)
			{
				cout << "Process Artificial Intelligence Spinning" << endl;
			}
			cout << "Process Artificial Intelligence Locked Mutex" << endl;
			result = ai.update(data);

			if (SDL_mutexV(m_mutex) == -1)
			{
				cout << "Unlock failed Spinning" << endl;
			}
			cout << "Process Artificial Intelligence Unlocked Mutex" << endl;
			elapsed = 0;
		}
	}
	return result;*/

	return 1;
}
