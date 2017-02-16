/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QPushButton *normalTrip;
    QPushButton *CustomTrip1;
    QPushButton *CustomTrip2;
    QPushButton *startTrip;
    QTableWidget *LocationsTableWidget;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *Selected_Locations_Label;
    QLabel *label_4;
    QComboBox *comboBox;
    QWidget *stackedWidgetPage2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QTableWidget *tableWidget_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSplitter *splitter;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTableWidget *tableWidget_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLabel *label_10;
    QSplitter *splitter_4;
    QComboBox *comboBox_2;
    QSpinBox *spinBox;
    QWidget *stackedWidgetPage3;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *stackedWidgetPage4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSplitter *splitter_2;
    QLabel *label_13;
    QLineEdit *pass;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label;
    QPushButton *LogOut_Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(948, 629);
        MainWindow->setStyleSheet(QLatin1String("gridline-color: rgb(255, 85, 0);\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 60, 791, 441));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        normalTrip = new QPushButton(stackedWidgetPage1);
        normalTrip->setObjectName(QStringLiteral("normalTrip"));
        normalTrip->setGeometry(QRect(20, 50, 81, 31));
        normalTrip->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        CustomTrip1 = new QPushButton(stackedWidgetPage1);
        CustomTrip1->setObjectName(QStringLiteral("CustomTrip1"));
        CustomTrip1->setGeometry(QRect(20, 90, 81, 31));
        CustomTrip1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        CustomTrip2 = new QPushButton(stackedWidgetPage1);
        CustomTrip2->setObjectName(QStringLiteral("CustomTrip2"));
        CustomTrip2->setGeometry(QRect(20, 130, 81, 31));
        CustomTrip2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        startTrip = new QPushButton(stackedWidgetPage1);
        startTrip->setObjectName(QStringLiteral("startTrip"));
        startTrip->setGeometry(QRect(640, 390, 81, 31));
        startTrip->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LocationsTableWidget = new QTableWidget(stackedWidgetPage1);
        LocationsTableWidget->setObjectName(QStringLiteral("LocationsTableWidget"));
        LocationsTableWidget->setGeometry(QRect(150, 50, 221, 381));
        LocationsTableWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LocationsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2 = new QTableWidget(stackedWidgetPage1);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(400, 50, 221, 381));
        tableWidget_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 20, 61, 16));
        Selected_Locations_Label = new QLabel(stackedWidgetPage1);
        Selected_Locations_Label->setObjectName(QStringLiteral("Selected_Locations_Label"));
        Selected_Locations_Label->setGeometry(QRect(400, 20, 121, 16));
        label_4 = new QLabel(stackedWidgetPage1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(641, 51, 131, 16));
        comboBox = new QComboBox(stackedWidgetPage1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(640, 80, 38, 20));
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QStringLiteral("stackedWidgetPage2"));
        layoutWidget = new QWidget(stackedWidgetPage2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 50, 261, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        tableWidget_4 = new QTableWidget(layoutWidget);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));

        verticalLayout_2->addWidget(tableWidget_4);

        pushButton_5 = new QPushButton(stackedWidgetPage2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(560, 230, 181, 23));
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_6 = new QPushButton(stackedWidgetPage2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(560, 380, 181, 23));
        pushButton_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        splitter = new QSplitter(stackedWidgetPage2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 20, 201, 16));
        splitter->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter);
        label_5->setObjectName(QStringLiteral("label_5"));
        splitter->addWidget(label_5);
        label_6 = new QLabel(splitter);
        label_6->setObjectName(QStringLiteral("label_6"));
        splitter->addWidget(label_6);
        layoutWidget1 = new QWidget(stackedWidgetPage2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 261, 361));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        tableWidget_3 = new QTableWidget(layoutWidget1);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));

        verticalLayout->addWidget(tableWidget_3);

        layoutWidget2 = new QWidget(stackedWidgetPage2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(560, 310, 181, 16));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        layoutWidget3 = new QWidget(stackedWidgetPage2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(560, 150, 181, 16));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        splitter_4 = new QSplitter(stackedWidgetPage2);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(560, 80, 181, 20));
        splitter_4->setOrientation(Qt::Horizontal);
        comboBox_2 = new QComboBox(splitter_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        splitter_4->addWidget(comboBox_2);
        spinBox = new QSpinBox(splitter_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        splitter_4->addWidget(spinBox);
        stackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QStringLiteral("stackedWidgetPage3"));
        label_14 = new QLabel(stackedWidgetPage3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(340, 190, 141, 31));
        label_15 = new QLabel(stackedWidgetPage3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(620, 410, 161, 20));
        stackedWidget->addWidget(stackedWidgetPage3);
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName(QStringLiteral("stackedWidgetPage4"));
        pushButton = new QPushButton(stackedWidgetPage4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 230, 51, 21));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(stackedWidgetPage4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 410, 101, 23));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(30, 30, 30);"));
        splitter_2 = new QSplitter(stackedWidgetPage4);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(300, 180, 221, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(splitter_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        splitter_2->addWidget(label_13);
        pass = new QLineEdit(splitter_2);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        splitter_2->addWidget(pass);
        splitter_3 = new QSplitter(stackedWidgetPage4);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(300, 130, 221, 20));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        name = new QLineEdit(splitter_3);
        name->setObjectName(QStringLiteral("name"));
        name->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        splitter_3->addWidget(name);
        stackedWidget->addWidget(stackedWidgetPage4);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Light"));
        label->setFont(font);
        LogOut_Button = new QPushButton(centralWidget);
        LogOut_Button->setObjectName(QStringLiteral("LogOut_Button"));
        LogOut_Button->setGeometry(QRect(730, 10, 81, 31));
        LogOut_Button->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 948, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        normalTrip->setText(QApplication::translate("MainWindow", "Regular Trip", 0));
        CustomTrip1->setText(QApplication::translate("MainWindow", "Custom Trip 1", 0));
        CustomTrip2->setText(QApplication::translate("MainWindow", "Custom Trip 2", 0));
        startTrip->setText(QApplication::translate("MainWindow", "Start Trip", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">Locations:</span></p></body></html>", 0));
        Selected_Locations_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">Distances:</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Number of Cities:</span></p></body></html>", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
         << QApplication::translate("MainWindow", "9", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QApplication::translate("MainWindow", "13", 0)
        );
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Menu:</span></p></body></html>", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Purchase", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Next City", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Current Location: </span></p></body></html>", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">NameOfCity</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Menu:</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Total Purchase:</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">$</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Current Purchase:</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">$</span></p></body></html>", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Kev", 0)
         << QApplication::translate("MainWindow", "Rahil", 0)
        );
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">God Mode: ON</span></p></body></html>", 0));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">~ Powers under construction ~</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "login", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Back to Normal", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Password:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">Username:</span></p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; text-decoration: underline; color:#ff0000;\">Tour de Europe:</span></p></body></html>", 0));
        LogOut_Button->setText(QApplication::translate("MainWindow", "Log In", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
