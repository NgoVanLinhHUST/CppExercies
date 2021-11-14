#include "shape.h"
#include <iostream>
#include <math.h>

using namespace std;


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
{}

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
    return sqrt(p*(p-side1)*(p-side2)*(p-side3)); // heron
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


