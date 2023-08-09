#include "brauerdemo.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BrauerDemo w;
    w.show();
    return a.exec();
}
