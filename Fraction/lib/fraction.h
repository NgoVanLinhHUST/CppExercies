#pragma once
#include <iostream>
using namespace std;
class Fraction
{
    private:
        int num;
        int den;
    public:
        Fraction();
        Fraction(const int &n, const int &d);
        bool operator==(const Fraction &f) const;
        Fraction operator+(const Fraction &f) const;
        Fraction operator-(const Fraction &f) const;
        Fraction operator*(const Fraction &f) const;
        Fraction operator/(const Fraction &f) const;
        friend ostream& operator<<(ostream &os, const Fraction &f);
        friend istream& operator>>(istream &is, Fraction &f);
};