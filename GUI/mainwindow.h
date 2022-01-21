#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "../build/config.h"
#include "../VideoCapture/videoCapture.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MyVideoCapture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_initButton_clicked();

private:
    Ui::MainWindow *ui;
    MyVideoCapture *mVideoCapture;
};
#endif // MAINWINDOW_H
