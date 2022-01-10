#include "line.h"

Line::Line(double length,QColor col,int thickness,QPointF location){

    counter++;
    QString tit="L"+QString::number(counter);

    setType("Line");
    setTitle(tit);
    setColor(col);
    setThickness(thickness);
    setLocation(location);
    setLength(length);
    setPerimeter(length);
    setarea(0);
    setIsFilled(false);

}

int Line::counter=0;

//double Line::getPerimeter(){
//    return getLength();
//}

//double Line::getarea(){
//    return 0;
//}

double Line::getLength(){
    return length;
}

void Line::setLength(double l){
    length=l;
}
