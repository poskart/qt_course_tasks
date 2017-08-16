#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QLabel * nameLabel = new QLabel("Name");
    QLabel * lastNameLabel = new QLabel("Last name:");
    QLabel * ageLabel = new QLabel("Age:");
    QLabel * countryLabel = new QLabel("Country:");
    QLabel * sportsHeadLabel = new QLabel("Sports:");
    QLineEdit * nameTextBox = new QLineEdit("John");
    QLineEdit * lastNameTextBox = new QLineEdit("Doe");
    QPlainTextEdit * textEdit1 = new QPlainTextEdit;
    QPlainTextEdit * textEdit2 = new QPlainTextEdit;
    QPlainTextEdit * textEdit3 = new QPlainTextEdit;
    textEdit1->setMaximumHeight(100);
    textEdit1->setMaximumWidth(200);
    textEdit1->setPlainText("First");
    textEdit2->setMaximumHeight(70);
    textEdit2->setMaximumWidth(280);
    textEdit2->setPlainText("Second");
    textEdit3->setMaximumHeight(150);
    textEdit3->setMaximumWidth(120);
    textEdit3->setPlainText("Third");

    sortByLabel = new QLabel("Sort by:");
    sortComboBox = new QComboBox;
    sortComboBox->addItem("Width");
    sortComboBox->addItem("Height");

    widgets.push_back(nameLabel);
    widgets.push_back(lastNameLabel);
    widgets.push_back(ageLabel);
    widgets.push_back(countryLabel);
    widgets.push_back(sportsHeadLabel);
    widgets.push_back(nameTextBox);
    widgets.push_back(lastNameTextBox);
    widgets.push_back(textEdit1);
    widgets.push_back(textEdit2);
    widgets.push_back(textEdit3);


    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(sortByLabel);
    mainLayout->addWidget(sortComboBox);

    for(int i = 0; i < widgets.size(); i++)
        mainLayout->addWidget(widgets.at(i));

    mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    setWindowTitle("My Qt window");
    resize(400,400);

    connect(sortComboBox,
            SIGNAL(currentIndexChanged(QString)),
            this,
            SLOT(rearrangeLayout(QString))
            );
}

MainWindow::~MainWindow()
{

}

void MainWindow::rearrangeLayout(QString sortByString)
{
    for(int i = 0; i < widgets.size(); i++)
        mainLayout->removeWidget(widgets.at(i));
    if(sortByString == "Width")
        std::sort(widgets.begin(), widgets.end(), [](const QWidget * a, const QWidget * b)->bool{return a->width() < b->width();});
    else if (sortByString == "Height")
        std::sort(widgets.begin(), widgets.end(), [](const QWidget * a, const QWidget * b)->bool{return a->height() < b->height();});

    for(int i = 0; i < widgets.size(); i++)
        mainLayout->addWidget(widgets.at(i));
}
