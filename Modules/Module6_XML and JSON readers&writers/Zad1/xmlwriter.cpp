#include "xmlwriter.h"


XmlWriter::XmlWriter(QObject *parent) : QObject(parent)
{

}

void XmlWriter::setSourceFile(QString fileName)
{
        m_filename = fileName;
}

bool XmlWriter::isFileDelivered(void)
{
    return !m_filename.isEmpty();
}

QString XmlWriter::readFileToString(void)
{
    QFile xmlFile(m_filename);
    xmlFile.open(QIODevice::ReadOnly);
    QByteArray arr = xmlFile.readAll();

    QString dataAsString = QTextCodec::codecForMib(106)->toUnicode(arr);
    return dataAsString;
}

void XmlWriter::read()
{
    QFile jsonFile(m_filename);
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    list.clear();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    QJsonArray array = document.array();

    foreach (const QJsonValue & v, array)
    {
        QString isbn = v.toObject().value("isbn").toString();
        QString name = v.toObject().value("name").toString();
        QString author = v.toObject().value("author").toString();
        list.append(Book(isbn,
                         name,
                         author));
    }
}

void XmlWriter::insertBook(const Book & book)
{
    m_xml.writeStartElement("book");
    m_xml.writeTextElement("isbn", book.m_isbn);
    m_xml.writeTextElement("isbn", book.m_name);
    m_xml.writeTextElement("isbn", book.m_author);
    m_xml.writeEndElement(); // book
}

QString XmlWriter::convertToXml(void)
{
    read();

    QFile saveFile(QStringLiteral("save.xml"));
    saveFile.open(QIODevice::WriteOnly);
    m_xml.setDevice(&saveFile);

    m_xml.setAutoFormatting(true);
    m_xml.writeStartElement("books");
    for(int i = 0; i < list.size(); i++)
        insertBook(list.at(i));
    m_xml.writeEndElement(); // books
    m_xml.writeEndDocument();

    saveFile.close();

    if (!saveFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return "";
    }
    QString dataAsString = saveFile.readAll();
    return dataAsString;
}
