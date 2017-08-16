#include "sumrunnable.h"

SumRunnable::SumRunnable(QWidget * wdg, int * array, int _n):
    progressWidget(wdg), arr(array), n(_n)
{

}

void SumRunnable::run(void)
{
    qulonglong sum = 0;
    for(qlonglong i = 0; i < n; i++)
    {
        sum += arr[i];

        if(i % 10 == 0)
            QMetaObject::invokeMethod(progressWidget, "updateProgressBar",
                                  Qt::QueuedConnection,
                                  Q_ARG(int, i*100/n));
        for(int j = 0; j < 100000; j++);
    }
}
