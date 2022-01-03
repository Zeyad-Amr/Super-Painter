#include "drawpanel.h"

#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include<QtMath>

DrawPanel::DrawPanel(QWidget *parent) : QWidget(parent)
{
    start();
}


DrawPanel::~DrawPanel() {}


void DrawPanel::start()
{
    drawPanel = QImage(this->size(), QImage::Format_RGB32);
    drawPanel.fill(Qt::white);
    setColor(Qt::black);
    setFillColor(Qt::black);
    setBrushWidth(1);
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);
    setIsLine(true);
    setIsCircle(false);
    setIsTriangle(false);
    setIsRectangle(false);
    setIsFilling(false);
    mousePressed = false;
}


bool DrawPanel::openImage()
{
     QString openImageLocation = QFileDialog::getOpenFileName(this, tr("Open image"), "", tr("PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)" ));
     if(!openImageLocation.isEmpty())
     {
        drawPanel.load(openImageLocation);
        return true;
     }
     else
     {
         return false;
     }
}


void DrawPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        firstPoint = event->pos();
        lastPoint = event->pos();

        isDrawing = true;
        mousePressed = true;
    }
    update();
}


void DrawPanel::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && isDrawing)
    {
        lastPoint = event->pos();
    }
    update();
}


void DrawPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isDrawing)
    {
        isDrawing = false;
        mousePressed = false;
    }
    update();
}


void DrawPanel::paintEvent(QPaintEvent *event)
{
    static bool wasMousePressed = false;

    QRect dirtyRect = event->rect();
    QPainter painter(this);
    painter.drawImage(dirtyRect, drawPanel, dirtyRect);

    if(mousePressed){
        wasMousePressed = true;

        if (getIsCircle()){
            qreal R= sqrt(pow(firstPoint.rx()-lastPoint.rx(),2)+pow(firstPoint.ry()-lastPoint.ry(),2));
            QPainter circlePainter(this);
            circlePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            circlePainter.drawEllipse(firstPoint,R,R);



        }else if (getIsFilledCircle()){
            qreal R= sqrt(pow(firstPoint.rx()-lastPoint.rx(),2)+pow(firstPoint.ry()-lastPoint.ry(),2));
            QPainter circlePainter(this);
            circlePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            circlePainter.drawEllipse(firstPoint,R,R);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addEllipse(firstPoint,R,R);
            painter.fillPath(path, fillbrush);

        }else if (getIsRectangle()){
            QRect rect = QRect(firstPoint, lastPoint);
            QPainter rectanglePainter(this);
            rectanglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            rectanglePainter.drawRect(rect);

        }else if (getIsFilledRectangle()){
            QRect rect = QRect(firstPoint, lastPoint);
            QPainter rectanglePainter(this);
            rectanglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            rectanglePainter.drawRect(rect);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addRoundedRect(rect,brushWidth, brushWidth);
            painter.fillPath(path,fillbrush);

        }else if (getIsTriangle()){
            QPainter trianglePainter(this);
            trianglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QPoint *points = new QPoint[3];
            points[0] = QPoint(firstPoint.x(), lastPoint.y());
            points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            trianglePainter.drawPolygon(polygon);

        }else if (getIsFilledTriangle()){
            QPainter trianglePainter(this);
            trianglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QPoint *points = new QPoint[3];
            points[0] = QPoint(firstPoint.x(), lastPoint.y());
            points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            trianglePainter.drawPolygon(polygon);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addPolygon(polygon);
            painter.fillPath(path,fillbrush);

        }else if (getIsLine()){
            QPainter linePainter(this);
            linePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QPoint *points = new QPoint[3];

            points[0] = QPoint(firstPoint.x(), firstPoint.y());
            points[1] = QPoint(lastPoint.x() , lastPoint.y());

            QPolygon polygon;
            polygon<<points[0]<<points[1];

            linePainter.drawPolygon(polygon);

        }/*else{
            QPainter pencilPainter(&drawPanel);
            pencilPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            pencilPainter.drawLine(lastPoint, firstPoint);

            firstPoint = lastPoint;
        }*/
    }else if(wasMousePressed)
    {
        QPainter painter(&drawPanel);
        painter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));

        if (getIsCircle())
        {
            qreal R= sqrt(pow(firstPoint.rx()-lastPoint.rx(),2)+pow(firstPoint.ry()-lastPoint.ry(),2));
            painter.drawEllipse(firstPoint,R,R);

        }else if (getIsFilledCircle()){
            qreal R= sqrt(pow(firstPoint.rx()-lastPoint.rx(),2)+pow(firstPoint.ry()-lastPoint.ry(),2));
            painter.drawEllipse(firstPoint,R,R);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addEllipse(firstPoint,R,R);
            painter.fillPath(path, fillbrush);

        }else if (getIsRectangle()){
            QRect rect = QRect(firstPoint, lastPoint);
            painter.drawRect(rect);

        }else if (getIsFilledRectangle()){
            QRect rect = QRect(firstPoint, lastPoint);
            painter.drawRect(rect);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addRoundedRect(rect,brushWidth, brushWidth);
            painter.fillPath(path,fillbrush);

        }else if (getIsTriangle()){
            QPoint *points = new QPoint[3];
            points[0] = QPoint(firstPoint.x(), lastPoint.y());
            points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            painter.drawPolygon(polygon);

        }else if (getIsFilledTriangle()){
        QPoint *points = new QPoint[3];
        points[0] = QPoint(firstPoint.x(), lastPoint.y());
        points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
        points[2] = QPoint(lastPoint);

        QPolygon polygon;
        polygon<<points[0]<<points[1]<<points[2];
        painter.drawPolygon(polygon);
        QBrush fillbrush(currentColor);
        QPainterPath path;
        path.addPolygon(polygon);
        painter.fillPath(path,fillbrush);

    }else if (getIsLine()){
        QPoint *points = new QPoint[3];
        points[0] = QPoint(firstPoint.x(), firstPoint.y());
        points[1] = QPoint(lastPoint.x() , lastPoint.y());

        QPolygon polygon;
        polygon<<points[0]<<points[1];
        painter.drawPolygon(polygon);

    }/* else{
            painter.drawImage(dirtyRect, drawPanel, dirtyRect);
        }*/

        wasMousePressed = false;
    }
    update();
}


