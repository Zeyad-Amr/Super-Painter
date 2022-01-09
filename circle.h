#ifndef CIRCLE_H
#define CIRCLE_H

#include <shape.h>
class Circle:Shape
{
public:
    Circle();

    void setRaduis(double raduis);
    double getRaduis();

    double getPerimeter() override;
    double getarea() override;


    void setType() override;



private:
    double raduis;


};

#endif // CIRCLE_H
