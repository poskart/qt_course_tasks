#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QObject>
#include <QXmlStreamWriter>
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "book.h"

class XmlWriter : public QObject
{
    Q_OBJECT
public:
    explicit XmlWriter(QObject *parent = nullptr);
    void read();

    Q_INVOKABLE
    bool isFileDelivered(void);

private:
    void processBooks();
    void processBook();

    QString m_filename;
    QXmlStreamWriter m_xml;
    QList<Book> list;

signals:

public slots:
    QString readFileToString(void);
    void setSourceFile(QString fileName);
    void insertBook(const Book & book);
    QString convertToXml(void);
};

#endif // XMLWRITER_H
