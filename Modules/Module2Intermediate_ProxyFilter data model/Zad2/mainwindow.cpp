#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

//    for(int i = 0; i < 3; i++)
//    {
//        fileList.append(File("Nazwa"+QString::number(i), i, "COstam"+QString::number(i*i)));
//    }

     //    QList<File> fileList;
     //    QModelIndex idx = fsModel->index(fsModel->rootPath());
     //    qint64 i = fsModel->rowCount(idx);
     //    qint64 sizzz = fsModel->size(idx);
     //    for(int i = 0; i < fsModel->rowCount(idx); i++)
     //    {
     //        auto child = idx.child(i, idx.column());
     //        fileList.append(File(fsModel->fileName(child), fsModel->size(child), fsModel->type(child)));
     //    }
//    model = myQListView.model()
//    idx = model.index(model.rootPath())
//    for i in range(0, model.rowCount(idx)):
//        child = idx.child(i, idx.column())
//        print model.fileName(child)

//    for_each()//(i = fsModel->index(path, 0); i.row() < fsModel->rowCount(); i++)
//    {
//        fileList.append(File(fsModel->fileName(i), fsModel->size(i), fsModel->type(i)));
//    }

    model = new MyFileSystemModel();
    proxyModel = new ProxyModel;
    proxyModel->setSourceModel(model);

    view = new QTableView(this);
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

MainWindow::~MainWindow()
{

}

void MainWindow::createWidgets()
{

    limitLabel = new QLabel("Name/size filtering:");
    graterLabel = new QLabel("Grater(checked)/less(unchecked)");
    filterTextBox = new QPlainTextEdit;
    //filterTextBox->width()
    treshCheckBox = new QCheckBox;
    treshCheckBox->setChecked(true);
}

void MainWindow::createLayout(){

    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(limitLabel);
    hLayout->addWidget(filterTextBox);
    hLayout->addWidget(graterLabel);
    hLayout->addWidget(treshCheckBox);

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

void MainWindow::readTexBox(void)
{
    bool convertedToDouble;
    double newSizeValue = (filterTextBox->toPlainText()).toDouble(&convertedToDouble);
    if(convertedToDouble)
    {
        proxyModel->setTresholdSize(newSizeValue);
        proxyModel->setSizeNameFlag(true);
        treshCheckBox->show();
        graterLabel->show();
    }
    else
    {
        QString name = QString::fromStdString((filterTextBox->toPlainText()).toStdString());
        proxyModel->setTresholdName(name);
        proxyModel->setSizeNameFlag(false);
        treshCheckBox->hide();
        graterLabel->hide();
    }
}

void MainWindow::createConnections()
{
    QObject::connect(filterTextBox,
                                SIGNAL(textChanged(void)),
                                this,
                                SLOT(readTexBox(void)));
    QObject::connect(treshCheckBox,
                                SIGNAL(stateChanged(int)),
                                proxyModel,
                                SLOT(setTresholdDirection(int)));
}

