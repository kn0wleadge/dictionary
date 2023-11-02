#include "dictionary.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    std::cout<<"kill me"<<std::endl;
    QApplication a(argc, argv);
    dictionary w;
    w.show();
    return a.exec();
}
