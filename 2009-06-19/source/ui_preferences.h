/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PreferencesDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *pliBox_2;
    QHBoxLayout *hboxLayout;
    QLabel *label_6;
    QLineEdit *ldrawPath;
    QPushButton *browseLDraw;
    QGroupBox *pliBox;
    QHBoxLayout *hboxLayout1;
    QLabel *label_5;
    QLineEdit *pliName;
    QPushButton *browsePli;
    QGroupBox *ldgliteBox;
    QHBoxLayout *hboxLayout2;
    QLabel *label;
    QLineEdit *ldglitePath;
    QPushButton *browseLDGLite;
    QGroupBox *ldviewBox;
    QHBoxLayout *hboxLayout3;
    QLabel *label_2;
    QLineEdit *ldviewPath;
    QPushButton *browseLDView;
    QHBoxLayout *hboxLayout4;
    QLabel *label_4;
    QComboBox *preferredRenderer;
    QGroupBox *groupBox;
    QHBoxLayout *hboxLayout5;
    QRadioButton *Centimeters;
    QRadioButton *Inches;
    QSpacerItem *spacerItem;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreferencesDialog)
    {
        if (PreferencesDialog->objectName().isEmpty())
            PreferencesDialog->setObjectName(QString::fromUtf8("PreferencesDialog"));
        PreferencesDialog->resize(395, 493);
        vboxLayout = new QVBoxLayout(PreferencesDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        pliBox_2 = new QGroupBox(PreferencesDialog);
        pliBox_2->setObjectName(QString::fromUtf8("pliBox_2"));
        pliBox_2->setCheckable(false);
        pliBox_2->setChecked(false);
        hboxLayout = new QHBoxLayout(pliBox_2);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label_6 = new QLabel(pliBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        hboxLayout->addWidget(label_6);

        ldrawPath = new QLineEdit(pliBox_2);
        ldrawPath->setObjectName(QString::fromUtf8("ldrawPath"));
        ldrawPath->setMinimumSize(QSize(200, 0));

        hboxLayout->addWidget(ldrawPath);

        browseLDraw = new QPushButton(pliBox_2);
        browseLDraw->setObjectName(QString::fromUtf8("browseLDraw"));

        hboxLayout->addWidget(browseLDraw);


        vboxLayout->addWidget(pliBox_2);

        pliBox = new QGroupBox(PreferencesDialog);
        pliBox->setObjectName(QString::fromUtf8("pliBox"));
        pliBox->setCheckable(true);
        pliBox->setChecked(false);
        hboxLayout1 = new QHBoxLayout(pliBox);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label_5 = new QLabel(pliBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        hboxLayout1->addWidget(label_5);

        pliName = new QLineEdit(pliBox);
        pliName->setObjectName(QString::fromUtf8("pliName"));
        pliName->setMinimumSize(QSize(200, 0));

        hboxLayout1->addWidget(pliName);

        browsePli = new QPushButton(pliBox);
        browsePli->setObjectName(QString::fromUtf8("browsePli"));

        hboxLayout1->addWidget(browsePli);


        vboxLayout->addWidget(pliBox);

        ldgliteBox = new QGroupBox(PreferencesDialog);
        ldgliteBox->setObjectName(QString::fromUtf8("ldgliteBox"));
        ldgliteBox->setCheckable(true);
        ldgliteBox->setChecked(false);
        hboxLayout2 = new QHBoxLayout(ldgliteBox);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label = new QLabel(ldgliteBox);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout2->addWidget(label);

        ldglitePath = new QLineEdit(ldgliteBox);
        ldglitePath->setObjectName(QString::fromUtf8("ldglitePath"));

        hboxLayout2->addWidget(ldglitePath);

        browseLDGLite = new QPushButton(ldgliteBox);
        browseLDGLite->setObjectName(QString::fromUtf8("browseLDGLite"));

        hboxLayout2->addWidget(browseLDGLite);


        vboxLayout->addWidget(ldgliteBox);

        ldviewBox = new QGroupBox(PreferencesDialog);
        ldviewBox->setObjectName(QString::fromUtf8("ldviewBox"));
        ldviewBox->setCheckable(true);
        ldviewBox->setChecked(false);
        hboxLayout3 = new QHBoxLayout(ldviewBox);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        label_2 = new QLabel(ldviewBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout3->addWidget(label_2);

        ldviewPath = new QLineEdit(ldviewBox);
        ldviewPath->setObjectName(QString::fromUtf8("ldviewPath"));

        hboxLayout3->addWidget(ldviewPath);

        browseLDView = new QPushButton(ldviewBox);
        browseLDView->setObjectName(QString::fromUtf8("browseLDView"));

        hboxLayout3->addWidget(browseLDView);


        vboxLayout->addWidget(ldviewBox);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        hboxLayout4->setContentsMargins(0, 0, -1, -1);
        label_4 = new QLabel(PreferencesDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        hboxLayout4->addWidget(label_4);

        preferredRenderer = new QComboBox(PreferencesDialog);
        preferredRenderer->setObjectName(QString::fromUtf8("preferredRenderer"));

        hboxLayout4->addWidget(preferredRenderer);


        vboxLayout->addLayout(hboxLayout4);

        groupBox = new QGroupBox(PreferencesDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        hboxLayout5 = new QHBoxLayout(groupBox);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        Centimeters = new QRadioButton(groupBox);
        Centimeters->setObjectName(QString::fromUtf8("Centimeters"));

        hboxLayout5->addWidget(Centimeters);

        Inches = new QRadioButton(groupBox);
        Inches->setObjectName(QString::fromUtf8("Inches"));

        hboxLayout5->addWidget(Inches);


        vboxLayout->addWidget(groupBox);

        spacerItem = new QSpacerItem(371, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        buttonBox = new QDialogButtonBox(PreferencesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(PreferencesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreferencesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferencesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferencesDialog)
    {
        PreferencesDialog->setWindowTitle(QApplication::translate("PreferencesDialog", "LPub Preferences", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pliBox_2->setToolTip(QApplication::translate("PreferencesDialog", "This file controls Part List parts orientation and size", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pliBox_2->setTitle(QApplication::translate("PreferencesDialog", "LDraw Root Directory", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PreferencesDialog", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        browseLDraw->setToolTip(QApplication::translate("PreferencesDialog", "Use directory dialog to find LDraw directory", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        browseLDraw->setWhatsThis(QApplication::translate("PreferencesDialog", "This lets you find the LDraw directory", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        browseLDraw->setText(QApplication::translate("PreferencesDialog", "Browse...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pliBox->setToolTip(QApplication::translate("PreferencesDialog", "This file controls Part List parts orientation and size", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pliBox->setTitle(QApplication::translate("PreferencesDialog", "Use PLI orientation/size control file", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PreferencesDialog", "Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        browsePli->setToolTip(QApplication::translate("PreferencesDialog", "Use directory dialog to find LDraw directory", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        browsePli->setWhatsThis(QApplication::translate("PreferencesDialog", "This lets you find the LDraw directory", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        browsePli->setText(QApplication::translate("PreferencesDialog", "Browse...", 0, QApplication::UnicodeUTF8));
        ldgliteBox->setTitle(QApplication::translate("PreferencesDialog", "LDGLite is installed", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreferencesDialog", "Path:", 0, QApplication::UnicodeUTF8));
        browseLDGLite->setText(QApplication::translate("PreferencesDialog", "Browse...", 0, QApplication::UnicodeUTF8));
        ldviewBox->setTitle(QApplication::translate("PreferencesDialog", "LDView is installed", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PreferencesDialog", "Path:", 0, QApplication::UnicodeUTF8));
        browseLDView->setText(QApplication::translate("PreferencesDialog", "Browse...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PreferencesDialog", "Preferred Renderer:", 0, QApplication::UnicodeUTF8));
        preferredRenderer->clear();
        preferredRenderer->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "LDGLite", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "LDView", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("PreferencesDialog", "Default Units", 0, QApplication::UnicodeUTF8));
        Centimeters->setText(QApplication::translate("PreferencesDialog", "Centimeters", 0, QApplication::UnicodeUTF8));
        Inches->setText(QApplication::translate("PreferencesDialog", "Inches", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreferencesDialog: public Ui_PreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
