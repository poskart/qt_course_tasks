#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "headers/caroptions.h"
#include "headers/orderhandler.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterSingletonType<CarOptions>("Qt.example.CarOptions",
                                         1, 0, "CarOptions",
                                         &CarOptions::qmlInstance);
    qmlRegisterSingletonType<OrderHandler>("Qt.example.OrderHandler",
                                         1, 0, "OrderHandler",
                                         &OrderHandler::qmlInstance);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
