//person.h
#ifndef PERSON_H
#define PERSON_H
#include <QObject>
class Person : public QObject{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.openthinks.dbus.interface")
public:
    explicit Person();
    ~Person();
signals:
    void nameChanged(QString);
    void ageChanged(int);
public slots:
    QString name() const;
    void setName(QString name);
    int age() const;
    void setAge(int age);
private:
    QString m_name;
    int m_age;
};
#endif // PERSON_H
