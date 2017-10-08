
#ifndef Square_h
#define Square_h
#include "Shape.h"
class Square:public Shape
{
public:
    Square(double height,string name):Shape(height/2,height/2,name)
    {
        this->height=height;
    }
    virtual double area()
    {
        return height*height;
    }
    virtual void draw()
    {
        cout<<"  **************\n"
            <<"  *            *\n"
            <<"  *            *\n"
            <<"  *            *\n"
            <<"  *            *\n"
            <<"  *            *\n"
            <<"  *            *\n"
            <<"  **************\n"<<endl;
    }
protected:
    double height;
};

#endif /* Square_h */
