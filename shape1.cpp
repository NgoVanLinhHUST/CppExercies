#include <iostream>
#include <string>
using namespace std;

#define EXIT 0
#define CIRCLE 1
#define RECTANGLE 2
#define SQUARE 3
#define PRINT 4
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

class MenuProgram
{
    public:
        void run();
    protected:
        virtual void printMenu() const = 0; // no implementation
        int getChoice() const;
        virtual void doTask(const int &choice) = 0; // no implementation
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
        void addCircle();
        void addRectangle();
        void addSquare();
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
    cout << "1. Add Circle" << endl;
    cout << "2. Add Rectangle" << endl;
    cout << "3. Add Square" << endl;
    cout << "4. Print all" << endl;
    cout << "0. Exit" << endl;
}

void ShapeDemo::doTask(const int &choice) 
{
    switch (choice)
    {
        case CIRCLE   : addCircle   (); break;
        case RECTANGLE: addRectangle(); break;
        case SQUARE   : addSquare   (); break;
        case PRINT    : printAll    (); break;
        case EXIT     : exitProgram (); break;
        default       : showError   (); break;
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
    // Shape *c1 = new Circle(name,radius);
    // shapes[nShapes] = c1;




    //  cout << Circle("alo" , 4);
    // should ask user to enter circle's info and create new circle object instead of using default constructor
 
}

void ShapeDemo::addRectangle()
{
    string name;
    cout << "Enter name of circle: ";
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