#ifndef CAROPTIONS_H
#define CAROPTIONS_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include "car.h"

class CarOptions : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(CarOptions)
public:
    Q_INVOKABLE const QStringList getEngineTypes(void);
    Q_INVOKABLE const QStringList getEnginePowersCars(void);
    Q_INVOKABLE const QStringList getEnginePowersTrucks(void);
    Q_INVOKABLE const QStringList getCarColors(void);
    Q_INVOKABLE const QStringList getCarBrands(void);
    Q_INVOKABLE const QStringList getTruckBrands(void);
    Q_INVOKABLE const QStringList getCarModels(void);
    Q_INVOKABLE const QStringList getEquipment(void);

    Q_INVOKABLE int getEquipmentCount(void) const;
    Q_INVOKABLE const QString getEquipment(int index);
    Q_INVOKABLE int getLongestEqNameWidth() const;

    static QObject * qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
    {
        Q_UNUSED(engine);
        Q_UNUSED(scriptEngine);
        return new CarOptions;
    }

signals:

private:
    CarOptions(QObject *parent = nullptr);

    QStringList colors;
    QStringList engineTypes;
    QStringList enginePowersCars;
    QStringList enginePowersTrucks;
    QStringList carBrands;
    QStringList carModels;
    QStringList truckBrands;
    QStringList optionalEquipmentList;
};

#endif // CAROPTIONS_H
