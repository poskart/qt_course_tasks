#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>
#include <QXmlStreamReader>
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "book.h"

class XmlReader : public QObject
{
    Q_OBJECT
public:
    explicit XmlReader(QObject *parent = nullptr);
    void read();

    Q_INVOKABLE
    bool isFileDelivered(void);

private:
    void processBooks();
    void processBook();

    QString m_filename;
    QXmlStreamReader m_xml;
    QList<Book> list;

signals:

public slots:
    QString readFileToString(void);
    void setSourceFile(QString fileName);
    QString convertToJson(void);
};


#endif // XMLREADER_H
