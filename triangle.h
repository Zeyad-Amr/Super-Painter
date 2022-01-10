#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
class Triangle:public Shape
{
public:
    Triangle(double base,double side,QColor col,int thickness,QPointF location,bool isFilled);

    void setBase(double length);
    double getBase();
    void setSide(double width);
    double getSide();



    static int counter;



private:
    double base;
    double side;
    bool isFilled;


};

#endif // TRIANGLE_H
