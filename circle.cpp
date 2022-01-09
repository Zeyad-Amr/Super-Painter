#include "circle.h"

Circle::Circle()
{
    setType("circle");
}

double Circle::getPerimeter(){
    return getRaduis()*2*3.14;
}

double Circle::getarea(){
    return getRaduis()*getRaduis()*3.14;
}

