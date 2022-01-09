#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle:Shape
{
public:
    Rectangle(double length,double width,QString tit,QColor col,int thickness,QPointF location);

    void setLength(double length);
    double getLength();
    void setWidth(double width);
    double getWidth();

    double getPerimeter() override;
    double getarea() override;



private:
    double length;
    double width;


};

#endif // RECTANGLE_H
