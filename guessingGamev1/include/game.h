#include "computer.h"
#include "player.h"
#pragma once

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
