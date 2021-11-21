#include <iostream>
#include "employee.h"

using namespace std;
#define BASICSALARY 500
Employee::Employee()
{
    ID = 0;
    name = "No name";
    telephone = 0;
    age = 0;
    rate = 0;
}
Employee::~Employee() {}
Employee::Employee(const int &ID)
{
    this->ID = ID;
}
int Employee::getAge()
{
    return this->age;
}
int Employee::getPhone()
{
    return this->telephone;
}
double Employee::getRate()
{
    return this->rate;
}
string Employee::getName()
{
    return this->name;
}
int Employee::getID()
{
    return this->ID;
}

string Employee::toString()
{
    // // string s = (this->ID).str();
    // return  to_string(this->ID) + "|" + this->name + "|" + to_string(this->telephone) 
    //         + "|" + to_string(this->age) + "|" + to_string(this->rate);
    // // string s ="ID: " + to_string(this->ID) + "\n Name: " + this->name + "\n Phone: " + to_string(this->telephone) 
    // //     + "\n Age: " + to_string(this->age) + "\n Rate: " + to_string(this->rate) + "\n";
    // //     return s;
}
string FulltimeEmployee::toString()
{
    return   to_string(this->ID) + "|" + this->name + "|" + to_string(this->telephone) 
            + "|" + to_string(this->age) + "|" + to_string(this->rate) + "|fulltime|\n";
}
string ParttimeEmployee::toString()
{
    return   to_string(this->ID) + "|" + this->name + "|" + to_string(this->telephone) 
            + "|" + to_string(this->age) + "|" + to_string(this->rate) + "|parttime|\n";
}
string HourlyEmployee::toString()
{
    return   to_string(this->ID) + "|" + this->name + "|" + to_string(this->telephone) 
            + "|" + to_string(this->age) + "|" + to_string(this->rate) + "|hourly" + "|" + to_string(this->nHours) + "|\n";
}
ostream &operator<<(ostream &os, const Employee &e)
{
    e.print(os);
    return os;
}

void Employee::print(ostream &os) const
{
    os << "\nID: " << ID << "\nName: " << name << "\nAge :" << age
       << "\nTelephone: " << telephone << "\nSalary: " << calculateSalary();
}

FulltimeEmployee::FulltimeEmployee()
{
    ID = 0;
    name = "No name";
    telephone = 0;
    age = 0;
    rate = 0;
}
FulltimeEmployee::FulltimeEmployee(const int &ID, const string &name, const int &telephone, const int &age, const double &rate)
{
    this->ID = ID;
    this->name = name;
    this->telephone = telephone;
    this->age = age;
    this->rate = rate;
}
double FulltimeEmployee::calculateSalary() const
{
    int bonus;
    if (rate > 0 && rate <= 4)
    {
        bonus = 50;
    }
    else if (rate > 4 && rate < 7)
    {
        bonus = 100;
    }
    else if (rate > 7 && rate <= 10)
    {
        bonus = 200;
    }


    return BASICSALARY * rate + bonus;
}
ostream &operator<<(ostream &os, const FulltimeEmployee &f)
{
    f.print(os);
    return os;
}
ParttimeEmployee::ParttimeEmployee()
{
    ID = 0;
    name = "No name";
    telephone = 0;
    age = 0;
    rate = 0;
}

ParttimeEmployee::ParttimeEmployee(const int &ID, const string &name, const int &telephone, const int &age, const double &rate)
{
    this->ID = ID;
    this->name = name;
    this->telephone = telephone;
    this->age = age;
    this->rate = rate;
}
double ParttimeEmployee::calculateSalary() const
{

    return 0.5 * BASICSALARY * rate;
}
ostream &operator<<(ostream &os, const ParttimeEmployee &p)
{
    p.print(os);
    return os;
}

HourlyEmployee::HourlyEmployee()
{
    ID = 0;
    name = "No name";
    telephone = 0;
    age = 0;
    rate = 0;
    nHours = 0;
}
HourlyEmployee::HourlyEmployee(const int &ID, const string &name, const int &telephone, const int &age, const double &rate, const int &nHours)
{
    this->ID = ID;
    this->name = name;
    this->telephone = telephone;
    this->age = age;
    this->rate = rate;
    this->nHours = nHours;
}
double HourlyEmployee::calculateSalary() const
{

    return (BASICSALARY * rate * nHours) / 240;
}
ostream &operator<<(ostream &os, const HourlyEmployee &h)
{
    h.print(os);
    return os;
}
double Employee::calculateSalary() const
{
}