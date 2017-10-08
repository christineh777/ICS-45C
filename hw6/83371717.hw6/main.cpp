#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Picture.h"

int main()
{
    Picture pic;
    Triangle* tri1=new Triangle(5,5,"FirstTriangle");
    Triangle* tri2=new Triangle(3,4,"SecondTriangle");
    pic.add(tri1);
    pic.add(tri2);
    Circle* cir1=new Circle(5,"FirstCircle");
    Circle* cir2=new Circle(10,"SecondCircle");
    pic.add(cir1);
    pic.add(cir2);
    Square* squ1=new Square(5,"FirstSquare");
    Square* squ2=new Square(10,"SecondSquare");
    pic.add(squ1);
    pic.add(squ2);
    Rectangle* rec1=new Rectangle(4,8,"FirstRectangle");
    Rectangle* rec2=new Rectangle(8,4,"SecondRectangle");
    pic.add(rec1);
    pic.add(rec2);
    
    pic.drawAll();
    cout<<"The total area of the shapes on this picture is "<<pic.totalArea()<<" square units."<<endl;
    
    delete tri1;
    delete tri2;
    delete cir1;
    delete cir2;
    delete squ1;
    delete squ2;
    delete rec1;
    delete rec2;
    
    return 0;
}
