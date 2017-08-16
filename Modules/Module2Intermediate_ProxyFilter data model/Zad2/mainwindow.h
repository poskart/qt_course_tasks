#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QLabel>
#include <QCheckBox>
#include <QPlainTextEdit>
#include <QFileSystemModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHeaderView>

#include "myfilesystemmodel.h"
#include "proxymodel.h"
#include "file.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTableView* view;
    MyFileSystemModel * model;
    ProxyModel * proxyModel;

    QLabel * limitLabel;
    QLabel * graterLabel;
    QPlainTextEdit * filterTextBox;
    QCheckBox * treshCheckBox;

    void createWidgets();
    void createConnections();
    void createLayout();

public slots:
    void readTexBox(void);
};

#endif // MAINWINDOW_H
