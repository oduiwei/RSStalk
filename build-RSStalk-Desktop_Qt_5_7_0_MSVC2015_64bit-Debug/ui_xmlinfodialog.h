/********************************************************************************
** Form generated from reading UI file 'xmlinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMLINFODIALOG_H
#define UI_XMLINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_XMLInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *XMLInfoDialog)
    {
        if (XMLInfoDialog->objectName().isEmpty())
            XMLInfoDialog->setObjectName(QStringLiteral("XMLInfoDialog"));
        XMLInfoDialog->resize(400, 450);
        verticalLayout = new QVBoxLayout(XMLInfoDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(XMLInfoDialog);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(XMLInfoDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        buttonBox->setFont(font1);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(XMLInfoDialog);

        QMetaObject::connectSlotsByName(XMLInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *XMLInfoDialog)
    {
        XMLInfoDialog->setWindowTitle(QApplication::translate("XMLInfoDialog", "Dialog", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("XMLInfoDialog", "\351\200\211\346\213\251\346\202\250\346\203\263\350\246\201\347\232\204\350\256\242\351\230\205", 0));
    } // retranslateUi

};

namespace Ui {
    class XMLInfoDialog: public Ui_XMLInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMLINFODIALOG_H
