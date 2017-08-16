#ifndef FILE_H
#define FILE_H

#include <QString>

struct File{
    File(const QString & _name = QString(), const qint64 _size = 0, const QString & _type = QString()):
        name(_name), size(_size), type(_type)
    {}
    QString name;
    qint64 size;
    QString type;
};

#endif // FILE_H
