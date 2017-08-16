#include "../headers/orderhandler.h"

#include <QDebug>
void OrderHandler::prepareOrder()
{
    if(type == Car::CAR)
        factory = new CarFactory();
    else if(type == Car::TRUCK)
        factory = new TruckFactory();

    Car * newCar =
            factory->build(
                &brand, &color, &model, &engineType, &enginePower, &equipment);
    if(newCar != nullptr)
    {
        qDebug()<<"Car manufactured!";
        qDebug()<<newCar->m_brand;
        qDebug()<<newCar->m_model;
        qDebug()<<newCar->m_color;
        qDebug()<<newCar->m_engineType;
        qDebug()<<newCar->m_enginePower;
        qDebug()<<"Equipment: "<<newCar->m_equipment;
    }
    else
    {
        qDebug()<<"Car manufacturing failed...";
    }

    delete factory;
}

QObject * OrderHandler::qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);
    return new OrderHandler;
}

void OrderHandler::setCarColor(QString color)
{
    this->color = color;
}

void OrderHandler::setCarModel(QString model)
{
    this->model = model;
}

void OrderHandler::setCarType(QString type)
{
    if(type == "Car")
        this->type = Car::CAR;
    else if(type == "Truck")
        this->type = Car::TRUCK;
}

void OrderHandler::setCarEngine(QString engine)
{
    this->engineType = engine;
}

void OrderHandler::setCarPower(QString power)
{
    this->enginePower = power.toInt();
}

void OrderHandler::setCarBrand(QString brand)
{
    this->brand = brand;
}

void OrderHandler::setCarEquipment(QString equipmentItem)
{
    if(std::find(equipment.begin(), equipment.end(), equipmentItem) ==
            equipment.end())
        this->equipment.push_back(equipmentItem);
}

void OrderHandler::removeCarEquipment(QString equipmentItem)
{
    QStringList::iterator it;
    if((it = std::find(equipment.begin(), equipment.end(), equipmentItem)) !=
            equipment.end())
        this->equipment.erase(it);
}
