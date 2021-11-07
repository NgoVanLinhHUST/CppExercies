#pragma once 
#include "player.h"
#include "computer.h"
class Game
{
	public:
		Player p;
		Computer c;
	public:
		Game();
		~Game();
		void start(const int &min,const int &max);
};
