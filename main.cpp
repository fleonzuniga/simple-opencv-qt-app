/**
*   @file main.cpp
*   Main function
*   @param[in] argc
*   @param[in] argv
*   @param[out] a.exec()
*/
#include "GUI/mainwindow.h"
#include <QApplication>
#include <iostream>
#include "build/config.h"

int main(int argc, char *argv[])
{
    std::cout << "PROJECT:               " << PROJECT << std::endl;
    std::cout << "PROJECT_VERSION:       " << PROJECT_VERSION << std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
