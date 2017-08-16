#ifndef SUMRUNNABLE_H
#define SUMRUNNABLE_H

#include <QRunnable>
#include <QMetaObject>
#include <QWidget>
#include <QProgressBar>
#include <QThread>

class SumRunnable : public QRunnable
{
public:
    SumRunnable(QWidget * wdg, int * array, int _n,
                int * outTab, int id);
    ~SumRunnable();
    void run(void);
private:
    QWidget * progressWidget;
    int * arr;
    int n;
    int * outcomeTab;
    int threadId;
    int begIdx;
};

#endif // SUMRUNNABLE_H
