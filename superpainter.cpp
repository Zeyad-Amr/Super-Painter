#include "superpainter.h"
#include "./ui_superpainter.h"

SuperPainter::SuperPainter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SuperPainter)
{
    ui->setupUi(this);
}

SuperPainter::~SuperPainter()
{
    delete ui;
}

