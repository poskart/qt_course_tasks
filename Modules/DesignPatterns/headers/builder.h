#ifndef BUILDER_H
#define BUILDER_H

#include <QString>
#include <QStringList>
#include "car.h"

class Builder
{
public:
    Builder(){}
    virtual ~Builder(){}
    virtual QString * getBrand() = 0;
    virtual Car::CarType getType() = 0;
    virtual QString * getModel() = 0;
    virtual QString * getEngine() = 0;
    virtual QString * getColor() = 0;
    virtual int * getPower() = 0;
    virtual QStringList * getEquipment() = 0;

    void setParams(QString * color, QString * model,
                   QString * engine, int * power,
                   QStringList * equipment);

    QString * m_color;
    QString * m_model;
    QString * m_engine;
    int * m_power;
    QStringList * m_equipment;
};
#endif // BUILDER_H
