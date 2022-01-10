#include "line.h"

Line::Line(double length,QString tit,QColor col,int thickness,QPointF location){

    setType("line");
    setTitle(tit);
    setColor(col);
    setThickness(thickness);
    setLocation(location);
    setLength(length);

    setIsFilled(false);

}


double Line::getPerimeter(){
    return getLength();
}

double Line::getarea(){
    return 0;
}

double Line::getLength(){
    return length;
}

void Line::setLength(double l){
    length=l;
}
