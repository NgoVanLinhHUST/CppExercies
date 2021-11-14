#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define EXIT 0
#define ADDSHAPE 1
#define CIRCLE 1
#define RECTANGLE 2
#define SQUARE 3
#define TRIANGLE 4
#define ETRIANGLE 5
#define PRINT 2
#define NSHAPES 100


#define PI 3.14

class Shape // abstract class -> cannot create objects
{
    protected:
        string name;
    public:
        Shape();
        Shape(const string &name);

        virtual double area() const = 0; // return 0.0
        friend ostream& operator<<(ostream& os, const Shape &s);
    protected:
        void print(ostream &os) const; // print name, area
    public:
        virtual ~Shape();
};

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle();
        Circle(const string &name, const double &radius);

        double area() const; // return pi*r*r
        friend ostream& operator<<(ostream& os, const Circle &c);
};

class Rectangle : public Shape 
{
    protected:
        double width;
        double height;
    public:
        Rectangle();
        Rectangle(const string &name, const double &width, const double &height);
        double area() const;
        friend ostream& operator<<(ostream& os, const Rectangle &r);
};

class Square : public Rectangle 
{
    public:
        Square();
        Square(const string &name, const double &side);
        friend ostream& operator<<(ostream& os, const Square &s);
};
class Triangle : public Shape 
{
    protected:
        double side1;
        double side2;
        double side3;
    public:
        Triangle();
        Triangle(const string &name, const double &side1, const double &side2, const double &side3);
        double area() const;
        friend ostream& operator<<(ostream& os, const Triangle &t);
};
class ETriangle : public Triangle 
{

    public:
        ETriangle();
        ETriangle(const string &name, const double &side);
        // double area() const;
        friend ostream& operator<<(ostream& os, const ETriangle &e);
};

class MenuProgram
{
    public:
        void run();
    protected:
        virtual void printMenu() const = 0; // no implementation
        int getChoice() const;
        virtual void doTask(const int &choice) = 0; // no implementation
        virtual void addShape() = 0;
};

class ShapeDemo : public MenuProgram
{
    public:
        ShapeDemo();
        ~ShapeDemo();
    private:
        Shape* shapes[NSHAPES];
        int nShapes;
    protected:
        void printMenu() const;
        void doTask(const int &choice);
    public:
        void addShape();
        void addCircle();
        void addRectangle();
        void addSquare();
        void addTriangle();
        void addETriangle();
        void printAll();
        void exitProgram();
        void showError();
};
Shape::Shape() 
{
    name = "No name";
}

Shape::Shape(const string &name) 
{
    this->name = name;
}

ostream& operator<<(ostream& os, const Shape &s) 
{
    s.print(os);
    return os;
}

void Shape::print(ostream &os) const
{
    os << "Name: " << name << ", area: " << area();
}

Shape::~Shape()
{
    // cout << "Delete Shape" << endl;
}
Circle::Circle() 
{
    name = "No name";
    radius = 1.0;
}

Circle::Circle(const string &name, const double &radius) 
{
    this->name = name;
    this->radius = radius;
}

double Circle::area() const
{
    return PI * radius * radius;
}

ostream& operator<<(ostream& os, const Circle &c) 
{
    c.print(os);
    return os;
}

Rectangle::Rectangle() : Shape("No name")
{
    width = 1.0;
    height = 2.0;
}
Rectangle::Rectangle(const string &name, const double &width, const double &height) : Shape(name)
{
    this->width = width;
    this->height = height;
}
double Rectangle::area() const
{
    return width * height;
}

ostream& operator<<(ostream& os, const Rectangle &r)
{
    r.print(os);
    return os;
}

Square::Square() : Rectangle("No name", 1.0, 1.0)
{} // don't need anything else

Square::Square(const string &name, const double &side) : Rectangle(name, side, side)
{}

ostream& operator<<(ostream& os, const Square &s)
{
    s.print(os);
    return os;
}

Triangle::Triangle(const string &name, const double &side1, const double &side2, const double &side3) : Shape (name)
{
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}
double Triangle::area() const
{
    double p = (side1 + side2 + side3)/2;
    return sqrt(p*(p-side1)*(p-side2)*(p-side3));
}
ostream& operator<<(ostream& os, const Triangle &t)
{
    t.print(os);
    return os;
}
ETriangle::ETriangle() : Triangle("No name", 1.0, 1.0, 1.0)
{}
ETriangle::ETriangle(const string &name, const double &side) : Triangle (name, side, side, side)
{}
ostream& operator<<(ostream& os, const ETriangle &e)
{
    e.print(os);
    return os;
}

// Square::Square() : Rectangle("No name", 1.0, 1.0)
// {} // don't need anything else

// Square::Square(const string &name, const double &side) : Rectangle(name, side, side)
// {}

// ostream& operator<<(ostream& os, const Square &s)
// {
//     s.print(os);
//     return os;
// }



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
        // case CIRCLE   : addCircle   (); break;
        // case RECTANGLE: addRectangle(); break;
        // case SQUARE   : addSquare   (); break;
        // case PRINT    : printAll    (); break;
        // case EXIT     : exitProgram (); break;
        // default       : showError   (); break;
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
int main()
{
	ShapeDemo program;
	program.run();

	return 0;
}