#include "sumprogresswidget.h"
#include <QApplication>
#include "sumprogresswidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SumProgressWidget w;
    w.show();

    return a.exec();
}
