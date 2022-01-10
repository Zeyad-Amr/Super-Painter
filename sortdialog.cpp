#include "sortdialog.h"
#include "ui_sortdialog.h"
#include "shape.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);

    //Making the table widget
    {
        QTableWidget *table=new QTableWidget(this) ;

        QStringList TableLabel;
        TableLabel<<"Name"<<"Type"<<"Perimter"<<"Area"<<"Thickness"<<"Color"<<"Location";

        table->setColumnCount(7);
        table->setHorizontalHeaderLabels(TableLabel);
        while (table->rowCount() > 0)
        {
            table->removeRow(0);
        }
        // Initializing the Figure Values



        Shape s;
        std::vector<Shape> shapes=s.shapes;
        shapes=sort(shapes);

        for(int i=0;i<shapes.size();i++){

            // Insert New row in the table
            table->insertRow(table->rowCount());

            // Setting the row values
            table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(shapes[i].getTitle()));
            table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(shapes[i].getType()));
            table->setItem(table->rowCount()-1, 2, new QTableWidgetItem(QString::number(shapes[i].getPerimeter())));
            table->setItem(table->rowCount()-1, 3, new QTableWidgetItem(QString::number(shapes[i].getarea())));
            table->setItem(table->rowCount()-1, 4, new QTableWidgetItem(QString::number(shapes[i].getThickness())));
            table->setItem(table->rowCount()-1, 5, new QTableWidgetItem(shapes[i].getColor().name()));
            table->setItem(table->rowCount()-1, 6, new QTableWidgetItem("("+QString::number(shapes[i].getLocation().rx())+","+QString::number(s.shapes[i].getLocation().ry())+")"));




            table->setStyleSheet(
                        "QTableWidget{"
                        "background-color: #C0C0C0;"
                        "alternate-background-color: #606060;"
                        "selection-background-color: #282828;"
                        "}");
            table->setAlternatingRowColors(true);

            //Cell Items Properties
            table->setSelectionMode(QAbstractItemView::SingleSelection);
            table->setSelectionBehavior(QAbstractItemView::SelectRows);
            table->setTextElideMode(Qt::ElideRight);

            //Table Properties
            table->setShowGrid(true);
            table->setGridStyle(Qt::DotLine);
            table->setSortingEnabled(true);
            table->setCornerButtonEnabled(true);

            //H7eader Properties
            table->horizontalHeader()->setVisible(true);
            table->horizontalHeader()->setDefaultSectionSize(150);
            table->horizontalHeader()->setStretchLastSection(true);


        }

    }


}

std::vector<Shape> SortDialog::sort(std::vector<Shape> a){
    std::vector<Shape> shapes=a;


    int i, j;
        for (i = 0; i < shapes.size()-1; i++)

        // Last i elements are already in place
        for (j = 0; j < shapes.size()-i-1; j++)
            if (shapes[j].getPerimeter() > shapes[j+1].getPerimeter())
                swap(&shapes[j], &shapes[j+1]);

        return shapes;

}
void SortDialog::swap(Shape *xp,Shape *yp){

           Shape temp ;
           temp= *xp;
           *xp = *yp;
           *yp = temp;

}


SortDialog::~SortDialog()
{
    delete ui;
}
