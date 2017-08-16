#include "animal.h"

Animal::Animal(QObject *parent) : QObject(parent)
{

}

Animal::Animal(int mAge, QString mName, double mWeight, QString mType, int mMaxAge):
    m_age(mAge), m_name(mName), m_weight(mWeight), m_type(mType), m_maxAge(mMaxAge)
{

}
