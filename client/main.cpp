//main.cpp
#include <QCoreApplication>
#include "caller.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Caller caller;
    caller.callByMsg();
    caller.callByInterface();
    caller.callAsync();
    return a.exec();
}
