#ifndef SUPERPAINTER_H
#define SUPERPAINTER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SuperPainter; }
QT_END_NAMESPACE

class SuperPainter : public QWidget
{
    Q_OBJECT

public:
    SuperPainter(QWidget *parent = nullptr);
    ~SuperPainter();

private:
    Ui::SuperPainter *ui;
};
#endif // SUPERPAINTER_H
