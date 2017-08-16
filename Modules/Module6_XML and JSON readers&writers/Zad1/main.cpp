#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "xmlreader.h"
#include "xmlwriter.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<XmlReader>("com.mod14.xmlreader", 1, 0, "XmlReader");
    qmlRegisterType<XmlReader>("com.mod14.xmlwriter", 1, 0, "XmlWriter");

    QQmlApplicationEngine engine;

    XmlReader * reader = new XmlReader();
    XmlWriter * writer = new XmlWriter();

    QQmlContext * ctxt = engine.rootContext();
    ctxt->setContextProperty("xmlReaderObj", QVariant::fromValue(reader));
    ctxt->setContextProperty("xmlWriterObj", QVariant::fromValue(writer));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;



    return app.exec();
}
