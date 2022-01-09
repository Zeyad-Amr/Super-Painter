#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>
SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}


void SearchDialog::on_pushButton_clicked()
{
   QString name="Variable";

   QMessageBox::information(this,"Search Result","Name:\t"+name+"\nType:\t"+name+"\nDimensions:\t"+name+"\nPerimeter:\t"+name+"\nArea:\t"+name+"\nColour:\t"+name+"\nThickmess:\t"+name+"\nLocation:\t"+name);

}



