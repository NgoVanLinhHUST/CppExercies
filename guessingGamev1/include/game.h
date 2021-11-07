#pragma once
#include "computer.h"
#include "player.h"


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
