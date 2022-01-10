#include "rectangle.h"


Rectangle::Rectangle(double length,double width,QString tit,QColor col,int thickness,QPointF location,bool isFilled){

    setType("rectangle");
    setTitle(tit);
    setColor(col);
    setThickness(thickness);
    setLocation(location);
    setWidth(width);
    setLength(length);
    setIsFilled(isFilled);

}


double Rectangle::getPerimeter(){
    return (getLength()+getWidth())*2;
}

double Rectangle::getarea(){
    return getLength()*getWidth();
}

double Rectangle::getLength(){
    return length;
}
double Rectangle::getWidth(){
    return width;
}
void Rectangle::setLength(double l){
    length=l;
}
void Rectangle::setWidth(double w){
    width=w;
}

