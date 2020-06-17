#include <QCoreApplication>
#include <QtDBus/QDBusConnection>
#include "person.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDBusConnection sessionBus = QDBusConnection::sessionBus();
    if(sessionBus.registerService("com.openthinks.dbus.service")){
        sessionBus.registerObject("/",new Person,QDBusConnection::ExportAllContents);
        qDebug()<<"registerService successful";
    }
    else
        qDebug()<<"registerService failed";
    return a.exec();
}
