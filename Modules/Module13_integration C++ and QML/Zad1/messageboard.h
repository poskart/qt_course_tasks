#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QObject>
#include <QDebug>

class MessageBoard : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE bool postMessage(const QString &msg) {
        qDebug() << "Called the C++ method with" << msg;
        return true;
    }
public slots:
    void refresh() {
        qDebug() << "Called the C++ slot";
    }
};

#endif // MESSAGEBOARD_H
