#include "dictionary.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dictionary w;
    w.show();
    return a.exec();
}
