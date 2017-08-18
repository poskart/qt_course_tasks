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
#include <QTranslator>
#include "TranslatorManager.h"
#include "translation.h"

const double PI = 3.1415926535897;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void createWidgets(void);
    void createLayout(void);
    double computeCircle(void);
    double computeRectangle(void);
    double computeTriangle(void);
    void updateUi(void);
    ~MainWindow();

protected:
    void changeEvent(QEvent *event);

private slots:
    void slotSelectLanguage();

public slots:
    void computeArea(void);
    void changeParametersDialog(int dstFigure);

private:
    Ui::MainWindow* m_ui;
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
