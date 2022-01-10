#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "searchdialog.h"

#include <QColorDialog>
#include <QScrollArea>

#include <QAction>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QUndoView>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      drawpanel(new DrawPanel(this)){
    ui->setupUi(this);


    QWidget *window = new QWidget;
    QVBoxLayout *vLayout = new QVBoxLayout(window);

    vLayout->addWidget(drawpanel);

    setCentralWidget(window);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete drawpanel;
}

int MainWindow::openDialog(){

    QMessageBox dialog(QMessageBox::Question, tr("PaintQT"), tr("Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Yes"));
    dialog.setButtonText(QMessageBox::No, tr("No"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Cancel"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
}

void MainWindow::on_actionPen_color_triggered()
{
    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Pick a color"), QColorDialog::ShowAlphaChannel);
    drawpanel->setColor(customColor);
}

void MainWindow::on_actionSave_triggered()
{
    QImage saveDrawing = drawpanel->getImage();
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");
    saveDrawing.save(filePath);
}

void MainWindow::on_actionPen_size_triggered()
{
    bool correct = false;

    int brushWidth=drawpanel->getBrushWidth();
    int size = QInputDialog::getInt(this, "Set pen size", "Pen size",brushWidth , 0, 50, 1, &correct);

    if (correct && size!=0){
        drawpanel->setBrushWidth(size);
    }
}

void MainWindow::on_actionErase_triggered()
{
    if(ui->actionErase->isChecked() == true)
    {
       drawpanel->setPrevColor(drawpanel->getColor());
       drawpanel->setColor(Qt::white);

       ui->actionCircle->setChecked(false);
       ui->actionRectangle->setChecked(false);
       ui->actionTriangle->setChecked(false);
       ui->actionLine->setChecked(false);
       ui->actionFilledCircle->setChecked(false);
       ui->actionFilledRectangle->setChecked(false);
       ui->actionFilledTriangle->setChecked(false);
       ui->actionErase->setChecked(true);
       drawpanel->setIsCircle(false);
       drawpanel->setIsRectangle(false);
       drawpanel->setIsTriangle(false);
       drawpanel->setIsLine(false);
       drawpanel->setIsFilledCircle(false);
       drawpanel->setIsFilledRectangle(false);
       drawpanel->setIsFilledTriangle(false);
       drawpanel->setIsErase(true);
    }
    if(ui->actionErase->isChecked() == false)
    {
        drawpanel->setColor(drawpanel->getPrevColor());

        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}

void MainWindow::on_actionRectangle_triggered()
{
    if(ui->actionRectangle->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(true);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(true);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
    if(ui->actionRectangle->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}

void MainWindow::on_actionCircle_triggered()
{
    if(ui->actionCircle->isChecked() == true)
    {
        ui->actionCircle->setChecked(true);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(true);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
    if(ui->actionCircle->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}

void MainWindow::on_actionTriangle_triggered()
{
    if(ui->actionTriangle->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(true);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(true);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
    if(ui->actionTriangle->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);
        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}

void MainWindow::on_actionLine_triggered()
{
    if(ui->actionLine->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(true);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(true);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
    if(ui->actionLine->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}


void MainWindow::on_actionFilledCircle_triggered()
{
    if(ui->actionFilledCircle->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(true);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(true);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
    if(ui->actionFilledCircle->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}


void MainWindow::on_actionFilledRectangle_triggered()
{
    if(ui->actionFilledRectangle->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(true);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(true);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
    if(ui->actionFilledRectangle->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}


void MainWindow::on_actionFilledTriangle_triggered()
{
    if(ui->actionFilledTriangle->isChecked() == true)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(true);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(true);
        drawpanel->setIsErase(false);
    }
    if(ui->actionFilledTriangle->isChecked() == false)
    {
        ui->actionCircle->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionTriangle->setChecked(false);
        ui->actionLine->setChecked(false);
        ui->actionFilledCircle->setChecked(false);
        ui->actionFilledRectangle->setChecked(false);
        ui->actionFilledTriangle->setChecked(false);
        ui->actionErase->setChecked(false);

        drawpanel->setIsCircle(false);
        drawpanel->setIsRectangle(false);
        drawpanel->setIsTriangle(false);
        drawpanel->setIsLine(false);
        drawpanel->setIsFilledCircle(false);
        drawpanel->setIsFilledRectangle(false);
        drawpanel->setIsFilledTriangle(false);
        drawpanel->setIsErase(false);
    }
}


void MainWindow::on_actionOpen_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionSave_triggered();
       drawpanel->openImage();
    }
    else if(dialog == QMessageBox::No)
    {
        drawpanel->openImage();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionNew_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionSave_triggered();
       drawpanel->start();
       update();
    }
    else if(dialog == QMessageBox::No)
    {
        drawpanel->start();
        update();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionClose_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionSave_triggered();
       QApplication::quit();
    }
    else if(dialog == QMessageBox::No)
    {
        QApplication::quit();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}

void MainWindow::on_actionResize_triggered()
{
    Resize resize;
    resize.setWidth(drawpanel->getImage().width());
    resize.setHeight(drawpanel->getImage().height());
    if(resize.exec() == QDialog::Accepted)
    {
        int nWidth = resize.getWidth();
        int nHeight = resize.getHeight();

        drawpanel->resize(nWidth, nHeight);
    }

}

//void MainWindow::on_actionFill_with_coor_triggered()
//{
//    if(ui->actionFill_with_coor->isChecked() == true)
//    {
//        drawpanel->setIsFilling(true);
//    }
//    else if(ui->actionFill_with_coor->isChecked() == false)
//    {
//        drawpanel->setIsFilling(false);
//    }
//}

//void MainWindow::on_actionFill_color_triggered()
//{
//    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Pick a fill color"), QColorDialog::ShowAlphaChannel);
//    drawpanel->setFillColor(customColor);
//}

void MainWindow::on_actionCut_triggered()
{
    drawpanel->setCopyDrawing(drawpanel->getImage());
    drawpanel->clear();
    ui->actionPaste->setEnabled(true);
}

void MainWindow::on_actionPaste_triggered()
{
    drawpanel->setImage(drawpanel->getCopyDrawing());
    QPainter painter;
    painter.drawImage(0,0, drawpanel->getImage());
}

void MainWindow::on_actionAbout_PaintQT_triggered()
{
    About aboutDialog;
    aboutDialog.exec();
}

void MainWindow::on_actionZoom_2_triggered()
{
    Zoom zoomDialog;
    if(zoomDialog.exec() == QDialog::Accepted)
    {
        int zoom = zoomDialog.getZoom();

        int newW = drawpanel->getImage().width() * zoom / 100;
        int newH = drawpanel->getImage().height() * zoom / 100;

        QImage zoomedImage = drawpanel->getImage();

        drawpanel->clear();
        drawpanel->resize(newW, newH);

        drawpanel->setImage(zoomedImage.scaled(newW, newH, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}




void MainWindow::on_actionFull_Screen_triggered(){
    isFullScreen() ? showNormal() : showFullScreen();

}


void MainWindow::on_actionUndo_triggered()
{
    drawpanel->undoCommand();
}


void MainWindow::on_actionRedo_triggered()
{
     drawpanel->redoCommand();
}


void MainWindow::on_actionSearch_triggered()
{
   SearchDialog searchdialogue;
   //searchdialogue.setModal(true);
   searchdialogue.exec();

}


void MainWindow::on_actionSort_triggered()
{


}

