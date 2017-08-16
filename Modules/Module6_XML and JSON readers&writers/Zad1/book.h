#ifndef BOOK_H
#define BOOK_H

#include <QString>

struct Book
{
    QString m_isbn;
    QString m_name;
    QString m_author;

    Book(QString & isbn, QString & name, QString & author)
        : m_isbn(isbn), m_name(name), m_author(author){}
};

#endif // BOOK_H
