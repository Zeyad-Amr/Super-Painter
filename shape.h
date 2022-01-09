#ifndef SHAPE_H
#define SHAPE_H

#include<QVector>
#include<QString>
#include <QPainter>

class Shape
{
public:
    Shape();
   static QVector<Shape> shapes;

private:
QString title;
QString type;
double perimeter;
double area;
QColor color;
int brushWidth;
QPointF location;

};

#endif // SHAPE_H
