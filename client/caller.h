//caller.h
#ifndef CALLER_H
#define CALLER_H
#include <QDBusConnection>
#include <QDBusReply>
#include <QDebug>
#include <QObject>
class Caller : public QObject
{
    Q_OBJECT
public:
    explicit Caller(QObject *parent = nullptr);
    void callByMsg();//call method by dbus message
    void callByInterface();//call method by dbus interface
    void callAsync();//call method as async
signals:
public slots:
    void callFinishedSlot(QDBusPendingCallWatcher *call);//async mecthod callback
    void onNameChanged(QString name);//signal callback
};
#endif // CALLER_H
