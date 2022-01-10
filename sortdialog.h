#ifndef SORTDIALOG_H
#define SORTDIALOG_H
#include <QDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QGraphicsScene>
#include "shape.h"
namespace Ui {
class SortDialog;
}

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    ~SortDialog();
    std::vector<Shape> sort(std::vector<Shape> a);
    void swap(Shape *xp,Shape *yp);

private:
    Ui::SortDialog *ui;
    QTableWidget* table;
};

#endif // SORTDIALOG_H
