#ifndef SUMRUNNABLE_H
#define SUMRUNNABLE_H

#include <QRunnable>
#include <QMetaObject>
#include <QWidget>
#include <QProgressBar>

class SumRunnable : public QRunnable
{
public:
    SumRunnable(QWidget * wdg, int * array, int _n);
    ~SumRunnable(){}
    void run(void);
private:
    QWidget * progressWidget;
    int * arr;
    int n;
};

#endif // SUMRUNNABLE_H
