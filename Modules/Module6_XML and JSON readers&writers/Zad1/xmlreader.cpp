#include "xmlreader.h"

XmlReader::XmlReader(QObject *parent) : QObject(parent)
{

}

void XmlReader::setSourceFile(QString fileName)
{
        m_filename = fileName;
}

bool XmlReader::isFileDelivered(void)
{
    return !m_filename.isEmpty();
}

QString XmlReader::readFileToString(void)
{
    QFile xmlFile(m_filename);
    xmlFile.open(QIODevice::ReadOnly);

    QString dataAsString = xmlFile.readAll();
    return dataAsString;
}

void XmlReader::read()
{
    QFile xmlFile(m_filename);
    xmlFile.open(QIODevice::ReadOnly);
    m_xml.setDevice(&xmlFile);

    list.clear();

    if (m_xml.readNextStartElement() && m_xml.name() == "books")
       processBooks();

    if (m_xml.tokenType() == QXmlStreamReader::Invalid)
        m_xml.readNext();

    if (m_xml.hasError())
    {
        m_xml.raiseError();
    }
}

void XmlReader::processBooks() {
    if (!m_xml.isStartElement() || m_xml.name() != "books")
        return;
    while (m_xml.readNextStartElement()) {
        if (m_xml.name() == "book")
            processBook();
        else
            m_xml.skipCurrentElement();
    }
}

void XmlReader::processBook() {
    if (!m_xml.isStartElement() || m_xml.name() != "book")
        return;
    QString isbn, name, author;
    while (m_xml.readNextStartElement()) {
        if (m_xml.name() == "isbn")  {
            m_xml.readNext();
            isbn = m_xml.text().toString(); }
        else if (m_xml.name() == "name") {
            m_xml.readNext();
            name = m_xml.text().toString(); }
        else if (m_xml.name() == "author") {
            m_xml.readNext();
            author = m_xml.text().toString(); }

        m_xml.skipCurrentElement();
    }
    if (!(isbn.isEmpty() || name.isEmpty() || author.isEmpty()))
        list.append(Book(isbn, name, author));
}

QString XmlReader::convertToJson(void)
{
    read();
    QJsonObject json;
    QJsonArray jsonArray;
    for(int i = 0; i < list.size(); i++)
    {
        json["isbn"] = list.at(i).m_isbn;
        json["name"] = list.at(i).m_name;
        json["author"] = list.at(i).m_author;
        jsonArray.append(json);
    }

    QFile saveFile(QStringLiteral("save.json"));
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open save file.");
        return "";
    }
    // … write array to json file
    QJsonDocument saveDoc(jsonArray);
    saveFile.write(saveDoc.toJson());
    saveFile.close();

    if (!saveFile.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open save file.");
        return "";
    }

    QString dataAsString = saveFile.readAll();
    return dataAsString;
}
