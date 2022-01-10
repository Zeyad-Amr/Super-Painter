#include "shape.h"

Shape::Shape()
{

}

int Shape::index=0;
std::vector<Shape> Shape::shapes;
std::vector<Shape> Shape::Undoshapes;

double Shape::getPerimeter(){
    return perimeter;
}

double Shape::getarea(){
    return area;
}

void Shape::setPerimeter(double per){
    perimeter=per;
}

void Shape::setarea(double a){
   area=a;
}

void Shape::setType(QString t){
    index++;
    order=index;
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


