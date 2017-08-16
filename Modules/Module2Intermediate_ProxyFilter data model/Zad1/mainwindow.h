#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "planettablemodel.h"
#include "proxymodel.h"
#include <QHeaderView>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QGroupBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QTableView* view;
    PlanetTableModel* model;
    ProxyModel* proxyModel;

    QLabel* filterGravityLabel;
    QLabel* filterDensityLabel;
    QDoubleSpinBox* filterGravitySpinBox;
    QDoubleSpinBox* filterDensitySpinBox;

    void createWidgets();
    void createConnections();
    void createLayout();
};
#endif // MAINWINDOW_H
