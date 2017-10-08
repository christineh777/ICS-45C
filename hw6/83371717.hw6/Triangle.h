//
//  Triangle.h
//  hw6
//
//  Created by Changchuan Shen on 2016/11/9.
//  Copyright © 2016年 Changchuan Shen. All rights reserved.
//

#ifndef Triangle_h
#define Triangle_h
#include "Shape.h"
class Triangle: public Shape
{
public:
    Triangle(double base,double height,string name):Shape(base/2,height/2,name)
    {
        this->base=base;
        this->height=height;
    }
    virtual double area()
    {
        return height*base/2;
    }
    virtual void draw()
    {
        cout<<"          *\n"
            <<"         * * \n"
            <<"        *   *\n"
            <<"       *     *  \n"
            <<"      *       * \n"
            <<"     *         * \n"
            <<"    *           *\n"
            <<"   ***************\n"<<endl;
    }
private:
    double base;
    double height;
};

#endif /* Triangle_h */
