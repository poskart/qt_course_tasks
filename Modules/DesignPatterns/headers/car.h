#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QStringList>

class Car
{
public:
    enum CarType{
        CAR,
        TRUCK,
    };

    Car();
    Car(CarType type, const QString & brand, const QString & model,
        const QString engineType, int enginePower,
        const QString & color, const QStringList & equipment);
    ~Car();

    void getType(Car::CarType type);
    void getBrand(QString * b);
    void getModel(QString * m);
    void getEngine(QString * e);
    void getPower(int * p);
    void getColor(QString * c);
    void getEquipment(QStringList * eq);

    CarType m_type;
    QString m_brand;
    QString m_model;
    QString m_engineType;
    int m_enginePower;
    QString m_color;
    QStringList m_equipment;
};

#endif // CAR_H
