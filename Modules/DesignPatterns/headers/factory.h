#ifndef FACTORY_H
#define FACTORY_H

#include <QString>
#include <QStringList>
#include "car.h"
#include "headers/builders/alfaromeobuilder.h"
#include "headers/builders/jaguarbuilder.h"
#include "headers/builders/mercedesbuilder.h"
#include "headers/builders/toyotabuilder.h"
#include "headers/builders/ferraribuilder.h"
#include "headers/builders/jelczbuilder.h"
#include "headers/builders/renaultbuilder.h"
#include "headers/builders/volkswagenbuilder.h"
#include "headers/builders/hondabuilder.h"
#include "headers/builders/manbuilder.h"
#include "headers/builders/scaniabuilder.h"
#include "headers/builders/volvobuilder.h"

class Factory
{
public:
    Factory();
    virtual Car * build(QString * brand, QString * color,
                  QString * model, QString * engine,
                  int * power, QStringList * equipment) = 0;
    virtual ~Factory(){}
};

#endif // FACTORY_H
