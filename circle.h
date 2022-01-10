#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>
class Circle:public Shape
{
public:
    Circle(double raduis,QString tit,QColor col,int thickness,QPointF location,bool isFilled);

    void setRaduis(double raduis);
    double getRaduis();

    double getPerimeter() override;
    double getarea() override;



private:
    double raduis;


};

#endif // CIRCLE_H
