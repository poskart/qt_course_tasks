#include "../headers/carfactory.h"

CarFactory::~CarFactory()
{
    if(builder != nullptr)
        delete builder;
}
Builder * CarFactory::getBuilder(QString brand)
{
    if(brand == "Jaguar")
        return new JaguarBuilder();
    else if(brand == "Alfa Romeo")
        return new AlfaRomeoBuilder();
    else if(brand == "Ferrari")
        return new FerrariBuilder();
    else if(brand == "Honda")
        return new HondaBuilder();
    else if(brand == "Mercedes")
        return new MercedesBuilder();
    else if(brand == "Toyota")
        return new ToyotaBuilder();
    else if(brand == "Volkswagen")
        return new VolkswagenBuilder();
    else
        return nullptr;
}

Car * CarFactory::build(QString * brand, QString * color,
            QString * model, QString * engine,
            int * power, QStringList * equipment)
{
    builder = getBuilder(*brand);
    if(builder == nullptr)
        return nullptr;

    builder->setParams(color, model, engine, power, equipment);
    return getCar();
    delete builder;
}

Car * CarFactory::getCar(void)
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
