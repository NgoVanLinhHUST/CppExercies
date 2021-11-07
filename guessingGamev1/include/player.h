#pragma once
class Player
{ 
	private:
		int nTry;
	public:
		Player();
		~Player();
		int guess();
		int getnTry();
		bool confirmPlay();
		void reset();
};
