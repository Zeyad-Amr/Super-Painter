#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);

    //Making the table widget
    {
        QTableWidget *table=new QTableWidget(this) ;

        QStringList TableLabel;
        TableLabel<<"Name"<<"Type"<<"Perimter"<<"LineWeight"<<"Color";

        table->setColumnCount(5);
        table->setHorizontalHeaderLabels(TableLabel);
        while (table->rowCount() > 0)
        {
            table->removeRow(0);
        }
        // Initializing the Figure Values
        QString name="aa";
        QString Type= "bb";
        QString Perimeter = "cc";
        QString linewidth = "dd";
        QString linecolor ="ff";


        // Insert New row in the table
        table->insertRow(table->rowCount());

        // Setting the row values
        table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(name));
        table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(Type));
        table->setItem(table->rowCount()-1, 2, new QTableWidgetItem(Perimeter));
        table->setItem(table->rowCount()-1, 3, new QTableWidgetItem(linewidth));
        table->setItem(table->rowCount()-1, 4, new QTableWidgetItem(linecolor));



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

        //Header Properties
        table->horizontalHeader()->setVisible(true);
        table->horizontalHeader()->setDefaultSectionSize(150);
        table->horizontalHeader()->setStretchLastSection(true);



//        for(auto* item:*shapesMemory){
//            // Initializing the Figure Values
//            QString name= item->Shape::getname();
//            QString Type= item->Shape::getshapeType();
//            QString Perimeter = QString::number(item->Shape::get_perimeter());
//            QString linewidth = QString::number(item->Shape::pen.width());
//            QString linecolor = (item->Shape::pen.color()).name();


//            // Insert New row in the table
//            table->insertRow(table->rowCount());

//            // Setting the row values
//            table->setItem(table->rowCount()-1, 0, new QTableWidgetItem(name));
//            table->setItem(table->rowCount()-1, 1, new QTableWidgetItem(Type));
//            table->setItem(table->rowCount()-1, 2, new QTableWidgetItem(Perimeter));
//            table->setItem(table->rowCount()-1, 3, new QTableWidgetItem(linewidth));
//            table->setItem(table->rowCount()-1, 4, new QTableWidgetItem(linecolor));



//            table->setStyleSheet(
//                        "QTableWidget{"
//                        "background-color: #C0C0C0;"
//                        "alternate-background-color: #606060;"
//                        "selection-background-color: #282828;"
//                        "}");
//            table->setAlternatingRowColors(true);

//            //Cell Items Properties
//            table->setSelectionMode(QAbstractItemView::SingleSelection);
//            table->setSelectionBehavior(QAbstractItemView::SelectRows);
//            table->setTextElideMode(Qt::ElideRight);

//            //Table Properties
//            table->setShowGrid(true);
//            table->setGridStyle(Qt::DotLine);
//            table->setSortingEnabled(true);
//            table->setCornerButtonEnabled(true);

//            //Header Properties
//            table->horizontalHeader()->setVisible(true);
//            table->horizontalHeader()->setDefaultSectionSize(150);
//            table->horizontalHeader()->setStretchLastSection(true);


//        }

    }


}

SortDialog::~SortDialog()
{
    delete ui;
}
