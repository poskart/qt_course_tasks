#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)
    QString m_author;

public:
    explicit Message(QObject *parent = nullptr);

    QString author() const
    {
        return m_author;
    }

signals:

    void authorChanged(QString author);

public slots:
    void setAuthor(QString author)
    {
        if (m_author == author)
            return;

        m_author = author;
        emit authorChanged(m_author);
    }
};

#endif // MESSAGE_H
