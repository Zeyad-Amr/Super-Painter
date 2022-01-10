#include "shape.h"

Shape::Shape()
{

}

double Shape::getPerimeter(){
    return 0;
}

double Shape::getarea(){
    return 0;
}


void Shape::setType(QString t){
    type=t;
}

QString Shape::getType(){
    return type;
}

void Shape::setTitle(QString tit){
    title=tit;
}

QString Shape::getTitle(){
    return title;
}

void Shape::setColor(QColor col){
    color=col;
}
QColor Shape::getColor(){
    return color;
}

void Shape::setThickness(int thick){
    thickness=thick;
}
int Shape::getThickness(){
    return thickness;
}

void Shape::setLocation(QPointF point){
    location=point;
}
QPointF Shape::getLocation(){
    return location;
}

bool Shape::getIsFilled(){
    return isFilled;
}
void Shape::setIsFilled(bool isf){
    isFilled=isf;
}
