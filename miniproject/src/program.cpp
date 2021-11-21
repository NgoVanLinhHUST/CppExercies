#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "program.h"
#include "excep.h"

using namespace std;

#define ADD 1
#define UPDATE 2
#define DELETE 3
#define SEARCH 4
#define SHOW 5
#define SAVE 6
#define READ 7

Employee Program::convertStringtoEmployee(string inputString)
{
    string fields[7];
    string str = "";
    int count = 0;
    for(int i = 0; i < inputString.length(); i++) 
    {
        if(inputString[i]=='|') 
        {
            fields[count++] = str;
            str="";
        } else {
            str+=inputString[i];
        }
    }
    if (fields[5]=="fulltime")
    {
        Employee *e = new FulltimeEmployee(stoi(fields[0]), fields[1],stoi(fields[2]),stoi(fields[3]), atof(fields[4].c_str()));
        return *e;
    }
    if (fields[5]=="parttime")
    {
        Employee *e = new ParttimeEmployee(stoi(fields[0]), fields[1],stoi(fields[2]),stoi(fields[3]), atof(fields[4].c_str()));
        return *e;
    }
    if (fields[5]=="hourly")
    {
        Employee *e = new HourlyEmployee(stoi(fields[0]), fields[1],stoi(fields[2]),stoi(fields[3]), atof(fields[4].c_str()), stoi(fields[6]));
        return *e;
    }
    
}

int MenuProgram::getChoice() const
{
    cout << "Enter your chocie: ";
    int choice;
    cin >> choice;
    return choice;
}
Program::Program()
{
    nEmployees = 0;
    // count = 0;
}

void Program::printMenu() const
{
    cout << "~~~~~~ DEMO ~~~~~~" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Update by ID" << endl;
    cout << "3. Delete by ID" << endl;
    cout << "4. Search by name" << endl;
    cout << "5. Show all employees" << endl;
    cout << "6. Save file" << endl;
    cout << "7. Read file" << endl;
    cout << "0. Exit" << endl;
}
void Program::doTask(const int &choice)
{
    switch (choice)
    {
    case ADD:
        addEmployee();
        break;
    case UPDATE:
        updateEmployeeByID();
        break;
    case DELETE:
        deleteEmployeeByID();
        break;
    case SEARCH:
        searchEmployeeByName();
        break;
    case SHOW:
        showListEmployee();
        break;
    case SAVE:
        saveFile();
        break;
    case READ:
        readFile();
        break;
    case 0:
        exitProgram();
        break;
    default:
        showError();
        break;
    }
}
void Program::addEmployee()
{
    cout << "\n\n\t\t~~~~~~ MENU ADD ~~~~~~" << endl;
    cout << "1. Add Fulltime Employee" << endl;
    cout << "2. Add Partime Employee" << endl;
    cout << "3. Add Hourly Employee" << endl;
    cout << "Enter your choise :";
    int choice2;
    cin >> choice2;
    switch (choice2)
    {
    case 1:
        addFulltimeEmPloyee();
        break;
    case 2:
        addParttimeEmployee();
        break;
    case 3:
        addHourlyEmployee();
        break;
    }
}
void Program::addFulltimeEmPloyee()
{
    string name;
    double rate;
    int ID, telephone, age;
    while (true)
	{
		try {
            cout << "\nEnter ID of Employee: ";
            cin >> ID;
            checkId(ID);
			break;
		} catch (SamdIdException ex)
		{
			cout << ex.what() << ". Please try again!" << endl;
		}
    }
    cout << "\nEnter name of Employee: ";
    cin >> name;
    cout << "\nEnter telephone of Employee: ";
    cin >> telephone;
    cout << "\nEnter age of Employee: ";
    cin >> age;
    while (true)
	{
		try {
            cout << "\nEnter rate of Employee: ";
            cin >> rate;
            checkRate(rate);
			break;
		} catch (rateGreaterTen ex)
		{
			cout << ex.what() << " Error : Rate is from 0.0 to 10.0 " << endl;
		}
    }
    Employees[nEmployees++] = new FulltimeEmployee(ID, name, telephone, age, rate);
    count++;
}
void Program::addParttimeEmployee()
{
    string name;
    double rate;
    int ID, telephone, age;
    while (true)
	{
		try {
            cout << "\nEnter ID of Employee: ";
            cin >> ID;
            checkId(ID);
			break;
		} catch (SamdIdException ex)
		{
			cout << ex.what() << ". Please try again!" << endl;
		}
    }
    cout << "\nEnter name of Employee: ";
    cin >> name;
    cout << "\nEnter telephone of Employee: ";
    cin >> telephone;
    cout << "\nEnter age of Employee: ";
    cin >> age;
     while (true)
	{
		try {
            cout << "\nEnter rate of Employee: ";
            cin >> rate;
            checkRate(rate);
			break;
		} catch (rateGreaterTen ex)
		{
			cout << ex.what() << " Error : Rate is from 0.0 to 10.0 " << endl;
		}
    }
    Employees[nEmployees++] = new ParttimeEmployee(ID, name, telephone, age, rate);
    count++;
}
void Program::addHourlyEmployee()
{
    string name;
    double rate;
    int ID, telephone, age, nHours;
    while (true)
	{
		try {
            cout << "\nEnter ID of Employee: ";
            cin >> ID;
            checkId(ID);
			break;
		} catch (SamdIdException ex)
		{
			cout << ex.what() << ". Please try again!" << endl;
		}
    }
    cout << "\nEnter name of Employee: ";
    cin >> name;
    cout << "\nEnter telephone of Employee: ";
    cin >> telephone;
    cout << "\nEnter age of Employee: ";
    cin >> age;
    while (true)
	{
		try {
            cout << "\nEnter rate of Employee: ";
            cin >> rate;
            checkRate(rate);
			break;
		} catch (rateGreaterTen ex)
		{
			cout << ex.what() << " Error : Rate is from 0.0 to 10.0 " << endl;
		}
    }
    cout << "\nEnter number hours of Employee: ";
    cin >> nHours;
    Employees[nEmployees++] = new HourlyEmployee(ID, name, telephone, age, rate, nHours);
    count++;
}
void Program::exitProgram()
{
    cout << "Program quits. See you again!" << endl;
}

