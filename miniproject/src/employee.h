#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
    int ID;
    string name;
    int age;
    int telephone; // string
    double rate; // exception

public:
    Employee();
    string getName();
    int getID();
    int getAge();
    int getPhone();
    double getRate();
    ~Employee();
    Employee(const int &ID);
    virtual double calculateSalary() const;
    virtual string toString();
    friend ostream &operator<<(ostream &os, const Employee &e);
    

protected:
    void print(ostream &os) const;
};
class FulltimeEmployee : public Employee
{

public:
    FulltimeEmployee();
    FulltimeEmployee(const int &ID, const string &name, const int &telephone, const int &age, const double &rate);

    string toString();
    double calculateSalary() const;
    friend ostream &operator<<(ostream &os, const FulltimeEmployee &f);
};
class ParttimeEmployee : public Employee
{

public:
    ParttimeEmployee();
    ParttimeEmployee(const int &ID, const string &name, const int &telephone, const int &age, const double &rate);

    string toString();
    double calculateSalary() const;
    friend ostream &operator<<(ostream &os, const ParttimeEmployee &p);
};

class HourlyEmployee : public Employee
{
private:
    int nHours;

public:
    HourlyEmployee();
    HourlyEmployee(const int &ID, const string &name, const int &telephone, const int &age, const double &rate, const int &nHours);
    string toString();
    double calculateSalary() const;
    friend ostream &operator<<(ostream &os, const HourlyEmployee &h);
};