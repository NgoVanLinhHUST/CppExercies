#pragma once
#include "fraction.h"

class FractionProgram
{
    private:
        Fraction f1;
        Fraction f2;
    public:
        void run();
    private:
        void printMenu();
        int getChoice();
        void doTask(const int& choice);
};
