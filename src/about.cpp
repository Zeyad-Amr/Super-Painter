#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->plainTextEdit->document()->setPlainText("PaintQT\n\n"
                                                "Application written in C++, using QT.\nOriginally made for passing 'Multiplatform programming in QT' subject at studies.\n\n"
                                                "Version 1.0.0, © 2019 Jakub Zięba");
}

About::~About()
{
    delete ui;
}
