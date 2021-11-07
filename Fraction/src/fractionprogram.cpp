#include <iostream>
#include "lib/fractionprogram.h"

using namespace std;
#define EXIT 0
void FractionProgram::run() 
{
    bool testing = true;
    while (testing)
    {
        printMenu();
        int choice = getChoice();
        doTask(choice);
        //if (choice == EXIT) testing = false;
        testing = choice != EXIT;
    }
    
}
void FractionProgram::printMenu()
{
	cout << "\n\n\t\tDemo Fraction Operator" << endl;
	cout << "\n1. Enter 2 fraction." ;
	cout << "\n2. Test Sum." ;
	cout << "\n3. Test Sub." ;
	cout << "\n4. Test Mul." ;
	cout << "\n5. Test Div." ;
	cout << "\n0. Exit."	;
}

int FractionProgram::getChoice()
{
	cout << "\n Please Enter your choice: ";
	int choice ;
	cin >> choice;
	return choice;
}

void FractionProgram::doTask(const int& choice)
{
	switch (choice)
	{
	case 1:
		cout << " Enter fraction f1: (e.g: 2/3)" ;
		cin >> f1;
		cout << " Enter fraction f2: (e.g: 2/3)" ;
		cin >> f2;
		break;
	case 2:
		// Fraction f4 = f1 + f2;
		// cout << f1 << " + " << f2 << " = " << f4 << endl;
		// Fraction f3 = f1 +f2;
		// cout << f3;
		{
		Fraction f3 = f1+f2;
		cout << f3;
		break;

		}

	case 3:
		{
			Fraction f3 = f1-f2;
			cout << f3;
			break;
		}

	case 4:
		{
			Fraction f3 = f1*f2;
			cout << f3;
			break;
		}
	case 5:
		{
			Fraction f3 = f1/f2;
			cout << f3;
			break;
		}
	}
}
