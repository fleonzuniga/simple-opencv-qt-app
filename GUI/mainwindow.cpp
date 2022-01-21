/**
*   @file MainWindow.cpp
*   MainWindow class
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString appName(PROJECT);
    QString appVersion(PROJECT_VERSION);
    this->setWindowTitle(appName + " " + appVersion);

    ui->labelFrame->setMinimumWidth(mVideoCapture->getWidth());
    ui->labelFrame->setMinimumHeight(mVideoCapture->getHeight());

    mVideoCapture = new MyVideoCapture(this);
    connect(mVideoCapture,&MyVideoCapture::newPixmapCaptured,this,[&]()
    {
        ui->labelFrame->setPixmap(mVideoCapture->pixmap());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    mVideoCapture->terminate();
}

void MainWindow::on_initButton_clicked()
{
    mVideoCapture->start(QThread::HighestPriority);
}
