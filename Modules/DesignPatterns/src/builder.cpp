#include "../headers/builder.h"

void Builder::setParams(QString * color, QString * model,
               QString * engine, int * power,
               QStringList * equipment)
{
    m_color = color;
    m_model = model;
    m_engine = engine;
    m_power = power;
    m_equipment = equipment;
}
