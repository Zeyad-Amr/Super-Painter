#include "circle.h"

Circle::Circle(double r,QString tit,QColor col,int thick,QPointF loc,bool isFilled)
{
    setType("circle");
    setTitle(tit);
    setColor(col);
    setThickness(thick);
    setLocation(loc);
    setRaduis(r);
    setIsFilled(isFilled);



}

double Circle::getPerimeter(){
    return getRaduis()*2*3.14;
}

double Circle::getarea(){
    return getRaduis()*getRaduis()*3.14;
}

double Circle::getRaduis(){
    return raduis;
}

void Circle::setRaduis(double r){
    raduis=r;
}
