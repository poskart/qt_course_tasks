#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initializeData();
    createWidgets();
    createLayout();

    setWindowTitle("My Qt window");
    resize(400,400);
}

MainWindow::~MainWindow()
{

}

void MainWindow::initializeData(void)
{
    countryNames.append("England");
    countryNames.append("Kenya");
    countryNames.append("Latvia");
    countryNames.append("Lithuania");
    countryNames.append("Malaysia");
    countryNames.append("Poland");
    countryNames.append("Romania");
    countryNames.append("Spain");

    sportNames.append("football");
    sportNames.append("basketball");
    sportNames.append("hockey");
    sportNames.append("cricket");
    sportNames.append("skating");
    sportNames.append("heavy weight lifting");
    sportNames.append("swimming");
    sportNames.append("running");
}

void MainWindow::createWidgets(void)
{
    nameLabel = new QLabel("Name");
    lastNameLabel = new QLabel("Last name:");
    ageLabel = new QLabel("Age:");
    countryLabel = new QLabel("Country:");
    sportsHeadLabel = new QLabel("Sports:");
    nameTextBox = new QLineEdit("John");
    lastNameTextBox = new QLineEdit("Doe");
    for(int i = 0; i < 8; i++)
    {
        sportCheckBoxes[i] = new QCheckBox();
        sportLabels[i] = new QLabel(sportNames.at(i));
    }
    ageSpinBox = new QSpinBox;
    ageSpinBox->setMaximum(100);
    ageSpinBox->setMinimum(10);
    ageSpinBox->setSingleStep(1);
    ageSpinBox->setMaximumWidth(100);
    countryComboBox = new QComboBox;
    countryComboBox->addItems(countryNames);
    countryComboBox->setMaximumWidth(150);
}

void MainWindow::createLayout(void)
{
    QFormLayout *firstSportLayout = new QFormLayout;
    for(int i = 0; i < 4; i++)
        firstSportLayout->addRow(sportCheckBoxes[i], sportLabels[i]);

    QFormLayout *secondSportLayout = new QFormLayout;
    for(int i = 4; i < 8; i++)
        secondSportLayout->addRow(sportCheckBoxes[i], sportLabels[i]);

    QHBoxLayout* mainSportsLayout2 = new QHBoxLayout;
    mainSportsLayout2->addLayout(firstSportLayout);
    mainSportsLayout2->addLayout(secondSportLayout);

    QVBoxLayout* mainSportsLayout1 = new QVBoxLayout;
    mainSportsLayout1->addWidget(sportsHeadLabel);
    mainSportsLayout1->addLayout(mainSportsLayout2);

    QFormLayout * namesAgeCountryLayout = new QFormLayout;
    namesAgeCountryLayout->addRow(nameLabel, nameTextBox);
    namesAgeCountryLayout->addRow(lastNameLabel, lastNameTextBox);
    namesAgeCountryLayout->addRow(ageLabel, ageSpinBox);
    namesAgeCountryLayout->addRow(countryLabel, countryComboBox);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(namesAgeCountryLayout);
    mainLayout->addLayout(mainSportsLayout1);

    QWidget* widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
}
