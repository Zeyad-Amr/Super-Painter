#ifndef DRAWPANEL_H
#define DRAWPANEL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include <QStack>
#include <shape.h>
#include <vector>

class DrawPanel : public QWidget
{
    Q_OBJECT
public:

    explicit DrawPanel(QWidget *parent = nullptr);
    ~DrawPanel() override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    void start();

    bool openImage();

    QImage getImage();
    void setImage(QImage image);

    void resize(int w, int h);

    void clear();

    void setBrushWidth (int setBrushWidth);
    int getBrushWidth ();
    void setColor(QColor setColor);
    QColor getColor();

    QColor getPrevColor() const;
    void setPrevColor(const QColor &value);

    Qt::PenStyle getPenStyle() const;
    void setPenStyle(const Qt::PenStyle &value);

    Qt::PenCapStyle getCapStyle() const;
    void setCapStyle(const Qt::PenCapStyle &value);

    Qt::PenJoinStyle getJoinStyle() const;
    void setJoinStyle(const Qt::PenJoinStyle &value);

    bool getIsRectangle() const;
    void setIsRectangle(bool value);

    bool getIsFilledRectangle() const;
    void setIsFilledRectangle(bool value);

    bool getIsCircle() const;
    void setIsCircle(bool value);

    bool getIsFilledCircle() const;
    void setIsFilledCircle(bool value);

    bool getIsTriangle() const;
    void setIsTriangle(bool value);

    bool getIsFilledTriangle() const;
    void setIsFilledTriangle(bool value);

    bool getIsLine() const;
    void setIsLine(bool value);

    bool getIsErase() const;
    void setIsErase(bool value);

    bool getIsFullScreen() const;
    void setIsFullScreen(bool value);

    QImage getCopyDrawing() const;
    void setCopyDrawing(const QImage &value);

    void addCommand(QImage newImage);
    void redoCommand();
    void undoCommand();


private:
    QImage drawPanel;
    QImage copyDrawing;
    QPointF lastPoint;
    QPointF firstPoint;
    QColor currentColor;
    QColor prevColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;



    int brushWidth;

    bool isDrawing;
    bool isRectangle;
    bool isCircle;
    bool isTriangle;
    bool isLine;
    bool isFilledRectangle;
    bool isFilledCircle;
    bool isFilledTriangle;
    bool isFilling;
    bool isErase;
    bool isFullScreen;

    bool mousePressed;

    QStack<QImage> undoStack;
    QStack<QImage> redoStack;
    Shape *s;



};

#endif // DRAWPANEL_H
