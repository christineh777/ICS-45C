

#ifndef Circle_h
#define Circle_h
#include "Shape.h"
#define PI 3.14159
class Circle:public Shape
{
public:
    Circle(double r,string name):Shape(r,r,name)
    {
        radius=r;
    }
    virtual double area()
    {
        return radius*radius*PI;
    }
    virtual void draw()
    {
        cout<<"     * * *    \n"
            <<"   *       *  \n"
            <<"  *         * \n"
            <<" *           *\n"
            <<" *           *\n"
            <<"  *         * \n"
            <<"   *       *  \n"
            <<"     * * *    \n"<<endl;
    }
private:
    double radius;
};




#endif /* Circle_h */
