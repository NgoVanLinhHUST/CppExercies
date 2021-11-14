#pragma once
#include <string>
#include <iostream>
using namespace std;

#define PI 3.14
#define EXIT 0
#define ADDSHAPE 1
#define CIRCLE 1
#define RECTANGLE 2
#define SQUARE 3
#define TRIANGLE 4
#define ETRIANGLE 5
#define PRINT 2
#define NSHAPES 100

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