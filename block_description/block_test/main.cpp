#include "mainwindow.h"
#include <simblock.h>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{    
#ifdef CREATE_BLOCK
    //код запускается в режиме создания тестового блока
    //полный класс записывается в json-файл
    std::cout << "Start program in CREATING_TEST_BLOCK mode" << std::endl;

    SimBlock block1;
    SimBlock block2("block");

    return 0;
#else
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
#endif

}
