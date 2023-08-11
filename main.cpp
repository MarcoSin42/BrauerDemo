#include "brauerdemo.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qputenv("QT_ASSUME_STDERR_HAS_CONSOLE", "1"); // This is dumb, why is this necessary for qDebug??  Find out why

    BrauerDemo w;
    w.show();
    return a.exec();
}
