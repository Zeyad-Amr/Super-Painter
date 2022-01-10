#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
class Triangle:public Shape
{
public:
    Triangle(double base,double side,QString tit,QColor col,int thickness,QPointF location,bool isFilled);

    void setBase(double length);
    double getBase();
    void setSide(double width);
    double getSide();

    double getPerimeter() override;
    double getarea() override;





private:
    double base;
    double side;
    bool isFilled;


};

#endif // TRIANGLE_H
