#include "mylayout.h"

MyLayout::~MyLayout()
{
     QLayoutItem *item;
     while ((item = takeAt(0)))
         delete item;
}

int MyLayout::count() const
{
    // QList::size() returns the number of QLayoutItems in the list
    return list.size();
}

QLayoutItem *MyLayout::itemAt(int idx) const
{
    // QList::value() performs index checking, and returns 0 if we are
    // outside the valid range
    return list.value(idx);
}
QLayoutItem *MyLayout::takeAt(int idx)
{
    // QList::take does not do index checking
    return idx >= 0 && idx < list.size() ? list.takeAt(idx) : 0;
}

void MyLayout::addItem(QLayoutItem *item)
{
    list.append(item);
}

void MyLayout::setGeometry(const QRect &r)
{
    QLayout::setGeometry(r);
//    QVBoxLayout::setGeometry(r);
    if (list.size() == 0)
        return;
    int w = r.width() - (list.count() - 1) * spacing();
    int h = r.height() - (list.count() - 1) * spacing();
    int i = 0;
    QWidget * currWidget;
    while (i < list.size())
    {
        QLayoutItem *o = list.at(i);
        currWidget = (QWidget *)o;
        QRect geom(r.x() + spacing(), r.y() + 2* i * spacing(), w, h + 50);
        o->setGeometry(geom);
        ++i;
    }
}

QSize MyLayout::sizeHint() const
{
    QSize s(0,0);
    int n = list.count();
    if (n > 0)
        s = QSize(100,70); //start with a nice default size
    int i = 0;
    while (i < n) {
        QLayoutItem *o = list.at(i);
        s = s.expandedTo(o->sizeHint());
        ++i;
    }
    return s + n*QSize(spacing(), spacing());
}

QSize MyLayout::minimumSize() const
{
    QSize s(0,0);
    int n = list.count();
    int i = 0;
    while (i < n) {
        QLayoutItem *o = list.at(i);
        s = s.expandedTo(o->minimumSize());
        ++i;
    }
    return s + n*QSize(spacing(), spacing());
}
