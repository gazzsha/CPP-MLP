/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QRadioButton *GraphRadio;
    QRadioButton *MatrixRadio;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *letter_label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushLoad;
    QPushButton *pushTraib;
    QGraphicsView *graphicsView;
    QPushButton *pushClear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(1075, 856);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("   background-color:    rgb(84, 74, 128);"));
        GraphRadio = new QRadioButton(centralwidget);
        GraphRadio->setObjectName(QString::fromUtf8("GraphRadio"));
        GraphRadio->setGeometry(QRect(770, 190, 131, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Charter")});
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        GraphRadio->setFont(font);
        GraphRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color:       rgb(84, 74, 128);\n"
"    color:                  white;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width:                  10px;\n"
"    height:                 10px;\n"
"    border-radius:          7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color:       red;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       black;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
""));
        MatrixRadio = new QRadioButton(centralwidget);
        MatrixRadio->setObjectName(QString::fromUtf8("MatrixRadio"));
        MatrixRadio->setGeometry(QRect(910, 190, 131, 31));
        MatrixRadio->setFont(font);
        MatrixRadio->setLayoutDirection(Qt::RightToLeft);
        MatrixRadio->setAutoFillBackground(false);
        MatrixRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    background-color:       rgb(84, 74, 128);\n"
"    color:                  white;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width:                  10px;\n"
"    height:                 10px;\n"
"    border-radius:          7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color:       red;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color:       black;\n"
"    border:                 2px solid white;\n"
"}\n"
"\n"
""));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(770, 400, 271, 33));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Charter")});
        font1.setPointSize(23);
        font1.setBold(true);
        font1.setItalic(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"    border-radius: 3px;\n"
"color: white;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(horizontalLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(23);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        spinBox->setFont(font2);
        spinBox->setStyleSheet(QString::fromUtf8("\n"
"    border-radius: 3px;\n"
"color: white;"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(5);

        horizontalLayout_2->addWidget(spinBox);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(770, 320, 271, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color : white;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Charter")});
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        radioButton->setFont(font3);
        radioButton->setLayoutDirection(Qt::LeftToRight);
        radioButton->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(radioButton);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setFont(font3);
        radioButton_3->setLayoutDirection(Qt::LeftToRight);
        radioButton_3->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setFont(font3);
        radioButton_2->setLayoutDirection(Qt::LeftToRight);
        radioButton_2->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton_4 = new QRadioButton(verticalLayoutWidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setFont(font3);
        radioButton_4->setLayoutDirection(Qt::LeftToRight);
        radioButton_4->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(radioButton_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(770, 510, 271, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Charter")});
        font4.setPointSize(31);
        font4.setBold(true);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color : white;"));

        horizontalLayout_3->addWidget(label_3);

        letter_label = new QLabel(horizontalLayoutWidget_3);
        letter_label->setObjectName(QString::fromUtf8("letter_label"));

        horizontalLayout_3->addWidget(letter_label);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(770, 630, 271, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Charter")});
        font5.setPointSize(23);
        font5.setBold(true);
        font5.setItalic(false);
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("color : white;"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("color : white;"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font5);
        label_5->setStyleSheet(QString::fromUtf8("color : white;"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font5);
        label_7->setStyleSheet(QString::fromUtf8("color : white;"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("color : white;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("color : white;"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font5);
        label_10->setStyleSheet(QString::fromUtf8("color : white;"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font5);
        label_11->setStyleSheet(QString::fromUtf8("color : white;"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 2, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font5);
        label_12->setStyleSheet(QString::fromUtf8("color : white;"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 3, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font5);
        label_13->setStyleSheet(QString::fromUtf8("color : white;"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 4, 1, 1, 1);

        pushLoad = new QPushButton(centralwidget);
        pushLoad->setObjectName(QString::fromUtf8("pushLoad"));
        pushLoad->setGeometry(QRect(770, 50, 271, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Ayuthaya")});
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setItalic(true);
        pushLoad->setFont(font6);
        pushLoad->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        pushTraib = new QPushButton(centralwidget);
        pushTraib->setObjectName(QString::fromUtf8("pushTraib"));
        pushTraib->setGeometry(QRect(770, 80, 271, 21));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Ayuthaya")});
        font7.setPointSize(17);
        font7.setBold(false);
        font7.setItalic(true);
        pushTraib->setFont(font7);
        pushTraib->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 50, 741, 711));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: white;"));
        pushClear = new QPushButton(centralwidget);
        pushClear->setObjectName(QString::fromUtf8("pushClear"));
        pushClear->setGeometry(QRect(20, 20, 271, 21));
        pushClear->setFont(font7);
        pushClear->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1075, 24));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        View->setStatusBar(statusbar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QCoreApplication::translate("View", "View", nullptr));
        GraphRadio->setText(QCoreApplication::translate("View", "Graph", nullptr));
        MatrixRadio->setText(QCoreApplication::translate("View", "Matrix", nullptr));
        label_2->setText(QCoreApplication::translate("View", "Epochs", nullptr));
        label->setText(QCoreApplication::translate("View", "Number of Hidden Layers", nullptr));
        radioButton->setText(QCoreApplication::translate("View", "2", nullptr));
        radioButton_3->setText(QCoreApplication::translate("View", "3", nullptr));
        radioButton_2->setText(QCoreApplication::translate("View", "4", nullptr));
        radioButton_4->setText(QCoreApplication::translate("View", "5", nullptr));
        label_3->setText(QCoreApplication::translate("View", "The letter is:", nullptr));
        letter_label->setText(QString());
        label_6->setText(QCoreApplication::translate("View", "Recall", nullptr));
        label_8->setText(QCoreApplication::translate("View", "Time", nullptr));
        label_5->setText(QCoreApplication::translate("View", "Precision", nullptr));
        label_7->setText(QCoreApplication::translate("View", "F-measure", nullptr));
        label_4->setText(QCoreApplication::translate("View", "Accuracy", nullptr));
        label_9->setText(QCoreApplication::translate("View", "0.0", nullptr));
        label_10->setText(QCoreApplication::translate("View", "0.0", nullptr));
        label_11->setText(QCoreApplication::translate("View", "0.0", nullptr));
        label_12->setText(QCoreApplication::translate("View", "0.0", nullptr));
        label_13->setText(QCoreApplication::translate("View", "0.0", nullptr));
        pushLoad->setText(QCoreApplication::translate("View", "Load BMP...", nullptr));
        pushTraib->setText(QCoreApplication::translate("View", "Train", nullptr));
        pushClear->setText(QCoreApplication::translate("View", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
