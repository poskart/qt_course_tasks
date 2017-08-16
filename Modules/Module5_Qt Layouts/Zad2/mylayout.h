#ifndef MYLAYOUT_H
#define MYLAYOUT_H

#include <QLayoutItem>
#include <QVBoxLayout>
#include <QtGui>
#include <QList>
#include <QWidget>

class MyLayout : public QLayout
{
public:
//    MyLayout(QWidget *parent, int dist): QLayout(parent, 0, dist) {}
//    MyLayout(QLayout *parent, int dist): QLayout(parent, dist) {}
//    MyLayout(int dist): QLayout(dist) {}
    MyLayout(QWidget *parent): QLayout(parent) {}
    ~MyLayout();
    void addItem(QLayoutItem *item);
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);
    void setGeometry(const QRect &rect);
private:
    QList<QLayoutItem*> list;
};

#endif // MYLAYOUT_H
