#include "headers/car.h"

Car::Car():m_type(Car::CAR),
 m_brand(""),
 m_model(""),
 m_engineType(""),
 m_enginePower(0),
 m_color("")
{
    m_equipment = QStringList();
}

Car::Car(Car::CarType type, const QString & brand, const QString & model,
    const QString engineType, int enginePower,
    const QString & color, const QStringList & equipment):
    m_type(type),
    m_brand(brand),
    m_model(model),
    m_engineType(engineType),
    m_enginePower(enginePower),
    m_color(color),
    m_equipment(equipment)
{}

Car::~Car()
{
}

void Car::getType(Car::CarType type)
{
    m_type = type;
}
void Car::getBrand(QString * b)
{
    m_brand = *b;
    delete b;
}
void Car::getModel(QString * m)
{
    m_model = *m;
    delete m;
}
void Car::getEngine(QString * e)
{
    m_engineType = *e;
    delete e;
}
void Car::getPower(int * p)
{
    m_enginePower = *p;
    delete p;
}
void Car::getColor(QString * c)
{
    m_color = *c;
    delete c;
}
void Car::getEquipment(QStringList * eq)
{
    m_equipment = *eq;
    delete eq;
}
