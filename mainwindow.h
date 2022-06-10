#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Save_clicked();

    void on_Open_clicked();

    void on_Convert_clicked();

private:
    QString direct;
    QPixmap originalimage;
    QImage image;
    int labelWidth;
    int pixWidth;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
