#ifndef ANIMAL_H
#define ANIMAL_H
#include <QObject>
#include <QString>

class Animal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(double weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(int maxAge READ maxAge WRITE setMaxAge NOTIFY maxAgeChanged)
    int m_age;

    QString m_name;

    double m_weight;

    QString m_type;

    int m_maxAge;

public:
    explicit Animal(QObject *parent = nullptr);
    explicit Animal(int mAge, QString mName, double mWeight, QString mType, int mMaxAge);

int age() const
{
    return m_age;
}

QString name() const
{
    return m_name;
}

double weight() const
{
    return m_weight;
}

QString type() const
{
    return m_type;
}

int maxAge() const
{
    return m_maxAge;
}

signals:

void ageChanged(int age);

void nameChanged(QString name);

void weightChanged(double weight);

void typeChanged(QString type);

void maxAgeChanged(int maxAge);

public slots:
void setAge(int age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}
void setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
void setWeight(double weight)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_weight, weight))
        return;

    m_weight = weight;
    emit weightChanged(m_weight);
}
void setType(QString type)
{
    if (m_type == type)
        return;

    m_type = type;
    emit typeChanged(m_type);
}
void setMaxAge(int maxAge)
{
    if (m_maxAge == maxAge)
        return;

    m_maxAge = maxAge;
    emit maxAgeChanged(m_maxAge);
}
};

#endif // ANIMAL_H
