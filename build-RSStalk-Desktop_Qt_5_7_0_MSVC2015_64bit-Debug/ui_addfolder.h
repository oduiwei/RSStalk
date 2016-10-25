/********************************************************************************
** Form generated from reading UI file 'addfolder.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFOLDER_H
#define UI_ADDFOLDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddFolderDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *folderNameLabel;
    QLineEdit *folderNameLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddFolderDialog)
    {
        if (AddFolderDialog->objectName().isEmpty())
            AddFolderDialog->setObjectName(QStringLiteral("AddFolderDialog"));
        AddFolderDialog->resize(457, 107);
        horizontalLayout_2 = new QHBoxLayout(AddFolderDialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        folderNameLabel = new QLabel(AddFolderDialog);
        folderNameLabel->setObjectName(QStringLiteral("folderNameLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        folderNameLabel->setFont(font);
        folderNameLabel->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(folderNameLabel);

        folderNameLineEdit = new QLineEdit(AddFolderDialog);
        folderNameLineEdit->setObjectName(QStringLiteral("folderNameLineEdit"));

        horizontalLayout->addWidget(folderNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(AddFolderDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(AddFolderDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddFolderDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddFolderDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddFolderDialog);
    } // setupUi

    void retranslateUi(QDialog *AddFolderDialog)
    {
        AddFolderDialog->setWindowTitle(QApplication::translate("AddFolderDialog", "Dialog", 0));
        folderNameLabel->setText(QApplication::translate("AddFolderDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\345\273\272\345\210\206\347\261\273\347\232\204\345\220\215\347\247\260\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFolderDialog: public Ui_AddFolderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFOLDER_H
