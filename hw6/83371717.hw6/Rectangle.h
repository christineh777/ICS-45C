

#ifndef Rectangle_h
#define Rectangle_h
#include "Square.h"
class Rectangle:public Square
{
public:
    Rectangle(double width,double height,string name):Square(height,name)
    {
        this->width=width;
    }
    virtual double area()
    {
        return width*height;
    }
    virtual void draw()
    {
        cout<<"  *********\n"
            <<"  *       *\n"
            <<"  *       *\n"
            <<"  *       *\n"
            <<"  *       *\n"
            <<"  *       *\n"
            <<"  *       *\n"
            <<"  *********\n"<<endl;
    }
private:
    double width;
};

#endif /* Rectangle_h */
