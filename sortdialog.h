#ifndef SORTDIALOG_H
#define SORTDIALOG_H
#include <QDialog>
#include <QTableWidget>
#include <QHeaderView>
#include <QGraphicsScene>
namespace Ui {
class SortDialog;
}

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    ~SortDialog();

private:
    Ui::SortDialog *ui;
    QTableWidget* table;
};

#endif // SORTDIALOG_H
