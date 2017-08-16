#ifndef CARFACTORY_H
#define CARFACTORY_H

#include "factory.h"
#include "builder.h"

class CarFactory : public Factory
{
public:
    CarFactory(): builder(nullptr){}
    ~CarFactory();
    Builder * getBuilder(QString brand);
    Car * build(QString * brand, QString * color,
                QString * model, QString * engine,
                int * power, QStringList * equipment);

    Car * getCar(void);

    Builder * builder;
};

#endif // CARFACTORY_H
