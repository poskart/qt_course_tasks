#ifndef TRUCKFACTORY_H
#define TRUCKFACTORY_H

#include "factory.h"
#include "builder.h"

class TruckFactory: public Factory
{
public:
    TruckFactory(): builder(nullptr){}
    ~TruckFactory();
    Builder * getBuilder(QString brand);

    Car * build(QString * brand, QString * color,
                QString * model, QString * engine,
                int * power, QStringList * equipment);
    Car * getCar(void);

    Builder * builder;
};

#endif // TRUCKFACTORY_H
