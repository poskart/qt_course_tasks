#ifndef ORDERHANDLER_H
#define ORDERHANDLER_H

#include <QObject>
#include "carfactory.h"
#include "truckfactory.h"
#include <QQmlEngine>
#include <QJSEngine>

class OrderHandler : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(OrderHandler)
private:
    QString brand;
    Car::CarType type;
    QString model;
    QString color;
    QString engineType;
    int enginePower;
    QStringList equipment;

public:
    Q_INVOKABLE void prepareOrder();
    Q_INVOKABLE void setCarColor(QString color);
    Q_INVOKABLE void setCarModel(QString model);
    Q_INVOKABLE void setCarType(QString type);
    Q_INVOKABLE void setCarEngine(QString engine);
    Q_INVOKABLE void setCarPower(QString power);
    Q_INVOKABLE void setCarBrand(QString brand);
    Q_INVOKABLE void setCarEquipment(QString equipmentItem);
    Q_INVOKABLE void removeCarEquipment(QString equipmentItem);

    static QObject * qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    OrderHandler(QObject *parent = nullptr) : QObject(parent), factory(nullptr) {}
    ~OrderHandler(){}
    Factory * factory;
};

#endif // ORDERHANDLER_H
