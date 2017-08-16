#include "../headers/truckfactory.h"

TruckFactory::~TruckFactory()
{
    if(builder != nullptr)
        delete builder;
}
Builder * TruckFactory::getBuilder(QString brand)
{
    if(brand == "Jelcz")
        return new JelczBuilder();
    else if(brand == "Man")
        return new ManBuilder();
    else if(brand == "Scania")
        return new ScaniaBuilder();
    else if(brand == "Renault")
        return new RenaultBuilder();
    else if(brand == "Volvo")
        return new VolvoBuilder();
    else
        return nullptr;
}

Car * TruckFactory::build(QString * brand, QString * color,
            QString * model, QString * engine,
            int * power, QStringList * equipment)
{
    builder = getBuilder(*brand);
    builder->setParams(color, model, engine, power, equipment);
    return getCar();
    delete builder;
}

Car * TruckFactory::getCar(void)
{
    Car * car = new Car();
    car->getType(builder->getType());
    car->getBrand(builder->getBrand());
    car->getModel(builder->getModel());
    car->getEngine(builder->getEngine());
    car->getPower(builder->getPower());
    car->getColor(builder->getColor());
    car->getEquipment(builder->getEquipment());

    return car;
}
