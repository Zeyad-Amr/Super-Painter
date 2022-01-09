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

    setBrushWidth(5);
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);

    setIsCircle(false);
    setIsRectangle(false);
    setIsTriangle(false);
    setIsLine(false);
    setIsFilledCircle(false);
    setIsFilledRectangle(false);
    setIsFilledTriangle(false);
    setIsErase(false);


    mousePressed = false;
    addCommand(getImage());
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

    if (event->button() == Qt::LeftButton && isDrawing){
        isDrawing = false;
        mousePressed = false;

    }

     update();

     addCommand(getImage());
     redoStack.clear();
}


void DrawPanel::paintEvent(QPaintEvent *event)
{
    static bool wasMousePressed = false;

    QRectF dirtyRect = event->rect();
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
            QRectF rect = QRectF(firstPoint, lastPoint);
            QPainter rectanglePainter(this);
            rectanglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            rectanglePainter.drawRect(rect);

        }else if (getIsFilledRectangle()){
            QRectF rect = QRectF(firstPoint, lastPoint);
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
            QPointF *points = new QPointF[3];
            points[0] = QPointF(firstPoint.x(), lastPoint.y());
            points[1] = QPointF(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPointF(lastPoint);

            QPolygonF polygon;
            polygon<<points[0]<<points[1]<<points[2];
            trianglePainter.drawPolygon(polygon);

        }else if (getIsFilledTriangle()){
            QPainter trianglePainter(this);
            trianglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QPointF *points = new QPointF[3];
            points[0] = QPointF(firstPoint.x(), lastPoint.y());
            points[1] = QPointF(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPointF(lastPoint);

            QPolygonF polygon;
            polygon<<points[0]<<points[1]<<points[2];
            trianglePainter.drawPolygon(polygon);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addPolygon(polygon);
            painter.fillPath(path,fillbrush);

        }else if (getIsLine()){
            QPainter linePainter(this);
            linePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QPointF *points = new QPointF[3];

            points[0] = QPointF(firstPoint.x(), firstPoint.y());
            points[1] = QPointF(lastPoint.x() , lastPoint.y());

            QPolygonF polygon;
            polygon<<points[0]<<points[1];

            linePainter.drawPolygon(polygon);

        }/*else{
            QPainter pencilPainter(&drawPanel);
            pencilPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            pencilPainter.drawLine(lastPoint, firstPoint);

            firstPoint = lastPoint;
        }*/
    }else if(wasMousePressed){

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
            QRectF rect = QRectF(firstPoint, lastPoint);
            painter.drawRect(rect);

        }else if (getIsFilledRectangle()){
            QRectF rect = QRectF(firstPoint, lastPoint);
            painter.drawRect(rect);

            QBrush fillbrush(currentColor);
            QPainterPath path;
            path.addRoundedRect(rect,brushWidth, brushWidth);
            painter.fillPath(path,fillbrush);

        }else if (getIsTriangle()){
            QPointF *points = new QPointF[3];
            points[0] = QPointF(firstPoint.x(), lastPoint.y());
            points[1] = QPointF(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPointF(lastPoint);

            QPolygonF polygon;
            polygon<<points[0]<<points[1]<<points[2];
            painter.drawPolygon(polygon);

        }else if (getIsFilledTriangle()){

        QPointF *points = new QPointF[3];
        points[0] = QPointF(firstPoint.x(), lastPoint.y());
        points[1] = QPointF(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
        points[2] = QPointF(lastPoint);

        QPolygonF polygon;
        polygon<<points[0]<<points[1]<<points[2];
        painter.drawPolygon(polygon);
        QBrush fillbrush(currentColor);
        QPainterPath path;
        path.addPolygon(polygon);
        painter.fillPath(path,fillbrush);

    }else if (getIsLine()){
        QPointF *points = new QPointF[3];
        points[0] = QPointF(firstPoint.x(), firstPoint.y());
        points[1] = QPointF(lastPoint.x() , lastPoint.y());

        QPolygonF polygon;
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
    painter.drawImage(QPointF(0, 0), drawPanel);
    setImage(newImage.toImage());
    update();
}

void DrawPanel::clear()
{
    drawPanel.fill(Qt::white);

    update();
    addCommand(getImage());
    redoStack.clear();
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

bool DrawPanel::getIsFullScreen() const
{
    return isFullScreen;
}

void DrawPanel::setIsFullScreen(bool value)
{
    isFullScreen = value;
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
     setPrevColor(getColor());
     brushWidth = setBrushWidth;
     setColor(getPrevColor());
}

int DrawPanel::getBrushWidth()
{
   return brushWidth;
}
QColor DrawPanel::getColor()
{
    return currentColor;
}

void DrawPanel::addCommand(QImage newImage){
    undoStack.push(newImage);
}

void DrawPanel::undoCommand(){

  if(undoStack.length()!=1){
      QImage removedImage= undoStack.top();
      undoStack.pop();
      redoStack.push(removedImage);
      setImage(removedImage);

  }

}
void DrawPanel::redoCommand(){

    if(!redoStack.isEmpty()){
        QImage removedImage= redoStack.top();
        redoStack.pop();
        undoStack.push(removedImage);
        setImage(removedImage);
    }

}
