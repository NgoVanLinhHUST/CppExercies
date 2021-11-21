#pragma once 
#include "employee.h"

class MenuProgram
{
public:
    void run();

protected:
    virtual void printMenu() const = 0; // no implementation
    int getChoice() const;
    virtual void doTask(const int &choice) = 0; // no implementation
                                                // virtual void addShape() = 0;
};
class Program : public MenuProgram
{
private:
    Employee *Employees[100];
    int nEmployees;

protected:
    void printMenu() const;
    void doTask(const int &choice);

public:
    static int count ;
    Program();
    ~Program();
    void addEmployee();
    void addFulltimeEmPloyee();
    void addParttimeEmployee();
    void addHourlyEmployee();
    void deleteEmployeeByID();
    void updateEmployeeByID();
    void searchEmployeeByName();
    void showListEmployee();
    void saveFile();
    int readFile();
    Employee convertStringtoEmployee(string inputString);
    void exitProgram();
    void showError();
    void checkId(int id);
    void checkRate(int rate);
};
int Program::count = 0;