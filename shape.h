#ifndef SHAPE_H
#define SHAPE_H

#include<QVector>
#include<QString>
#include <QPainter>

class Shape
{
public:
    Shape();
//   static QVector<Shape> shapes;
   virtual double getPerimeter();
   virtual double getarea();

   virtual void setTitle(QString title);
   virtual QString getTitle();

   virtual void setType(QString type);
   virtual QString getType();

   virtual void setColor(QColor color);
   virtual QColor getColor();

   virtual void setThickness(int thickness);
   virtual int getThickness();

   virtual void setLocation(QPointF point);
   virtual QPointF getLocation();

private:

    QString title;
    QString type;
    double perimeter;
    double area;
    QColor color;
    int thickness;
    QPointF location;

};

#endif // SHAPE_H
