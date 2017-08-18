#include <QCoreApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include <QCheckBox>
#include <QToolButton>
#include <QTranslator>

#include "dialog.h"
#include "TranslatorManager.h"
#include "translation.h"

bool  myglobal = true;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    m_label = new QLabel();
    if (m_label)
    {
        QFont font("Sans Serif", 18, QFont::Bold);
        m_label->setFont(font);
        m_label->setAlignment(Qt::AlignCenter);
        m_label->setText(qtTrId(ID_LABEL_TEXT));
    }
    QStringList list;
    list.append(qtTrId(ID_COMBO_ITEM_1));
    list.append(qtTrId(ID_COMBO_ITEM_2));

    m_combo = createCombobox(list);
    if (m_combo)
    {
        connect(m_combo, SIGNAL(currentIndexChanged(int)), this, SLOT(slotComboChanged(int)));
    }

    m_cancelBtn = createButton();
    if (m_cancelBtn)
    {
        connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(slotAcceptParameters()));
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_combo);
    mainLayout->addWidget(m_label);
    mainLayout->addWidget(m_cancelBtn);
    setLayout(mainLayout);
    resize(400, 300);
}

Dialog::~Dialog()
{
}

void Dialog::slotAcceptParameters()
{
    close();
}

QComboBox* Dialog::createCombobox(QStringList& list, QWidget* parent)
{
    QComboBox* comboBox = new QComboBox(parent);

    if (comboBox)
    {
        QFont font("Sans Serif", 18, QFont::Bold);
        comboBox->setFont(font);
        // Populate the combo box.
        foreach(QString s, list)
        {
            comboBox->addItem(s, s);
        }

        QString lang = TranslatorManager::instance()->getCurrentLang();
        int index = 0;
        if (lang.compare("pl_PL") == 0)
        {
            index = 1;
        }
        comboBox->setCurrentIndex(index);
    }

    return comboBox;
}

void Dialog::slotComboChanged(int n)
{
    QString lang;

    if (n == 1)
    {
        lang = "pl_PL";
    }
    else
    {
        lang = "en_US";
    }

    TranslatorManager::instance()->setTranslator(lang);
    this->updateUI();
}

void Dialog::updateUI()
{
    if (m_label)
    {
        m_label->setText(qtTrId(ID_LABEL_TEXT));
    }

    if (m_cancelBtn)
    {
        m_cancelBtn->setText(qtTrId(ID_BUTTON_TEXT_1));
        m_cancelBtn->update();
    }


    if (m_combo)
    {
        m_combo->setItemText(0, qtTrId(ID_COMBO_ITEM_1));
        m_combo->setItemText(1, qtTrId(ID_COMBO_ITEM_2));
        m_combo->update();
    }
}

QToolButton* Dialog::createButton()
{
    QToolButton* saveBtn = new QToolButton();
    if (saveBtn)
    {
        saveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        saveBtn->setText(qtTrId(ID_BUTTON_TEXT_1));
    }

    return saveBtn;
}
