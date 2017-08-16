#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "message.h"
#include <QQuickView>
#include <QQmlContext>
#include "messageboard.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    Message msg;
    view.engine()->rootContext()->setContextProperty("msg", &msg);
    view.setSource(QUrl::fromLocalFile("main.qml"));
    view.show();

    return app.exec();
}
