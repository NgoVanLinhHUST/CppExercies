#include "menu.h"
#include <iostream>

using namespace std;

int MenuProgram::getChoice() const
{
    cout << "Enter your chocie: ";
    int choice;
    cin >> choice;
    return choice;
}

/*         SHAPE IMPLEMENTATION */
ShapeDemo::ShapeDemo()
{
    nShapes = 0;
}
void ShapeDemo::printMenu() const
{
    cout << "~~~~~~ DEMO SHAPE ~~~~~~" << endl;
    cout << "1. Add Shape" << endl;
    cout << "2. Print all" << endl;
    cout << "0. Exit" << endl;
}

void ShapeDemo::doTask(const int &choice) 
{
    switch (choice)
    {
        case ADDSHAPE : addShape    (); break;
        case PRINT    : printAll    (); break;
        case EXIT     : exitProgram (); break;
        default       : showError   (); break;
    }
}
void ShapeDemo::addShape()
{

    cout << "\n\n\t\t~~~~~~ MENU ADD ~~~~~~" << endl;
    cout << "1. Add Circle" << endl;
    cout << "2. Add Rectangle" << endl;
    cout << "3. Add Square" << endl;
    cout << "4. Add Triangle" << endl; 
    cout << "5. Add ETriangle" << endl;   
    cout << "Enter your choise :";
    int choice2;
    cin >> choice2;
        switch (choice2)
        {
        case CIRCLE   : addCircle   (); break;
        case RECTANGLE: addRectangle(); break;
        case SQUARE   : addSquare   (); break;
        case TRIANGLE : addTriangle (); break;
        case ETRIANGLE: addETriangle(); break;
        }
}
void ShapeDemo::addCircle()
{
    // Circle(const string &name, const double &radius);
    string name;
    cout << "Enter name of circle: ";
    cin >> name ;
    double radius;
    cout << "\nEnter radius: ";
    cin >> radius;
    shapes[nShapes++] = new Circle(name,radius);
    
}

void ShapeDemo::addRectangle()
{
    string name;
    cout << "Enter name of Rectangle: ";
    cin >> name ;
    double width, heigh;
    cout << "\nEnter width: ";
    cin >> width;
    cout << "\nEnter heigh: ";
    cin >> heigh;
    shapes[nShapes++] = new Rectangle(name,width,heigh);
}

void ShapeDemo::addSquare()
{
    string name;
    cout << "Enter name of Square: ";
    cin >> name ;
    double side;
    cout << "\nEnter length side: ";
    cin >> side;
    shapes[nShapes++] = new Square(name, side);
}

void ShapeDemo::addTriangle()
{
    string name;
    cout << "Enter name of Triangle: ";
    cin >> name ;
    double side1, side2, side3;
    cout << "\nEnter side1: ";
    cin >> side1;
    cout << "\nEnter side2: ";
    cin >> side2;
    cout << "\nEnter side3: ";
    cin >> side3;

    shapes[nShapes++] = new Triangle(name,side1,side2,side3);

}
void ShapeDemo::addETriangle()
{
    string name;
    cout << "Enter name of ETriangle: ";
    cin >> name ;
    double side;
    cout << "\nEnter side: ";
    cin >> side;

    shapes[nShapes++] = new ETriangle(name,side);
    
}
void ShapeDemo::printAll()
{
    for (int i = 0; i < nShapes; i++)
        cout << *shapes[i] << endl; // call print -> area
        // c1->print();
}
void ShapeDemo::exitProgram()
{
    cout << "Program quits. See you again!" << endl;
}

void ShapeDemo::showError()
{
    cout << "Invalid choice! Pelase try again!" << endl;
}

ShapeDemo::~ShapeDemo()
{
    for (int i = 0; i < nShapes; i++)
    {
        if (shapes[i] != NULL) 
        {
            delete shapes[i];
            shapes[i] = NULL;
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
        running = choice != EXIT;
    }
}