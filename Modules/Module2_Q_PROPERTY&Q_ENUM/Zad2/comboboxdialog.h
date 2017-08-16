#ifndef COMBOBOXDIALOG_H
#define COMBOBOXDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ComboBoxDialog;
}

class ComboBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComboBoxDialog(QWidget *parent = 0);
    ~ComboBoxDialog();

    enum MyColor { Red, Blue, Green, Yellow, White, Black };
    Q_ENUM(MyColor)
    void setMyColor(MyColor myColor);
    MyColor myColor() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::ComboBoxDialog *ui;
};

#endif // COMBOBOXDIALOG_H
