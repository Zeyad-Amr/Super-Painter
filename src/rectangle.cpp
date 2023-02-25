#include "rectangle.h"


Rectangle::Rectangle(double length,double width,QColor col,int thickness,QPointF location,bool isFilled){

    counter++;
    QString tit="R"+QString::number(counter);

    setType("Rectangle");
    setTitle(tit);
    setColor(col);
    setThickness(thickness);
    setLocation(location);
    setWidth(width);
    setLength(length);
    setPerimeter((length+width)*2);
    setarea(length*width);
    setIsFilled(isFilled);

}

int Rectangle::counter=0;

//double Rectangle::getPerimeter(){
//    return (getLength()+getWidth())*2;
//}

//double Rectangle::getarea(){
//    return getLength()*getWidth();
//}

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

