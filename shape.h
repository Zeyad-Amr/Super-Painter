#ifndef SHAPE_H
#define SHAPE_H

#include<QVector>
#include<QString>
#include <QPainter>


class Shape
{
public:
    Shape();

    std::vector<Shape> shapes;

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

   virtual bool getIsFilled();
    virtual void setIsFilled(bool isfilled);

private:

    QString title;
    QString type;
    QColor color;
    int thickness;
    QPointF location;
    bool isFilled;

};

#endif // SHAPE_H
