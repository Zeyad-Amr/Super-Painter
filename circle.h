#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>
class Circle:public Shape
{
public:
    Circle(double raduis,QColor col,int thickness,QPointF location,bool isFilled);
//    Circle();
    void setRaduis(double raduis);
    double getRaduis();





    static int counter;

private:
    double raduis;


};

#endif // CIRCLE_H
