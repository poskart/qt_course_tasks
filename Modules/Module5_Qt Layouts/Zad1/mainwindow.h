#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initializeData(void);
    void createWidgets(void);
    void createLayout(void);

private:
    QLabel * nameLabel;
    QLabel * lastNameLabel;
    QLabel * ageLabel;
    QLabel * countryLabel;
    QLabel * sportsHeadLabel;
    QLabel * sportLabels[8];
    QLineEdit * nameTextBox;
    QLineEdit * lastNameTextBox;
    QCheckBox * sportCheckBoxes[8];
    QSpinBox * ageSpinBox;
    QComboBox * countryComboBox;

    QStringList countryNames;
    QStringList sportNames;
};

#endif // MAINWINDOW_H
