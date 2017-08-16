#ifndef SUMPROGRESSWIDGET_H
#define SUMPROGRESSWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QThreadPool>
#include <QTimer>
#include <QCloseEvent>
#include "sumrunnable.h"
#include <vector>
#include <QDebug>

class SumProgressWidget : public QWidget
{
    Q_OBJECT

public:
    SumProgressWidget(QWidget *parent = 0);
    ~SumProgressWidget();
    void updateChildWidgets(void);
    void closeEvent(QCloseEvent *event);
private:
    QLabel* numberLabel;
    QLabel* resultLabel;
    QLineEdit* numberEdit;
    QPushButton* calculateButton;
    QPushButton* abortButton;
    QProgressBar* progressBar;

    volatile bool stopped;
    int numberOfThreads;
    std::vector<SumRunnable *> sumTasks;
private slots:
    void abort();
    void validateAndRun();
    void checkIfDone();
public slots:
    void updateProgressBar(int progressPercent);
};

#endif // SUMPROGRESSWIDGET_H