void DrawPanel::resizeEvent(QResizeEvent *event)
{
    if (width() != drawPanel.width() || height() != drawPanel.height())
    {
        int nWidth, nHeight;

        if (width() > drawPanel.width())
            nWidth = width();
        if (width() <= drawPanel.width())
            nWidth = drawPanel.width();
        if (height() > drawPanel.height())
            nHeight = height();
        if (height() <= drawPanel.height())
            nHeight = drawPanel.height();

        resize(nWidth,nHeight);
    }
}


QImage DrawPanel::getImage()
{
    return drawPanel;
}

void DrawPanel::setImage(QImage image)
{
    drawPanel = image;
}

void DrawPanel::resize(int w, int h)
{
    QPixmap newImage(QSize(w, h));
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), drawPanel);
    setImage(newImage.toImage());
    update();
}

void DrawPanel::clear()
{
    drawPanel.fill(Qt::white);
    update();
}

QColor DrawPanel::getPrevColor() const
{
    return prevColor;
}

void DrawPanel::setPrevColor(const QColor &value)
{
    prevColor = value;
}

Qt::PenStyle DrawPanel::getPenStyle() const
{
    return penStyle;
}

void DrawPanel::setPenStyle(const Qt::PenStyle &value)
{
    penStyle = value;
}

Qt::PenCapStyle DrawPanel::getCapStyle() const
{
    return capStyle;
}

void DrawPanel::setCapStyle(const Qt::PenCapStyle &value)
{
    capStyle = value;
}

Qt::PenJoinStyle DrawPanel::getJoinStyle() const
{
    return joinStyle;
}

void DrawPanel::setJoinStyle(const Qt::PenJoinStyle &value)
{
    joinStyle = value;
}

bool DrawPanel::getIsRectangle() const
{
    return isRectangle;
}

void DrawPanel::setIsRectangle(bool value)
{
    isRectangle = value;
}

bool DrawPanel::getIsFilledRectangle() const
{
    return isFilledRectangle;
}

void DrawPanel::setIsFilledRectangle(bool value)
{
    isFilledRectangle = value;
}

bool DrawPanel::getIsCircle() const
{
    return isCircle;
}

void DrawPanel::setIsCircle(bool value)
{
    isCircle = value;
}

bool DrawPanel::getIsFilledCircle() const
{
    return isFilledCircle;
}

void DrawPanel::setIsFilledCircle(bool value)
{
    isFilledCircle = value;
}

bool DrawPanel::getIsTriangle() const
{
    return isTriangle;
}

void DrawPanel::setIsTriangle(bool value)
{
    isTriangle = value;
}


bool DrawPanel::getIsFilledTriangle() const
{
    return isFilledTriangle;
}

void DrawPanel::setIsFilledTriangle(bool value)
{
    isFilledTriangle = value;
}


bool DrawPanel::getIsLine() const
{
    return isLine;
}

void DrawPanel::setIsLine(bool value)
{
    isLine = value;
}


bool DrawPanel::getIsErase() const
{
    return isErase;
}

void DrawPanel::setIsErase(bool value)
{
    isErase= value;
}

bool DrawPanel::getIsFilling() const
{
    return isFilling;
}

void DrawPanel::setIsFilling(bool value)
{
    isFilling = value;
}

QColor DrawPanel::getFillColor() const
{
    return fillColor;
}

void DrawPanel::setFillColor(const QColor &value)
{
    fillColor = value;
}

QImage DrawPanel::getCopyDrawing() const
{
    return copyDrawing;
}

void DrawPanel::setCopyDrawing(const QImage &value)
{
    copyDrawing = value;
}

void DrawPanel::setColor(QColor setColor)
{
    currentColor = setColor;
}

void DrawPanel::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}

QColor DrawPanel::getColor()
{
    return currentColor;
}
