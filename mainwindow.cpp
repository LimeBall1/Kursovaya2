#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labelWidth = ui->label->width();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Save_clicked()
{
    QString savedirect = QFileDialog::getSaveFileName(0,tr("Save File"),"/edited picture",tr("Images(*.png;*.jpg;*.jpeg)"));
    image.save(savedirect);
}


void MainWindow::on_Open_clicked()
{
    direct = QFileDialog::getOpenFileName(0,tr("openfile"),"C:/","Image Files ;*.png;*.jpg;*.jpeg");
    originalimage.load(direct);
    ui->label->setPixmap(originalimage);
    pixWidth = originalimage.width();
    double factor = double (labelWidth)/pixWidth;
    ui->label->setFixedWidth (factor * ui->label->pixmap().width());
    ui->label->setFixedHeight(factor * ui->label->pixmap().height());
    ui ->label->setScaledContents(true);
}


void MainWindow::on_Convert_clicked()
{
    image = QImage(direct);
    int height=image.rect().bottom();
    int width=image.rect().right();
    for (int h=0;h<=height;h++)
        for (int w=0;w<=width;w++){
            QColor col(image.pixel(w,h));
            int r=255-col.red();
            int g=255-col.green();
            int b=255-col.blue();
            col.setRgb(r,g,b,0);
            image.setPixel(w,h,col.rgb());
        }
            ui->label_2->setPixmap(QPixmap::fromImage(image));
            double factor = double (labelWidth)/pixWidth;
            ui->label_2->setFixedWidth (factor * ui->label->pixmap().width());
            ui->label_2->setFixedHeight(factor * ui->label->pixmap().height());
            ui ->label_2->setScaledContents(true);


}