void Program::showError()
{
    cout << "Invalid choice! Please try again!" << endl;
}

Program::~Program()
{
    for (int i = 0; i < 100; i++)
    {
        if (Employees[i] != NULL)
        {
            delete Employees[i];
            Employees[i] = NULL;
        }
    }
}
void MenuProgram::run()
{
    bool running = true;
    while (running)
    {
        printMenu();
        int choice = getChoice();
        doTask(choice);
        running = choice != 0;
    }
}
void Program::showListEmployee()
{
    for (int i = 0; i < 100; i++)
    {
        cout << *Employees[i] << endl; 
        break;
    }
}
void Program::updateEmployeeByID()
{
    int ID;
    bool checked = false;
    cout << " Enter ID update:";
    cin >> ID;
    for (int i = 0; i < nEmployees; i++)
    {
        if (Employees[i]->getID() == ID)
        {
            checked = true;
            cout << *Employees[i];
            string name;
            double rate, bonus;
            int ID, telephone, age;
            cout << "\nEnter New ID of Employee: ";
            cin >> ID;
            cout << "\nEnter new name of Employee: ";
            cin >> name;
            cout << "\nEnter Newtelephone of Employee: ";
            cin >> telephone;
            cout << "\nEnter New age of Employee: ";
            cin >> age;
            cout << "\nEnter New rate of Employee: ";
            cin >> rate;
            Employees[i] = new FulltimeEmployee(ID, name, telephone, age, rate);
            cout << "Update Done" << endl;
            break;
        }
        else 
            cout << " Not found ID Employee! Please retry again."<< endl;
    }
}
void Program::deleteEmployeeByID()
{
    int ID;
    bool checked = false;
    cout << " Enter ID delete:";
    cin >> ID;
    for (int i = 0; i < nEmployees; i++)
    {
        if (Employees[i]->getID() == ID)
        {
            checked = true;
            for (int j = i; j < nEmployees; j++)
            {
                Employees[j] = Employees[j+1];
            }
            cout << "Delete Done" << endl;
            break;
        }
        else 
            cout << " Not found ID Employee! Please retry again." << endl;
    }

}
void Program::saveFile()
{
    ofstream ofs("empdata.txt");
    if(!ofs){
        cout << "Error: file not opened." << endl;
    } else {
        for (int i = 0; i < nEmployees; i++)
        {
            ofs << Employees[i]->toString();
        }
        ofs.close();
    }
    cout << "Save Done" << endl;
}
int Program::readFile()
{
    ifstream file("empdata.txt");
    string str;
    int i = 0;
    cout << "File : " << endl;
    while (std::getline(file, str))
    {
        cout << convertStringtoEmployee(str) << endl;
        cout << "===================================" << endl;
    }

}
void Program::searchEmployeeByName()
{
    string name;
    bool checked = false;
    cout << " Enter Name:";
    cin >> name;
    for (int i = 0; i < nEmployees; i++)
    {
        if (Employees[i]->getName() == name)
        {
            checked = true;
            cout << *Employees[i];
            break;
        }
        else 
            cout << " Not found ID Employee! Please retry again." << endl;
    }

}
void Program::checkRate(int RT)
{
        if (RT >10 ) {
            throw rateGreaterTen();
        }
}
void Program::checkId(int id)
{

    if (count > 0)
    {   
        for (int i = 0; i < count; i++)
        {
            // cout << *Employees[i];
            if ((*Employees[i]).getID() == id) 
                throw SamdIdException();
        }
    }
}