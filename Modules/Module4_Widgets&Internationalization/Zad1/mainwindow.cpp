#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Circle
    paramNames[0].append(tr("Radius: "));
    // Rectangle
    paramNames[1].append(tr("Side a: "));
    paramNames[1].append(tr("Side b: "));
    // Triangle
    paramNames[2].append(tr("Base: "));
    paramNames[2].append(tr("Height: "));


    createWidgets();
    createLayout();

    connect(computeButton, SIGNAL(clicked(bool)), this, SLOT(computeArea(void)));
    connect(figureCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeParametersDialog(int)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createWidgets(void)
{
    figureLabel = new QLabel(tr("Figure: "));
    paramLabels[0] = new QLabel(tr("Side a: "));
    paramLabels[1] = new QLabel(tr("Side b: "));
    outcomeNameLabel = new QLabel(tr("Outcome ="));
    outcomeLabel = new QLabel("");
    paramEdits[0] = new QLineEdit;
    paramEdits[1] = new QLineEdit;
    figureCombo = new QComboBox;
    figureCombo->addItem(tr("Circle"));
    figureCombo->addItem(tr("Rectangle"));
    figureCombo->addItem(tr("Triangle"));
    figureCombo->setCurrentIndex(1);
    computeLabel = new QLabel(tr("Compute: "));
    computeButton = new QPushButton(tr("Compute"));
}

void MainWindow::createLayout(void)
{
    QFormLayout *firstLayout = new QFormLayout;
    firstLayout->addRow(figureLabel, figureCombo);
    for(int i = 0; i < 2; i++)
        firstLayout->addRow(paramLabels[i], paramEdits[i]);
    firstLayout->addRow(computeLabel, computeButton);
    firstLayout->addRow(outcomeNameLabel, outcomeLabel);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(firstLayout);

    QWidget* widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
}

void MainWindow::changeParametersDialog(int dstFigure)
{
    if(paramNames[dstFigure].size() < 2)
    {
        paramLabels[1]->hide();
        paramEdits[1]->hide();
    }
    else
    {
        paramLabels[1]->show();
        paramEdits[1]->show();
    }
    for(int i = 0; i < paramNames[dstFigure].size(); i++)
    {
        paramLabels[i]->setText(paramNames[dstFigure].at(i));
    }
}

double MainWindow::computeCircle(void)
{
    bool correctConv;
    double radius = paramEdits[0]->text().toDouble(&correctConv);
    if(correctConv)
        return PI * radius * radius;
    else
        return -1.0;
}

double MainWindow::computeRectangle(void)
{
    bool correctConv1, correctConv2;
    double sideA = paramEdits[0]->text().toDouble(&correctConv1);
    double sideB = paramEdits[1]->text().toDouble(&correctConv2);

    if(correctConv1 && correctConv2)
        return sideA * sideB;
    else
        return -1.0;
}

double MainWindow::computeTriangle(void)
{
    bool correctConv1, correctConv2;
    double base = paramEdits[0]->text().toDouble(&correctConv1);
    double height = paramEdits[1]->text().toDouble(&correctConv2);

    if(correctConv1 && correctConv2)
        return base * height / 2;
    else
        return -1.0;
}

void MainWindow::computeArea(void)
{
    double outcome;
    if(figureCombo->currentIndex() == 0)
        outcome = computeCircle();
    else if(figureCombo->currentIndex() == 1)
        outcome = computeRectangle();
    else if(figureCombo->currentIndex() == 2)
        outcome = computeTriangle();
    else return;

    outcomeLabel->setText(QString::number(outcome));
}
