//caller.cpp
#include "caller.h"
#include <QDBusInterface>
Caller::Caller(QObject *parent) : QObject(parent)
{
    //receive signal method 1
//    QDBusConnection::sessionBus().connect("com.openthinks.dbus.service", "/","com.openthinks.dbus.interface","nameChanged", this,SLOT(onNameChanged(QString)));
    //receive signal method 2
    QDBusInterface *interface=new QDBusInterface("com.openthinks.dbus.service","/","com.openthinks.dbus.interface",QDBusConnection::sessionBus());
    QObject::connect(interface, SIGNAL(nameChanged(QString)),this, SLOT(onNameChanged(QString)));
}
void Caller::callByMsg(){
    QDBusMessage msg = QDBusMessage::createMethodCall("com.openthinks.dbus.service","/","com.openthinks.dbus.interface","setName");
    msg<<QString("Alex");
    QDBusMessage response = QDBusConnection::sessionBus().call(msg);
    msg = QDBusMessage::createMethodCall("com.openthinks.dbus.service","/","com.openthinks.dbus.interface","name");
    response = QDBusConnection::sessionBus().call(msg);
    if(response.type()== QDBusMessage::ReplyMessage){
        QString name = response.arguments().takeFirst().toString();
        qDebug()<<"name = "<< name;
    }
}
void Caller::callByInterface(){
    QDBusInterface interface("com.openthinks.dbus.service","/","com.openthinks.dbus.interface");
    interface.call("setName","Jack");
    QDBusReply<QString> reply = interface.call("name");
    if(reply.isValid()){
        qDebug()<<"name = "<< reply.value();
    }else{
        qDebug()<<"reply not valid.";
    }
    interface.call("setName","Bluce");
    reply = interface.call("name");
    if(reply.isValid()){
        qDebug()<<"name = "<< reply.value();
    }else{
        qDebug()<<"reply not valid.";
    }
}
void Caller::callAsync(){
    QDBusInterface interface("com.openthinks.dbus.service","/","com.openthinks.dbus.interface");
    QDBusPendingCall async = interface.asyncCall("setName","Trump");
    async=interface.asyncCall("name");
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(async,this);
    QObject::connect(watcher,SIGNAL(finished(QDBusPendingCallWatcher*)),this,SLOT(callFinishedSlot(QDBusPendingCallWatcher*)));
}
void Caller::callFinishedSlot(QDBusPendingCallWatcher *call){
    QDBusPendingReply<QString> reply = *call;
    if(!reply.isError()){
        QString name = reply.argumentAt<0>();
        qDebug()<<"name = "<<name;
    }
    call->deleteLater();
}
void Caller::onNameChanged(QString name){
     qDebug()<<"received signal nameChanged : name =  "<<name;

}
