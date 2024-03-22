/********************************************************************************
** Form generated from reading UI file 'pkgselect.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PKGSELECT_H
#define UI_PKGSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pkgselect
{
public:
    QGridLayout *gridLayout;
    QRadioButton *minimal_button;
    QLabel *minimal_text;
    QLabel *extraparty_text;
    QSpacerItem *pushup;
    QRadioButton *normal_button;
    QScrollArea *extraparty_scroll;
    QWidget *extraparty_scrollhouse;
    QVBoxLayout *verticalLayout;
    QCheckBox *element_button;
    QLabel *element_text;
    QCheckBox *thunderbird_button;
    QLabel *thunderbird_text;
    QCheckBox *virtmanager_button;
    QLabel *virtmanager_text;
    QCheckBox *krita_button;
    QLabel *krita_text;
    QSpacerItem *pushup_tiny;
    QCheckBox *updates_button;
    QLabel *updates_text;
    QRadioButton *full_button;
    QSpacerItem *verticalSpacer;
    QLabel *party_text;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QLabel *apps_label;
    QLabel *full_text;
    QCheckBox *party_button;
    QLabel *normal_text;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *pkgselect)
    {
        if (pkgselect->objectName().isEmpty())
            pkgselect->setObjectName(QString::fromUtf8("pkgselect"));
        pkgselect->resize(830, 573);
        gridLayout = new QGridLayout(pkgselect);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        minimal_button = new QRadioButton(pkgselect);
        minimal_button->setObjectName(QString::fromUtf8("minimal_button"));
        QFont font;
        font.setPointSize(12);
        minimal_button->setFont(font);

        gridLayout->addWidget(minimal_button, 6, 1, 1, 1);

        minimal_text = new QLabel(pkgselect);
        minimal_text->setObjectName(QString::fromUtf8("minimal_text"));
        QFont font1;
        font1.setPointSize(10);
        font1.setItalic(true);
        minimal_text->setFont(font1);

        gridLayout->addWidget(minimal_text, 7, 1, 1, 1);

        extraparty_text = new QLabel(pkgselect);
        extraparty_text->setObjectName(QString::fromUtf8("extraparty_text"));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setWeight(50);
        extraparty_text->setFont(font2);

        gridLayout->addWidget(extraparty_text, 15, 1, 1, 1);

        pushup = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(pushup, 17, 1, 1, 1);

        normal_button = new QRadioButton(pkgselect);
        normal_button->setObjectName(QString::fromUtf8("normal_button"));
        normal_button->setFont(font);
        normal_button->setChecked(true);

        gridLayout->addWidget(normal_button, 4, 1, 1, 1);

        extraparty_scroll = new QScrollArea(pkgselect);
        extraparty_scroll->setObjectName(QString::fromUtf8("extraparty_scroll"));
        extraparty_scroll->setWidgetResizable(true);
        extraparty_scrollhouse = new QWidget();
        extraparty_scrollhouse->setObjectName(QString::fromUtf8("extraparty_scrollhouse"));
        extraparty_scrollhouse->setGeometry(QRect(0, -80, 741, 208));
        verticalLayout = new QVBoxLayout(extraparty_scrollhouse);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        element_button = new QCheckBox(extraparty_scrollhouse);
        element_button->setObjectName(QString::fromUtf8("element_button"));

        verticalLayout->addWidget(element_button);

        element_text = new QLabel(extraparty_scrollhouse);
        element_text->setObjectName(QString::fromUtf8("element_text"));
        element_text->setFont(font1);

        verticalLayout->addWidget(element_text);

        thunderbird_button = new QCheckBox(extraparty_scrollhouse);
        thunderbird_button->setObjectName(QString::fromUtf8("thunderbird_button"));

        verticalLayout->addWidget(thunderbird_button);

        thunderbird_text = new QLabel(extraparty_scrollhouse);
        thunderbird_text->setObjectName(QString::fromUtf8("thunderbird_text"));
        thunderbird_text->setFont(font1);

        verticalLayout->addWidget(thunderbird_text);

        virtmanager_button = new QCheckBox(extraparty_scrollhouse);
        virtmanager_button->setObjectName(QString::fromUtf8("virtmanager_button"));

        verticalLayout->addWidget(virtmanager_button);

        virtmanager_text = new QLabel(extraparty_scrollhouse);
        virtmanager_text->setObjectName(QString::fromUtf8("virtmanager_text"));
        virtmanager_text->setFont(font1);

        verticalLayout->addWidget(virtmanager_text);

        krita_button = new QCheckBox(extraparty_scrollhouse);
        krita_button->setObjectName(QString::fromUtf8("krita_button"));

        verticalLayout->addWidget(krita_button);

        krita_text = new QLabel(extraparty_scrollhouse);
        krita_text->setObjectName(QString::fromUtf8("krita_text"));
        krita_text->setFont(font1);

        verticalLayout->addWidget(krita_text);

        pushup_tiny = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(pushup_tiny);

        extraparty_scroll->setWidget(extraparty_scrollhouse);

        gridLayout->addWidget(extraparty_scroll, 16, 1, 1, 1);

        updates_button = new QCheckBox(pkgselect);
        updates_button->setObjectName(QString::fromUtf8("updates_button"));
        updates_button->setFont(font);

        gridLayout->addWidget(updates_button, 10, 1, 1, 1);

        updates_text = new QLabel(pkgselect);
        updates_text->setObjectName(QString::fromUtf8("updates_text"));
        updates_text->setFont(font1);

        gridLayout->addWidget(updates_text, 11, 1, 1, 1);

        full_button = new QRadioButton(pkgselect);
        full_button->setObjectName(QString::fromUtf8("full_button"));
        full_button->setFont(font);

        gridLayout->addWidget(full_button, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        party_text = new QLabel(pkgselect);
        party_text->setObjectName(QString::fromUtf8("party_text"));
        party_text->setFont(font1);

        gridLayout->addWidget(party_text, 13, 1, 1, 1);

        label = new QLabel(pkgselect);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        gridLayout->addWidget(label, 9, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 14, 1, 1, 1);

        apps_label = new QLabel(pkgselect);
        apps_label->setObjectName(QString::fromUtf8("apps_label"));
        apps_label->setFont(font2);

        gridLayout->addWidget(apps_label, 1, 1, 1, 1);

        full_text = new QLabel(pkgselect);
        full_text->setObjectName(QString::fromUtf8("full_text"));
        full_text->setFont(font1);

        gridLayout->addWidget(full_text, 3, 1, 1, 1);

        party_button = new QCheckBox(pkgselect);
        party_button->setObjectName(QString::fromUtf8("party_button"));
        party_button->setFont(font);

        gridLayout->addWidget(party_button, 12, 1, 1, 1);

        normal_text = new QLabel(pkgselect);
        normal_text->setObjectName(QString::fromUtf8("normal_text"));
        normal_text->setFont(font1);

        gridLayout->addWidget(normal_text, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 8, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        retranslateUi(pkgselect);

        QMetaObject::connectSlotsByName(pkgselect);
    } // setupUi

    void retranslateUi(QWidget *pkgselect)
    {
        pkgselect->setWindowTitle(QCoreApplication::translate("pkgselect", "Form", nullptr));
        minimal_button->setText(QCoreApplication::translate("pkgselect", "Minimal Installation", nullptr));
        minimal_text->setText(QCoreApplication::translate("pkgselect", "Only the desktop environment", nullptr));
        extraparty_text->setText(QCoreApplication::translate("pkgselect", "Install additional third-party packages", nullptr));
        normal_button->setText(QCoreApplication::translate("pkgselect", "Normal Installation", nullptr));
        element_button->setText(QCoreApplication::translate("pkgselect", "Element", nullptr));
        element_text->setText(QCoreApplication::translate("pkgselect", "Matrix-based end-to-end encrypted messenger and secure collaboration app", nullptr));
        thunderbird_button->setText(QCoreApplication::translate("pkgselect", "Thunderbird", nullptr));
        thunderbird_text->setText(QCoreApplication::translate("pkgselect", "Email, newsfeed, chat, and calendaring client", nullptr));
        virtmanager_button->setText(QCoreApplication::translate("pkgselect", "Virtual Machine Manager", nullptr));
        virtmanager_text->setText(QCoreApplication::translate("pkgselect", "Desktop user interface for managing virtual machines through libvirt", nullptr));
        krita_button->setText(QCoreApplication::translate("pkgselect", "Krita", nullptr));
        krita_text->setText(QCoreApplication::translate("pkgselect", "Graphics editor designed primarily for digital art and 2D animation", nullptr));
        updates_button->setText(QCoreApplication::translate("pkgselect", "Download and install updates following installation", nullptr));
        updates_text->setText(QCoreApplication::translate("pkgselect", "This saves time after installation, and keeps your system secure", nullptr));
        full_button->setText(QCoreApplication::translate("pkgselect", "Full Installation", nullptr));
        party_text->setText(QCoreApplication::translate("pkgselect", "This software is subject to license terms included with its documentation, and some may be proprietary", nullptr));
        label->setText(QCoreApplication::translate("pkgselect", "Additional Options", nullptr));
        apps_label->setText(QCoreApplication::translate("pkgselect", "Installation Mode", nullptr));
        full_text->setText(QCoreApplication::translate("pkgselect", "All applications in the Normal Installation, and all extra third-party packages listed below", nullptr));
        party_button->setText(QCoreApplication::translate("pkgselect", "Install third-party software for graphics, WiFi hardware, and additional media formats", nullptr));
        normal_text->setText(QCoreApplication::translate("pkgselect", "Web browser, utilities, office software, games, and media players", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pkgselect: public Ui_pkgselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PKGSELECT_H
