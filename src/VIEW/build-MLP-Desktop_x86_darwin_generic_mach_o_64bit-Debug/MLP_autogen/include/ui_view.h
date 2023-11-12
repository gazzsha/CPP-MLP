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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

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
    QRadioButton *count_2_hidden_layer;
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
    QPushButton *push_load_bmp;
    QPushButton *push_train;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *push_predict_bmp;
    QPushButton *pushPredict;
    QPushButton *pushClear;
    QPushButton *push_training_data;
    QPushButton *push_testing_data;
    QPushButton *push_check_testing_data;
    QPushButton *push_load_weights;
    QPushButton *push_save_weights;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QDoubleSpinBox *shape_box;
    QPushButton *push_train_online;
    QTableWidget *tableWidget;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(1688, 885);
        QFont font;
        font.setPointSize(30);
        View->setFont(font);
        View->setStyleSheet(QString::fromUtf8("color:white;"));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("   background-color:    rgb(84, 74, 128);"));
        GraphRadio = new QRadioButton(centralwidget);
        GraphRadio->setObjectName(QString::fromUtf8("GraphRadio"));
        GraphRadio->setGeometry(QRect(770, 280, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Charter")});
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(true);
        GraphRadio->setFont(font1);
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
        GraphRadio->setChecked(true);
        MatrixRadio = new QRadioButton(centralwidget);
        MatrixRadio->setObjectName(QString::fromUtf8("MatrixRadio"));
        MatrixRadio->setGeometry(QRect(910, 280, 131, 31));
        MatrixRadio->setFont(font1);
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
        horizontalLayoutWidget_2->setGeometry(QRect(770, 400, 271, 44));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Charter")});
        font2.setPointSize(23);
        font2.setBold(true);
        font2.setItalic(true);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"    border-radius: 3px;\n"
"color: white;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        epochs_count_box = new QSpinBox(horizontalLayoutWidget_2);
        epochs_count_box->setObjectName(QString::fromUtf8("epochs_count_box"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(epochs_count_box->sizePolicy().hasHeightForWidth());
        epochs_count_box->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(32);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        epochs_count_box->setFont(font3);
        epochs_count_box->setStyleSheet(QString::fromUtf8("\n"
"color: white;"));
        epochs_count_box->setAlignment(Qt::AlignCenter);
        epochs_count_box->setMinimum(1);
        epochs_count_box->setMaximum(5);
        epochs_count_box->setValue(2);

        horizontalLayout_2->addWidget(epochs_count_box);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(770, 320, 271, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color : white;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        count_2_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_2_hidden_layer->setObjectName(QString::fromUtf8("count_2_hidden_layer"));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Charter")});
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setItalic(true);
        count_2_hidden_layer->setFont(font4);
        count_2_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_2_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));
        count_2_hidden_layer->setChecked(false);

        horizontalLayout->addWidget(count_2_hidden_layer);

        count_3_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_3_hidden_layer->setObjectName(QString::fromUtf8("count_3_hidden_layer"));
        count_3_hidden_layer->setFont(font4);
        count_3_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_3_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));
        count_3_hidden_layer->setChecked(true);

        horizontalLayout->addWidget(count_3_hidden_layer);

        count_4_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_4_hidden_layer->setObjectName(QString::fromUtf8("count_4_hidden_layer"));
        count_4_hidden_layer->setFont(font4);
        count_4_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_4_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout->addWidget(count_4_hidden_layer);

        count_5_hidden_layer = new QRadioButton(verticalLayoutWidget);
        count_5_hidden_layer->setObjectName(QString::fromUtf8("count_5_hidden_layer"));
        count_5_hidden_layer->setFont(font4);
        count_5_hidden_layer->setLayoutDirection(Qt::LeftToRight);
        count_5_hidden_layer->setStyleSheet(QString::fromUtf8("color: white;"));
        count_5_hidden_layer->setChecked(false);

        horizontalLayout->addWidget(count_5_hidden_layer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(770, 510, 271, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Charter")});
        font5.setPointSize(31);
        font5.setBold(true);
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("color : white;"));

        horizontalLayout_3->addWidget(label_3);

        letter_label = new QLabel(horizontalLayoutWidget_3);
        letter_label->setObjectName(QString::fromUtf8("letter_label"));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Charter")});
        font6.setPointSize(40);
        font6.setBold(true);
        font6.setItalic(true);
        letter_label->setFont(font6);
        letter_label->setStyleSheet(QString::fromUtf8("color : white;"));
        letter_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(letter_label);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(770, 630, 271, 179));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Charter")});
        font7.setPointSize(23);
        font7.setBold(true);
        font7.setItalic(false);
        label_6->setFont(font7);
        label_6->setStyleSheet(QString::fromUtf8("color : white;"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font7);
        label_8->setStyleSheet(QString::fromUtf8("color : white;"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font7);
        label_5->setStyleSheet(QString::fromUtf8("color : white;"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font7);
        label_7->setStyleSheet(QString::fromUtf8("color : white;"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font7);
        label_4->setStyleSheet(QString::fromUtf8("color : white;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        accuracy_label = new QLabel(gridLayoutWidget);
        accuracy_label->setObjectName(QString::fromUtf8("accuracy_label"));
        accuracy_label->setFont(font7);
        accuracy_label->setStyleSheet(QString::fromUtf8("color : white;"));
        accuracy_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(accuracy_label, 0, 1, 1, 1);

        precision_label = new QLabel(gridLayoutWidget);
        precision_label->setObjectName(QString::fromUtf8("precision_label"));
        precision_label->setFont(font7);
        precision_label->setStyleSheet(QString::fromUtf8("color : white;"));
        precision_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(precision_label, 1, 1, 1, 1);

        recall_label = new QLabel(gridLayoutWidget);
        recall_label->setObjectName(QString::fromUtf8("recall_label"));
        recall_label->setFont(font7);
        recall_label->setStyleSheet(QString::fromUtf8("color : white;"));
        recall_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(recall_label, 2, 1, 1, 1);

        f_mera_label = new QLabel(gridLayoutWidget);
        f_mera_label->setObjectName(QString::fromUtf8("f_mera_label"));
        f_mera_label->setFont(font7);
        f_mera_label->setStyleSheet(QString::fromUtf8("color : white;"));
        f_mera_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(f_mera_label, 3, 1, 1, 1);

        time_label = new QLabel(gridLayoutWidget);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setFont(font7);
        time_label->setStyleSheet(QString::fromUtf8("color : white;"));
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(time_label, 4, 1, 1, 1);

        push_load_bmp = new QPushButton(centralwidget);
        push_load_bmp->setObjectName(QString::fromUtf8("push_load_bmp"));
        push_load_bmp->setGeometry(QRect(770, 70, 271, 21));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Ayuthaya")});
        font8.setPointSize(15);
        font8.setBold(false);
        font8.setItalic(true);
        push_load_bmp->setFont(font8);
        push_load_bmp->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        push_train = new QPushButton(centralwidget);
        push_train->setObjectName(QString::fromUtf8("push_train"));
        push_train->setGeometry(QRect(770, 130, 271, 21));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Ayuthaya")});
        font9.setPointSize(17);
        font9.setBold(false);
        font9.setItalic(true);
        push_train->setFont(font9);
        push_train->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 50, 741, 711));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: white;"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 741, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        push_predict_bmp = new QPushButton(horizontalLayoutWidget);
        push_predict_bmp->setObjectName(QString::fromUtf8("push_predict_bmp"));
        push_predict_bmp->setFont(font9);
        push_predict_bmp->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98);"));

        horizontalLayout_4->addWidget(push_predict_bmp);

        pushPredict = new QPushButton(horizontalLayoutWidget);
        pushPredict->setObjectName(QString::fromUtf8("pushPredict"));
        pushPredict->setFont(font9);
        pushPredict->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color:rgb(85, 24, 98)"));

        horizontalLayout_4->addWidget(pushPredict);

        pushClear = new QPushButton(horizontalLayoutWidget);
        pushClear->setObjectName(QString::fromUtf8("pushClear"));
        pushClear->setFont(font9);
        pushClear->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98);"));

        horizontalLayout_4->addWidget(pushClear);

        push_training_data = new QPushButton(centralwidget);
        push_training_data->setObjectName(QString::fromUtf8("push_training_data"));
        push_training_data->setGeometry(QRect(770, 40, 271, 21));
        push_training_data->setFont(font8);
        push_training_data->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        push_testing_data = new QPushButton(centralwidget);
        push_testing_data->setObjectName(QString::fromUtf8("push_testing_data"));
        push_testing_data->setGeometry(QRect(770, 100, 271, 21));
        push_testing_data->setFont(font9);
        push_testing_data->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        push_check_testing_data = new QPushButton(centralwidget);
        push_check_testing_data->setObjectName(QString::fromUtf8("push_check_testing_data"));
        push_check_testing_data->setGeometry(QRect(770, 190, 271, 21));
        push_check_testing_data->setFont(font9);
        push_check_testing_data->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        push_load_weights = new QPushButton(centralwidget);
        push_load_weights->setObjectName(QString::fromUtf8("push_load_weights"));
        push_load_weights->setGeometry(QRect(770, 220, 271, 21));
        push_load_weights->setFont(font9);
        push_load_weights->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        push_save_weights = new QPushButton(centralwidget);
        push_save_weights->setObjectName(QString::fromUtf8("push_save_weights"));
        push_save_weights->setGeometry(QRect(770, 250, 271, 21));
        push_save_weights->setFont(font9);
        push_save_weights->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(770, 450, 271, 60));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("\n"
"    border-radius: 3px;\n"
"color: white;"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_9);

        shape_box = new QDoubleSpinBox(horizontalLayoutWidget_4);
        shape_box->setObjectName(QString::fromUtf8("shape_box"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(shape_box->sizePolicy().hasHeightForWidth());
        shape_box->setSizePolicy(sizePolicy1);
        QFont font10;
        font10.setPointSize(32);
        font10.setBold(true);
        shape_box->setFont(font10);
        shape_box->setStyleSheet(QString::fromUtf8("color: white;"));
        shape_box->setAlignment(Qt::AlignCenter);
        shape_box->setMaximum(1.000000000000000);
        shape_box->setSingleStep(0.050000000000000);
        shape_box->setValue(1.000000000000000);

        horizontalLayout_5->addWidget(shape_box);

        push_train_online = new QPushButton(centralwidget);
        push_train_online->setObjectName(QString::fromUtf8("push_train_online"));
        push_train_online->setGeometry(QRect(770, 160, 271, 21));
        push_train_online->setFont(font9);
        push_train_online->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
" background-color: rgb(85, 24, 98)"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(1050, 40, 601, 191));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1050, 290, 601, 511));
        widget->setStyleSheet(QString::fromUtf8(""));
        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1688, 24));
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
        count_2_hidden_layer->setText(QCoreApplication::translate("View", "2", nullptr));
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
        push_load_bmp->setText(QCoreApplication::translate("View", "Load BMP...", nullptr));
        push_train->setText(QCoreApplication::translate("View", "Train", nullptr));
        push_predict_bmp->setText(QCoreApplication::translate("View", "Predict BMP", nullptr));
        pushPredict->setText(QCoreApplication::translate("View", "Predict", nullptr));
        pushClear->setText(QCoreApplication::translate("View", "Clear", nullptr));
        push_training_data->setText(QCoreApplication::translate("View", "Load Training Data...", nullptr));
        push_testing_data->setText(QCoreApplication::translate("View", "Load Testing Data...", nullptr));
        push_check_testing_data->setText(QCoreApplication::translate("View", "Check Testing Data", nullptr));
        push_load_weights->setText(QCoreApplication::translate("View", "Load weights", nullptr));
        push_save_weights->setText(QCoreApplication::translate("View", "Save weights", nullptr));
        label_9->setText(QCoreApplication::translate("View", "Part of Training", nullptr));
        push_train_online->setText(QCoreApplication::translate("View", "Train Online", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("View", "\342\204\226", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("View", "Accurancy", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("View", "Precision", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("View", "Recall", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("View", "F-Mera", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("View", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
