#include "shape.h"

Shape::Shape()
{
//   shapes.push_front(this);
}

double Shape::getPerimeter(){
    return perimeter;
}

void Shape::setType(QString t){
    type=t;
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
