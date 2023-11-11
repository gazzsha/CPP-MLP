/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
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
    QSpinBox *epochs_count_box;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton;
    QRadioButton *count_3_hidden_layer;
    QRadioButton *count_4_hidden_layer;
    QRadioButton *count_5_hidden_layer;
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
    QLabel *accuracy_label;
    QLabel *precision_label;
    QLabel *recall_label;
    QLabel *f_mera_label;
    QLabel *time_label;
    QPushButton *pushLoad;
    QPushButton *push_train;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushClear_3;
    QPushButton *pushPredict;
    QPushButton *pushClear;
    QPushButton *push_training_data;
    QPushButton *push_testing_data;
    QPushButton *push_check_testing_data;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName("View");
        View->resize(1075, 856);
        centralwidget = new QWidget(View);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("   background-color:    rgb(84, 74, 128);"));
        GraphRadio = new QRadioButton(centralwidget);
        GraphRadio->setObjectName("GraphRadio");
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
        MatrixRadio->setObjectName("MatrixRadio");
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
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(770, 400, 271, 33));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");
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

        epochs_count_box = new QSpinBox(horizontalLayoutWidget_2);
        epochs_count_box->setObjectName("epochs_count_box");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(epochs_count_box->sizePolicy().hasHeightForWidth());
        epochs_count_box->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(23);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        epochs_count_box->setFont(font2);
        epochs_count_box->setStyleSheet(QString::fromUtf8("\n"
"    border-radius: 3px;\n"
"color: white;"));
        epochs_count_box->setMinimum(1);
        epochs_count_box->setMaximum(5);

        horizontalLayout_2->addWidget(epochs_count_box);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(770, 320, 271, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color : white;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName("radioButton");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Charter")});
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(true);
        radioButton->setFont(font3);
        radioButton->setLayoutDirection(Qt::LeftToRight);
        radioButton->setStyleSheet(QString::fromUtf8("color: white;"));
        radioButton->setChecked(true);

        horizontalLayout->addWidget(radioButton);

        count_3_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_3_hidden_layer->setObjectName("count_3_hidden_layer");
        count_3_hidden_layer->setFont(font3);
        count_3_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_3_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(count_3_hidden_layer);

        count_4_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_4_hidden_layer->setObjectName("count_4_hidden_layer");
        count_4_hidden_layer->setFont(font3);
        count_4_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_4_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(count_4_hidden_layer);

        count_5_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_5_hidden_layer->setObjectName("count_5_hidden_layer");
        count_5_hidden_layer->setFont(font3);
        count_5_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_5_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(count_5_hidden_layer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(770, 510, 271, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Charter")});
        font4.setPointSize(31);
        font4.setBold(true);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color : white;"));

        horizontalLayout_3->addWidget(label_3);

        letter_label = new QLabel(horizontalLayoutWidget_3);
        letter_label->setObjectName("letter_label");
        QFont font5;
        font5.setPointSize(26);
        letter_label->setFont(font5);

        horizontalLayout_3->addWidget(letter_label);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(770, 630, 271, 179));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Charter")});
        font6.setPointSize(23);
        font6.setBold(true);
        font6.setItalic(false);
        label_6->setFont(font6);
        label_6->setStyleSheet(QString::fromUtf8("color : white;"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setFont(font6);
        label_8->setStyleSheet(QString::fromUtf8("color : white;"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font6);
        label_5->setStyleSheet(QString::fromUtf8("color : white;"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font6);
        label_7->setStyleSheet(QString::fromUtf8("color : white;"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font6);
        label_4->setStyleSheet(QString::fromUtf8("color : white;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        accuracy_label = new QLabel(gridLayoutWidget);
        accuracy_label->setObjectName("accuracy_label");
        accuracy_label->setFont(font6);
        accuracy_label->setStyleSheet(QString::fromUtf8("color : white;"));
        accuracy_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(accuracy_label, 0, 1, 1, 1);

        precision_label = new QLabel(gridLayoutWidget);
        precision_label->setObjectName("precision_label");
        precision_label->setFont(font6);
        precision_label->setStyleSheet(QString::fromUtf8("color : white;"));
        precision_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(precision_label, 1, 1, 1, 1);

        recall_label = new QLabel(gridLayoutWidget);
        recall_label->setObjectName("recall_label");
        recall_label->setFont(font6);
        recall_label->setStyleSheet(QString::fromUtf8("color : white;"));
        recall_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(recall_label, 2, 1, 1, 1);

        f_mera_label = new QLabel(gridLayoutWidget);
        f_mera_label->setObjectName("f_mera_label");
        f_mera_label->setFont(font6);
        f_mera_label->setStyleSheet(QString::fromUtf8("color : white;"));
        f_mera_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(f_mera_label, 3, 1, 1, 1);

        time_label = new QLabel(gridLayoutWidget);
        time_label->setObjectName("time_label");
        time_label->setFont(font6);
        time_label->setStyleSheet(QString::fromUtf8("color : white;"));
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(time_label, 4, 1, 1, 1);

        pushLoad = new QPushButton(centralwidget);
        pushLoad->setObjectName("pushLoad");
        pushLoad->setGeometry(QRect(770, 70, 271, 21));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Ayuthaya")});
        font7.setPointSize(15);
        font7.setBold(false);
        font7.setItalic(true);
        pushLoad->setFont(font7);
        pushLoad->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        push_train = new QPushButton(centralwidget);
        push_train->setObjectName("push_train");
        push_train->setGeometry(QRect(770, 130, 271, 21));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Ayuthaya")});
        font8.setPointSize(17);
        font8.setBold(false);
        font8.setItalic(true);
        push_train->setFont(font8);
        push_train->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 50, 741, 711));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: white;"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 741, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushClear_3 = new QPushButton(horizontalLayoutWidget);
        pushClear_3->setObjectName("pushClear_3");
        pushClear_3->setFont(font8);
        pushClear_3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));

        horizontalLayout_4->addWidget(pushClear_3);

        pushPredict = new QPushButton(horizontalLayoutWidget);
        pushPredict->setObjectName("pushPredict");
        pushPredict->setFont(font8);
        pushPredict->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));

        horizontalLayout_4->addWidget(pushPredict);

        pushClear = new QPushButton(horizontalLayoutWidget);
        pushClear->setObjectName("pushClear");
        pushClear->setFont(font8);
        pushClear->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));

        horizontalLayout_4->addWidget(pushClear);

        push_training_data = new QPushButton(centralwidget);
        push_training_data->setObjectName("push_training_data");
        push_training_data->setGeometry(QRect(770, 40, 271, 21));
        push_training_data->setFont(font7);
        push_training_data->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        push_testing_data = new QPushButton(centralwidget);
        push_testing_data->setObjectName("push_testing_data");
        push_testing_data->setGeometry(QRect(770, 100, 271, 21));
        push_testing_data->setFont(font8);
        push_testing_data->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        push_check_testing_data = new QPushButton(centralwidget);
        push_check_testing_data->setObjectName("push_check_testing_data");
        push_check_testing_data->setGeometry(QRect(770, 160, 271, 21));
        push_check_testing_data->setFont(font8);
        push_check_testing_data->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(236, 233, 238);"));
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1075, 24));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName("statusbar");
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
        count_3_hidden_layer->setText(QCoreApplication::translate("View", "3", nullptr));
        count_4_hidden_layer->setText(QCoreApplication::translate("View", "4", nullptr));
        count_5_hidden_layer->setText(QCoreApplication::translate("View", "5", nullptr));
        label_3->setText(QCoreApplication::translate("View", "The letter is:", nullptr));
        letter_label->setText(QString());
        label_6->setText(QCoreApplication::translate("View", "Recall", nullptr));
        label_8->setText(QCoreApplication::translate("View", "Time", nullptr));
        label_5->setText(QCoreApplication::translate("View", "Precision", nullptr));
        label_7->setText(QCoreApplication::translate("View", "F-measure", nullptr));
        label_4->setText(QCoreApplication::translate("View", "Accuracy", nullptr));
        accuracy_label->setText(QCoreApplication::translate("View", "0.0", nullptr));
        precision_label->setText(QCoreApplication::translate("View", "0.0", nullptr));
        recall_label->setText(QCoreApplication::translate("View", "0.0", nullptr));
        f_mera_label->setText(QCoreApplication::translate("View", "0.0", nullptr));
        time_label->setText(QCoreApplication::translate("View", "0.0", nullptr));
        pushLoad->setText(QCoreApplication::translate("View", "Load BMP...", nullptr));
        push_train->setText(QCoreApplication::translate("View", "Train", nullptr));
        pushClear_3->setText(QCoreApplication::translate("View", "Clear", nullptr));
        pushPredict->setText(QCoreApplication::translate("View", "Predict", nullptr));
        pushClear->setText(QCoreApplication::translate("View", "Clear", nullptr));
        push_training_data->setText(QCoreApplication::translate("View", "Load Training Data...", nullptr));
        push_testing_data->setText(QCoreApplication::translate("View", "Load Testing Data...", nullptr));
        push_check_testing_data->setText(QCoreApplication::translate("View", "Check Testing Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
