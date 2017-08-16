#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "animal.h"
#include <QQuickView>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<Animal>("com.mod14.animal", 1, 0, "Animal");

    QList<QObject*> dataList;
    dataList.append(new Animal(12, "Cheetah", 70, "Mammal", 25));
    dataList.append(new Animal(5, "Stork", 10.5, "Bird", 10));
    dataList.append(new Animal(24, "Elephant", 5500, "Mammal", 60));
    dataList.append(new Animal(12, "Anaconda", 180, "Reptile", 30));
    dataList.append(new Animal(42, "Rhinoceros", 2000, "Mammal", 50));

    QQmlApplicationEngine engine;

    QQmlContext * ctxt = engine.rootContext();
    ctxt->setContextProperty("myCppListModel", QVariant::fromValue(dataList));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
