#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QWidget>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>

const double PI = 3.1415926535897;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void createWidgets(void);
    void createLayout(void);
    double computeCircle(void);
    double computeRectangle(void);
    double computeTriangle(void);
    ~MainWindow();


public slots:
    void computeArea(void);
    void changeParametersDialog(int dstFigure);

private:
    QLabel * figureLabel;
    QLabel * paramLabels[2];
    QLabel * outcomeNameLabel;
    QLabel * outcomeLabel;
    QLineEdit * paramEdits[2];
    QComboBox * figureCombo;
    QLabel * computeLabel;
    QPushButton * computeButton;

    QList<QString> paramNames[3];
};

#endif // MAINWINDOW_H
