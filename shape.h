#ifndef SHAPE_H
#define SHAPE_H

#include<QVector>
#include<QString>
#include <QPainter>



class Shape
{
public:
    Shape();


   static std::vector<Shape> shapes;
   static std::vector<Shape> Undoshapes;



   virtual double getPerimeter();
   virtual double getarea();

   virtual void setPerimeter(double p);
   virtual void setarea(double a);

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

   virtual bool getIsFilled();
   virtual void setIsFilled(bool isfilled);
   static int index;
   int order;

private:


    QString title;
    QString type;
    QColor color;
    int thickness;
    QPointF location;
    bool isFilled;
    double perimeter;
    double area;


};

#endif // SHAPE_H
