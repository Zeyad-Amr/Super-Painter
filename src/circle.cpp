#include "circle.h"

Circle::Circle(double r,QColor col,int thick,QPointF loc,bool isFilled)
{
    counter++;
    QString tit="C"+QString::number(counter);
    setType("Circle");
    setTitle(tit);
    setColor(col);
    setThickness(thick);
    setLocation(loc);
    setRaduis(r);
    setPerimeter(r*2*3.14);
    setarea(r*r*3.14);
    setIsFilled(isFilled);




}


int Circle::counter=0;

//double Circle::getPerimeter(){
//    return getRaduis()*2*3.14;
//}

//double Circle::getarea(){
//    return getRaduis()*getRaduis()*3.14;
//}

double Circle::getRaduis(){
    return raduis;
}

void Circle::setRaduis(double r){
    raduis=r;
}
