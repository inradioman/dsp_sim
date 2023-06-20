#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{    
#ifdef CREATE_BLOCK
    //код запускается в режиме создания тестового блока
    //полный класс записывается в json-файл
#endif
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
