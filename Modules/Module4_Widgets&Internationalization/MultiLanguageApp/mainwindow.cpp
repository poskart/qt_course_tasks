#include <QDesktopWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "translation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    // Circle
    paramNames[0].append(qtTrId(ID_RADIUS));
    // Rectangle
    paramNames[1].append(qtTrId(ID_SIDEA));
    paramNames[1].append(qtTrId(ID_SIDEB));
    // Triangle
    paramNames[2].append(qtTrId(ID_BASE));
    paramNames[2].append(qtTrId(ID_HEIGHT));


    createWidgets();
    createLayout();

    connect(computeButton, SIGNAL(clicked(bool)), this, SLOT(computeArea(void)));
    connect(figureCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(changeParametersDialog(int)));

    connect(m_ui->actionSelect_Language,SIGNAL(triggered()), this, SLOT(slotSelectLanguage()));
    this->move(QApplication::desktop()->screen()->rect().center()-this->rect().center());
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::slotSelectLanguage()
{
    Dialog dlg(this);
    dlg.exec();
}

/* If you dynamically change the language in your application,
 * a changeEvent of type QEvent::LanguageChange is emitted.
 * You have to catch that and reset your text everywhere.
 */
void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        // Set all text.
        setWindowTitle(qtTrId(ID_APP_TITLE));
        m_ui->menuFile->setTitle(qtTrId(ID_MENU_FILE));
        m_ui->menuSettings->setTitle(qtTrId(ID_MENU_SETTINGS));
        m_ui->actionOpen->setText(qtTrId(ID_MENU_FILE_OPEN));
        m_ui->actionSave->setText(qtTrId(ID_MENU_FILE_SAVE));
        m_ui->actionClose->setText(qtTrId(ID_MENU_FILE_CLOSE));
        m_ui->action_Exit->setText(qtTrId(ID_MENU_FILE_EXIT));
        m_ui->actionSelect_Language->setText(qtTrId(ID_MENU_SETTINGS_SELECT));

        updateUi();
    }
    else
    {
        QMainWindow::changeEvent(event);
    }
}

void MainWindow::createWidgets(void)
{
    figureLabel = new QLabel(qtTrId(ID_FIGURE_NAME));
    paramLabels[0] = new QLabel(qtTrId(ID_RECT_PARAM1));
    paramLabels[1] = new QLabel(qtTrId(ID_RECT_PARAM2));
    outcomeNameLabel = new QLabel(qtTrId(ID_OUTCOME));
    outcomeLabel = new QLabel("");
    paramEdits[0] = new QLineEdit;
    paramEdits[1] = new QLineEdit;
    figureCombo = new QComboBox;
    figureCombo->addItem(qtTrId(ID_CIRCLE));
    figureCombo->addItem(qtTrId(ID_RECT));
    figureCombo->addItem(qtTrId(ID_TRIAN));
    figureCombo->setCurrentIndex(1);
    computeLabel = new QLabel(qtTrId(ID_COMPUTE));
    computeButton = new QPushButton(qtTrId(ID_COMPUTE));
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

void MainWindow::updateUi(void)
{
    // Circle
    paramNames[0].clear();
    paramNames[0].append(qtTrId(ID_RADIUS));
    // Rectangle
    paramNames[1].clear();
    paramNames[1].append(qtTrId(ID_SIDEA));
    paramNames[1].append(qtTrId(ID_SIDEB));
    // Triangle
    paramNames[2].clear();
    paramNames[2].append(qtTrId(ID_BASE));
    paramNames[2].append(qtTrId(ID_HEIGHT));

    figureLabel->setText(qtTrId(ID_FIGURE_NAME));
    figureLabel->update();
    paramLabels[0]->setText(qtTrId(ID_RECT_PARAM1));
    paramLabels[0]->update();
    paramLabels[1]->setText(qtTrId(ID_RECT_PARAM2));
    paramLabels[1]->update();
    outcomeNameLabel->setText(qtTrId(ID_OUTCOME));
    outcomeNameLabel->update();

    figureCombo->setItemText(0, qtTrId(ID_CIRCLE));
    figureCombo->setItemText(1, qtTrId(ID_RECT));
    figureCombo->setItemText(2, qtTrId(ID_TRIAN));
    figureCombo->update();

    computeLabel->setText(qtTrId(ID_COMPUTE));
    computeLabel->update();
    computeButton->setText(qtTrId(ID_COMPUTE));
    computeLabel->update();
}
