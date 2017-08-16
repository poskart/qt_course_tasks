#ifndef VOLKSWAGENBUILDER_H
#define VOLKSWAGENBUILDER_H

#include "../builder.h"

class VolkswagenBuilder : public Builder
{
public:
    QString * getBrand()
    {
        QString * brand = new QString("Volkswagen");
        return brand;
    }

    Car::CarType getType()
    {
        return Car::CAR;
    }

    QString * getModel()
    {
        QString * model = new QString(*m_model);
        return model;
    }

    QString * getEngine()
    {
        QString * engine = new QString(*m_engine);
        return engine;
    }

    QString * getColor()
    {
        QString * color = new QString(*m_color);
        return color;
    }

    int * getPower()
    {
        int * power = new int(*m_power);
        return power;
    }

    QStringList * getEquipment()
    {
        QStringList * newEqList = new QStringList(*m_equipment);
        return newEqList;
    }
};

#endif
