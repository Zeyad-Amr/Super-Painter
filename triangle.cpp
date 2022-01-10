#include "triangle.h"
#include<QtMath>

Triangle::Triangle(double base,double side,QString tit,QColor col,int thickness,QPointF location,bool isFilled){

    setType("triangle");
    setTitle(tit);
    setColor(col);
    setThickness(thickness);
    setLocation(location);
    setSide(side);
    setBase(base);
    setIsFilled(isFilled);

}


double Triangle::getPerimeter(){
    return getSide()*2+getBase();
}

double Triangle::getarea(){
    double s=getPerimeter()/2;
    return sqrt(s*pow(s-getSide(),2)*(s-getBase()));
}

double Triangle::getSide(){
    return side;
}
double Triangle::getBase(){
    return base;
}
void Triangle::setSide(double s){
    side=s;
}
void Triangle::setBase(double b){
    base=b;
}

