#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Computer
{
	public:
		int number;
	public:
		Computer();
		~Computer();
		void random(const int &min ,const int &max);
		int getNumber() const;
		int compare(int guess) const;
};

class Player
{ 
	public:
		int nTry;
		int point;
		int money;
	public:
		Player();
		~Player();
		int guess();
		int  getnTry();
		bool confirmPlay();
		void reset();
		int cashIn();
		bool checkPoint();
		int decreasePoint();
		void showPointMoney();
		void shownTry();
};


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

Computer::Computer(){}
Computer::~Computer(){}

Player::Player(){}
Player::~Player(){}

Game::Game(){}
Game::~Game(){}
void Computer::random(const int &min, const int &max)
{
	srand(time(NULL));
	number = rand()%max + 1;
}

int Computer::getNumber() const 
{
	// cout << number << endl;
	return number;
}
int Computer::compare(int guess) const
{
	if( number > guess)
	{
		cout << "\nyour number is less than my number";
		return 1;
	}

	else if (number < guess)
	{
		cout << "\nYour number is greater than my number";
		return 2;
	}

	else if(number == guess )
	{
		cout << " CORRECT ";
		return 0;
	}
}

int Player::guess()
{
	int guess;
	cout << "\nEnter a random number: "  ;	
	cin >> guess;
	return guess;
}

void Player::showPointMoney()
{
	point+=5;
	cout << "Your Point : " << point ;
	cout << "\nYour Money : " << point*1000 ;
}
int Player::decreasePoint()
{
	return point--;
}
int  Player::getnTry()
{
	return nTry++;
}

bool Player::confirmPlay()
{
	char conf;
	cout << "\n\nDo you want to continue? 1-y 2-n";
	cin >> conf;
	if (conf =='1')
	{
		return 0;
	}
	else if ( conf == '2')
	{
		cout << "Game Over. Your Point : " << point;
		cout << "\nYour Money : " << point*1000 ;
		return 1;
	}
}
void Player::shownTry()
{
	cout << "\nNumber of guess :" << nTry;
}
void Player::reset()
{
	nTry = 0;
}
int Player::cashIn()
{
	cout << "\n\tEnter money your cash in : ( 1000vnd = 1 point) ";
	cin >> money;
	return point = money/1000;
}
bool Player::checkPoint()
{
	if (point <= 0)
    {
        cout << "\nYour point is 0. Do you want to cash in? 1-yes 2-no";
        char cash;
        cin >> cash;
        if (cash == '1')
        {
            point = cashIn();
			reset();
			return true;
        }
        if (cash == '2')
        {
            cout << "GAMEOVER";
            return false;
        }
    }
	else 
		return 1;

}
void Game::start( const int &min,const int &max)
{
	p.cashIn();
	c.random(min,max);
	c.getNumber();
	bool gameOver = false;
	while(gameOver == 0 )
	{
		int numberGuess = p.guess();
		int check = c.compare(numberGuess);
		if(check == 1 || check == 2)
		{
			p.getnTry();
			p.decreasePoint();
			if (p.checkPoint()==0)
			{
				gameOver = 1;
			}
		}
		else if ( check == 0)
		{
			
			p.shownTry();
			p.showPointMoney();
			p.reset();
			gameOver = p.confirmPlay();
			if(gameOver == 0)
			{
				c.random(min,max);
				c.getNumber();
			}
		}
		
	}
}


int main(int argc, char *argv[])
{	 
	Game game;
	game.start(0,50);
}