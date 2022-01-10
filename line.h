#ifndef LINE_H
#define LINE_H

#include <shape.h>
class Line:public Shape
{
public:
    Line(double length,QColor col,int thickness,QPointF location);

    void setLength(double length);
    double getLength();




    static int counter;



private:
    double length;

    bool isFilled;



};

#endif // LINE_H
