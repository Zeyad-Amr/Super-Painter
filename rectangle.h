#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle:public Shape
{
public:
    Rectangle(double length,double width,QString tit,QColor col,int thickness,QPointF location,bool isFilled);

    void setLength(double length);
    double getLength();
    void setWidth(double width);
    double getWidth();

    double getPerimeter() override;
    double getarea() override;





private:
    double length;
    double width;
    bool isFilled;


};

#endif // RECTANGLE_H
