/********************************************************************************
** Form generated from reading UI file 'renamedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEDIALOG_H
#define UI_RENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_renameDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *renameDialog)
    {
        if (renameDialog->objectName().isEmpty())
            renameDialog->setObjectName(QStringLiteral("renameDialog"));
        renameDialog->resize(400, 133);
        verticalLayout_2 = new QVBoxLayout(renameDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(renameDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(renameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), renameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), renameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(renameDialog);
    } // setupUi

    void retranslateUi(QDialog *renameDialog)
    {
        renameDialog->setWindowTitle(QApplication::translate("renameDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("renameDialog", "\351\207\215\345\221\275\345\220\215", 0));
        label->setText(QApplication::translate("renameDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\347\232\204\345\220\215\347\247\260\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class renameDialog: public Ui_renameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEDIALOG_H
