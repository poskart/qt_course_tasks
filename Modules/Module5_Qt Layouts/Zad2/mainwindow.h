#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include "mylayout.h"
#include <QPlainTextEdit>
#include <vector>
#include <QComboBox>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QList<QWidget *> widgets;
    QWidget* mainWidget;
    QVBoxLayout *mainLayout;
    QLabel * sortByLabel;
    QComboBox * sortComboBox;

public slots:
    void rearrangeLayout(QString sortByString);
};

#endif // MAINWINDOW_H
