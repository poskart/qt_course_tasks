#include "sumprogresswidget.h"

SumProgressWidget::SumProgressWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Sum computation");
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* inputLayout = new QHBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    numberLabel = new QLabel(tr("Enter size of array:"));
    numberEdit = new QLineEdit;

    inputLayout->addWidget(numberLabel);
    inputLayout->addWidget(numberEdit);

    mainLayout->addLayout(inputLayout);

    calculateButton = new QPushButton(tr("Compute sum"));
    abortButton = new QPushButton(tr("Abort"));
    abortButton->setEnabled(false);
    buttonLayout->addWidget(calculateButton);
    buttonLayout->addWidget(abortButton);
    mainLayout->addLayout(buttonLayout);

    resultLabel = new QLabel(tr("Sum"));
    QFont f("Arial", 10, QFont::Bold);
    resultLabel->setFont(f);
    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setTextFormat(Qt::RichText);
    mainLayout->addWidget(resultLabel);

    progressBar = new QProgressBar;
    mainLayout->addWidget(progressBar);
    progressBar->setVisible(false);

    QObject::connect(calculateButton, SIGNAL(clicked()),
                     this, SLOT(validateAndRun()));
    QObject::connect(abortButton, SIGNAL(clicked()),
                     this, SLOT(abort()));
}

void SumProgressWidget::updateProgressBar(int progressPercent)
{
    if(stopped)
        return;
    this->progressBar->setValue(progressPercent);
}

void SumProgressWidget::validateAndRun(){
    bool numberCorrect = false;
    unsigned int n = numberEdit->text().toUInt(&numberCorrect);
    if(numberCorrect){
        int * array = new int[n];
        std::fill_n(array, n, 1);
        stopped = false;
        updateChildWidgets();
        sumTask = new SumRunnable(this, array, n);
        sumTask->setAutoDelete(false);
        QThreadPool::globalInstance()->start(sumTask);
        checkIfDone();
        delete [] array;
    }
    else
        resultLabel->setText("<font color = '#CC0000'>"
                     "You did not enter an usigned 64 bit integer.</font>");
}

void SumProgressWidget::checkIfDone()
{
    if(QThreadPool::globalInstance()->activeThreadCount())
        QTimer::singleShot(100, this, SLOT(checkIfDone()));
    else {
        if(!stopped) {
            stopped = true;
            updateChildWidgets();
            resultLabel->setText(
            "<font color = '#003582'>Sum done</font>");
        }
        if(sumTask){
            delete sumTask;
            sumTask = 0;
        }
    }
}

void SumProgressWidget::updateChildWidgets(void)
{
    if(stopped)
    {
        numberEdit->setEnabled(true);
        calculateButton->setEnabled(true);
        abortButton->setEnabled(false);
        resultLabel->setVisible(true);
        progressBar->reset();
        progressBar->setVisible(false);
    }
    else
    {
        numberEdit->setEnabled(false);
        calculateButton->setEnabled(false);
        abortButton->setEnabled(true);
        resultLabel->setVisible(false);
        progressBar->reset();
        progressBar->setVisible(true);
    }
}

void SumProgressWidget::closeEvent(QCloseEvent *event){
    stopped = true;
    if(QThreadPool::globalInstance()->activeThreadCount())
        QThreadPool::globalInstance()->waitForDone();
    event->accept();
}

void SumProgressWidget::abort(){
    stopped = true;
    if (QThreadPool::globalInstance()->activeThreadCount())
        QThreadPool::globalInstance()->waitForDone();
    updateChildWidgets();
    resultLabel->setText(
    "<font color = '#CC0000'>Calculation aborted.</font>");
    if(sumTask){
        delete sumTask;
        sumTask = 0;
    }
}

SumProgressWidget::~SumProgressWidget(){
    if(sumTask)
        delete sumTask;
}
