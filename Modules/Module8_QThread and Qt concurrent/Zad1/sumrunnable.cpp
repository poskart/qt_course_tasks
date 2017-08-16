#include "sumrunnable.h"

SumRunnable::SumRunnable(QWidget * wdg, int * array, int _n,
                         int * outTab, int id):
    progressWidget(wdg), arr(array), n(_n), outcomeTab(outTab),
    threadId(id)
{

}

SumRunnable::~SumRunnable()
{
    progressWidget = nullptr;
    arr = nullptr;
    outcomeTab = nullptr;
}

void SumRunnable::run(void)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if( (threadId == 0) && (i % 10 == 0))
            QMetaObject::invokeMethod(progressWidget, "updateProgressBar",
                                  Qt::DirectConnection,
                                  Q_ARG(int, i*100/n));
        for(int j = 0; j < 100000; j++);
    }
    outcomeTab[threadId] = sum;
}

