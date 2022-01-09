#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SearchDialog *ui;
};

#endif // SEARCHDIALOG_H
