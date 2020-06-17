//person.cpp
#include "person.h"
#include <QObject>

Person::Person(){
}
Person::~Person(){
}
QString Person::name() const{
    return m_name;
}
void Person::setName(QString name){
    this->m_name=name;
    emit nameChanged(name);
}
int Person::age() const{
    return m_age;
}

void Person::setAge(int age){
    this->m_age=age;
}
