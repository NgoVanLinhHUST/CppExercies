#pragma once
#include "shape.h"

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