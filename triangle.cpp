#include "triangle.h"
#include<QtMath>

Triangle::Triangle(double base,double side,QColor col,int thickness,QPointF location,bool isFilled){

    counter++;
        QString tit="Tr"+QString::number(counter);

    setType("Triangle");
    setTitle(tit);
    setColor(col);
    setThickness(thickness);
    setLocation(location);
    setSide(side);
    setBase(base);
    setPerimeter(side*2+base);
    double s=(side*2+base)/2;

    setarea(sqrt(s*pow(s-side,2)*(s-base)));
    setIsFilled(isFilled);

}

int Triangle::counter=0;


//double Triangle::getPerimeter(){
//    return getSide()*2+getBase();
//}

//double Triangle::getarea(){
//    double s=getPerimeter()/2;
//    return sqrt(s*pow(s-getSide(),2)*(s-getBase()));
//}

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

