#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>
#include<QString>
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
   QString name= ui->lineEdit->text();

   Shape s;

 int index=  search(s.shapes,name,s.shapes.size());

 Shape myShape=s.shapes[index];

   QMessageBox::information(this,"Search Result","Name:\t"+myShape.getTitle()+"\nType:\t"+myShape.getType()+"\nPerimeter:\t"+QString::number(myShape.getPerimeter())+"\nArea:\t"+QString::number(myShape.getarea())+"\nColor:\t"+myShape.getColor().name()+"\nThickmess:\t"+QString::number(myShape.getThickness())+"\nLocation:\t("+QString::number(myShape.getLocation().rx())+","+QString::number(myShape.getLocation().ry())+")");

}

int SearchDialog::search(std::vector<Shape> arr, QString x,int n){


            int l = 0 ;
            int r = n - 1;
            while (l <= r)
            {
                int m = l + (r - l) / 2;

            int res = -1000;   //some random value assigned because if res is already 0 then
                                 //it will always return 0
            if (x == (arr[m].getTitle()))
                res = 0;


                // Check if x is present at mid
                if (res == 0)
                    return m;

                // If x greater, ignore left half
                if (x > (arr[m].getTitle()))
                    l = m + 1;

                // If x is smaller, ignore right half
                else
                    r = m - 1;
            }

            return -1;


}


