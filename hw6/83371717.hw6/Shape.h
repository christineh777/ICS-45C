

#ifndef Shape_h
#define Shape_h
#include <iostream>
#include <string>
using namespace std;

class Shape
{
public:
    Shape(double x,double y,string n)
    {
        centerX=x;
        centerY=y;
        name=n;
    }
    virtual double area() = 0;
    virtual void draw() = 0;
protected:
    double centerX;
    double centerY;
    string name;
};











#endif /* Shape_h */
