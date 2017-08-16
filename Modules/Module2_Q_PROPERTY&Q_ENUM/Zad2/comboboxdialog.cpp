#include "comboboxdialog.h"
#include "ui_comboboxdialog.h"
#include "QMetaEnum"
#include "comboboxdialog.h"
#include "ui_comboboxdialog.h"

ComboBoxDialog::ComboBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComboBoxDialog)
{
    ui->setupUi(this);

    QMetaObject meta = ComboBoxDialog::staticMetaObject;
    QMetaEnum metaEnum = meta.enumerator(0);
    int count = metaEnum.keyCount();
    // Fill the items of the ComboBox
    for(int i = 0; i < count; i++)
    {
        ui->comboBox->addItem(metaEnum.key(i));//("item " + QString::number(i));
    }
}

ComboBoxDialog::~ComboBoxDialog()
{
    delete ui;
}

// Message popup when the button is clicked
void ComboBoxDialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "Item Selection",
                             ui->comboBox->currentText());
    QApplication * a = (QApplication *)QApplication::instance();
    QPalette pal = a->palette();
    QString tmp = ui->comboBox->currentText();
    const char * tmpText = tmp.toStdString().c_str();

    QMetaObject meta = ComboBoxDialog::staticMetaObject;
    QMetaEnum metaEnum = meta.enumerator(0);
    int key = metaEnum.keyToValue(tmpText);
    switch (key)
    {
    case 4:
        pal.setColor(QPalette::Window, Qt::white);
        break;
    case 5:
        pal.setColor(QPalette::Window, Qt::black);
        break;
    case 1:
        pal.setColor(QPalette::Window, Qt::blue);
        break;
    case 0:
        pal.setColor(QPalette::Window, Qt::red);
        break;
    case 2:
        pal.setColor(QPalette::Window, Qt::green);
        break;
    case 3:
        pal.setColor(QPalette::Window, Qt::yellow);
        break;
    }
    a->setPalette(pal);
}
