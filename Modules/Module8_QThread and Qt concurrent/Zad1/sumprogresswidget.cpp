#include "sumprogresswidget.h"

SumProgressWidget::SumProgressWidget(QWidget *parent)
    : QWidget(parent), numberOfThreads(1)
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
    numberOfThreads = QThread::idealThreadCount();
    int * outcomeTab = new int[numberOfThreads];
    std::fill_n(outcomeTab, numberOfThreads, 0);
    unsigned int n = numberEdit->text().toUInt(&numberCorrect);
    if(numberCorrect){
        //sumTasks = new SumRunnable*[numberOfThreads];
        int * array = new int[n];
        unsigned int elementsCount = n;
        unsigned int singleThreadElemCount = n/numberOfThreads;
        unsigned int firstIdx = 0;
        int totalSum = 0;
        unsigned freeThreads = numberOfThreads;
        std::fill_n(array, n, 1);
        stopped = false;
        updateChildWidgets();
        for(int i = 0; i < numberOfThreads; i++)
        {
            sumTasks.push_back(new SumRunnable(this, &array[firstIdx],
                                      singleThreadElemCount,
                                      outcomeTab, i));
            sumTasks[i]->setAutoDelete(false);
            QThreadPool::globalInstance()->start(sumTasks[i]);

            firstIdx += singleThreadElemCount;
            elementsCount -= singleThreadElemCount;
            --freeThreads;
            if(freeThreads)
                singleThreadElemCount = elementsCount/freeThreads;
        }
        checkIfDone();

        updateChildWidgets();
        for(int i = 0; i < numberOfThreads; i++)
            totalSum += outcomeTab[i];
        resultLabel->setText(
        "Sum done: " + QString::number(totalSum));

        delete [] outcomeTab;
        delete [] array;
    }
    else
        resultLabel->setText("<font color = '#CC0000'>"
                     "You did not enter an usigned 64 bit integer.</font>");
}

void SumProgressWidget::checkIfDone(void)
{
    if(QThreadPool::globalInstance()->waitForDone())
    {
        if(!stopped)
        {
            stopped = true;
            updateChildWidgets();
        }
        for(int i = 0; i < numberOfThreads; i++)
        {
            if(sumTasks[i])
            {
                delete sumTasks[i];
                sumTasks[i] = 0;
            }
        }
        sumTasks.clear();
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

    for(int i = 0; i < numberOfThreads; i++)
    {
        if(sumTasks[i]){
            delete sumTasks[i];
            sumTasks[i] = 0;
        }
    }
    sumTasks.clear();
}

SumProgressWidget::~SumProgressWidget(){
    for(int i = 0; i < numberOfThreads; i++)
    {
        if(sumTasks[i]){
            delete sumTasks[i];
            sumTasks[i] = 0;
        }
    }
    sumTasks.clear();
}
