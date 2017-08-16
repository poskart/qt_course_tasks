#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent)
{
    QList<Planet> planetList;
    planetList.append(Planet("Jupiter", 23.1, 1.326));
    planetList.append(Planet("Saturn", 9.0, 0.687));
    planetList.append(Planet("Uranus", 	8.7, 1.271));
    planetList.append(Planet("Neptune", 11.0, 1.638));
    planetList.append(Planet("Earth", 9.8, 5.514));
    planetList.append(Planet("Venus", 8.9, 5.243));
    planetList.append(Planet("Mars", 3.7, 3.933));
    planetList.append(Planet("Mercury", 3.7, 5.427));

    model = new PlanetTableModel(planetList);
    proxyModel = new ProxyModel;
    proxyModel->setSourceModel(model);

    view = new QTableView;
    view->setModel(proxyModel);
    view->verticalHeader()->setMinimumWidth(25);
    view->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->setSortingEnabled(true);
    view->sortByColumn(0, Qt::AscendingOrder);

    createWidgets();
    createLayout();
    createConnections();

    setWindowTitle("Sorting and filtering table data");
    resize(370,370);
}

void MainWindow::createWidgets()
{
    filterGravityLabel = new QLabel("Gravity more than:");
    filterGravitySpinBox = new QDoubleSpinBox;
    filterGravitySpinBox->setValue(0.0);
    filterGravitySpinBox->setSingleStep(2.5);

    filterDensityLabel = new QLabel("Density more than:");
    filterDensitySpinBox = new QDoubleSpinBox;
    filterDensitySpinBox->setValue(0.0);
    filterDensitySpinBox->setSingleStep(0.5);
}

void MainWindow::createLayout(){

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(filterGravityLabel);
    hLayout->addWidget(filterGravitySpinBox);
    hLayout->addWidget(filterDensityLabel);
    hLayout->addWidget(filterDensitySpinBox);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(view);
    vLayout->addLayout(hLayout);

    QGroupBox* filterGroupBox = new QGroupBox(tr("Sorted/Filtered Model"));
    filterGroupBox->setLayout(vLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(filterGroupBox);

    QWidget* widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
}

void MainWindow::createConnections()
{
    QObject::connect(filterGravitySpinBox,
                                SIGNAL(valueChanged(double)),
                                proxyModel,
                                SLOT(setMinGravity(double)));

    QObject::connect(filterDensitySpinBox,
                                SIGNAL(valueChanged(double)),
                                proxyModel,
                                SLOT(setMinDensity(double)));
}
