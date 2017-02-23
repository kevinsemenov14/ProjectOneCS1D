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
#include <QtWidgets/QDoubleSpinBox>
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
#include <QtWidgets/QTableView>
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
    QLabel *label_15;
    QPushButton *addCityButton;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *AddItemButton;
    QTableView *tableView;
    QTableView *tableView_2;
    QPushButton *LogOut_Button;
    QSplitter *splitter_5;
    QLabel *label_14;
    QLineEdit *AddCityName;
    QSplitter *splitter_6;
    QComboBox *RemoveCity_CB;
    QPushButton *removeCityButton;
    QSplitter *splitter_7;
    QLabel *label_16;
    QSpinBox *AddedCityBerlDist;
    QSplitter *splitter_8;
    QLabel *label_21;
    QComboBox *AI_CN_CB;
    QSplitter *splitter_9;
    QLabel *label_20;
    QDoubleSpinBox *AddedItemPrice;
    QSplitter *splitter_10;
    QLabel *label_19;
    QLineEdit *AddedItemName;
    QWidget *stackedWidgetPage4;
    QPushButton *LogInButton;
    QSplitter *splitter_2;
    QLabel *label_13;
    QLineEdit *pass;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(948, 629);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 60, 791, 441));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        normalTrip = new QPushButton(stackedWidgetPage1);
        normalTrip->setObjectName(QStringLiteral("normalTrip"));
        normalTrip->setGeometry(QRect(20, 50, 81, 31));
        normalTrip->setCursor(QCursor(Qt::PointingHandCursor));
        normalTrip->setStyleSheet(QStringLiteral(""));
        CustomTrip1 = new QPushButton(stackedWidgetPage1);
        CustomTrip1->setObjectName(QStringLiteral("CustomTrip1"));
        CustomTrip1->setGeometry(QRect(20, 90, 81, 31));
        CustomTrip1->setCursor(QCursor(Qt::PointingHandCursor));
        CustomTrip1->setStyleSheet(QStringLiteral(""));
        CustomTrip2 = new QPushButton(stackedWidgetPage1);
        CustomTrip2->setObjectName(QStringLiteral("CustomTrip2"));
        CustomTrip2->setGeometry(QRect(20, 130, 81, 31));
        CustomTrip2->setCursor(QCursor(Qt::PointingHandCursor));
        CustomTrip2->setStyleSheet(QStringLiteral(""));
        startTrip = new QPushButton(stackedWidgetPage1);
        startTrip->setObjectName(QStringLiteral("startTrip"));
        startTrip->setGeometry(QRect(640, 390, 81, 31));
        startTrip->setCursor(QCursor(Qt::PointingHandCursor));
        startTrip->setStyleSheet(QStringLiteral(""));
        LocationsTableWidget = new QTableWidget(stackedWidgetPage1);
        LocationsTableWidget->setObjectName(QStringLiteral("LocationsTableWidget"));
        LocationsTableWidget->setGeometry(QRect(150, 50, 221, 381));
        LocationsTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        LocationsTableWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LocationsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2 = new QTableWidget(stackedWidgetPage1);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(400, 50, 221, 381));
        tableWidget_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
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
        label_4->setCursor(QCursor(Qt::IBeamCursor));
        comboBox = new QComboBox(stackedWidgetPage1);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(640, 80, 38, 20));
        comboBox->setCursor(QCursor(Qt::PointingHandCursor));
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
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QStringLiteral(""));
        pushButton_6 = new QPushButton(stackedWidgetPage2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(560, 380, 181, 23));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QStringLiteral(""));
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
        tableWidget_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableWidget_3->setSortingEnabled(true);

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
        label_11->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setCursor(QCursor(Qt::IBeamCursor));

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
        label_9->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_2->addWidget(label_10);

        splitter_4 = new QSplitter(stackedWidgetPage2);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(560, 80, 181, 20));
        splitter_4->setOrientation(Qt::Horizontal);
        comboBox_2 = new QComboBox(splitter_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox_2->setStyleSheet(QStringLiteral(""));
        splitter_4->addWidget(comboBox_2);
        spinBox = new QSpinBox(splitter_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox->setStyleSheet(QStringLiteral(""));
        splitter_4->addWidget(spinBox);
        stackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QStringLiteral("stackedWidgetPage3"));
        label_15 = new QLabel(stackedWidgetPage3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(410, 10, 71, 21));
        addCityButton = new QPushButton(stackedWidgetPage3);
        addCityButton->setObjectName(QStringLiteral("addCityButton"));
        addCityButton->setGeometry(QRect(110, 90, 75, 23));
        label_17 = new QLabel(stackedWidgetPage3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 10, 47, 13));
        label_18 = new QLabel(stackedWidgetPage3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 280, 47, 13));
        AddItemButton = new QPushButton(stackedWidgetPage3);
        AddItemButton->setObjectName(QStringLiteral("AddItemButton"));
        AddItemButton->setGeometry(QRect(180, 390, 75, 23));
        tableView = new QTableView(stackedWidgetPage3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(280, 70, 221, 351));
        tableView_2 = new QTableView(stackedWidgetPage3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(530, 70, 221, 351));
        LogOut_Button = new QPushButton(stackedWidgetPage3);
        LogOut_Button->setObjectName(QStringLiteral("LogOut_Button"));
        LogOut_Button->setGeometry(QRect(670, 20, 71, 31));
        LogOut_Button->setCursor(QCursor(Qt::PointingHandCursor));
        LogOut_Button->setStyleSheet(QStringLiteral(""));
        splitter_5 = new QSplitter(stackedWidgetPage3);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(10, 30, 174, 20));
        splitter_5->setOrientation(Qt::Horizontal);
        label_14 = new QLabel(splitter_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        splitter_5->addWidget(label_14);
        AddCityName = new QLineEdit(splitter_5);
        AddCityName->setObjectName(QStringLiteral("AddCityName"));
        splitter_5->addWidget(AddCityName);
        splitter_6 = new QSplitter(stackedWidgetPage3);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setGeometry(QRect(410, 30, 221, 21));
        splitter_6->setOrientation(Qt::Horizontal);
        RemoveCity_CB = new QComboBox(splitter_6);
        RemoveCity_CB->setObjectName(QStringLiteral("RemoveCity_CB"));
        splitter_6->addWidget(RemoveCity_CB);
        removeCityButton = new QPushButton(splitter_6);
        removeCityButton->setObjectName(QStringLiteral("removeCityButton"));
        splitter_6->addWidget(removeCityButton);
        splitter_7 = new QSplitter(stackedWidgetPage3);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setGeometry(QRect(10, 60, 171, 20));
        splitter_7->setOrientation(Qt::Horizontal);
        label_16 = new QLabel(splitter_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        splitter_7->addWidget(label_16);
        AddedCityBerlDist = new QSpinBox(splitter_7);
        AddedCityBerlDist->setObjectName(QStringLiteral("AddedCityBerlDist"));
        splitter_7->addWidget(AddedCityBerlDist);
        splitter_8 = new QSplitter(stackedWidgetPage3);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setGeometry(QRect(20, 300, 221, 20));
        splitter_8->setOrientation(Qt::Horizontal);
        label_21 = new QLabel(splitter_8);
        label_21->setObjectName(QStringLiteral("label_21"));
        splitter_8->addWidget(label_21);
        AI_CN_CB = new QComboBox(splitter_8);
        AI_CN_CB->setObjectName(QStringLiteral("AI_CN_CB"));
        splitter_8->addWidget(AI_CN_CB);
        splitter_9 = new QSplitter(stackedWidgetPage3);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setGeometry(QRect(20, 360, 221, 20));
        splitter_9->setOrientation(Qt::Horizontal);
        label_20 = new QLabel(splitter_9);
        label_20->setObjectName(QStringLiteral("label_20"));
        splitter_9->addWidget(label_20);
        AddedItemPrice = new QDoubleSpinBox(splitter_9);
        AddedItemPrice->setObjectName(QStringLiteral("AddedItemPrice"));
        splitter_9->addWidget(AddedItemPrice);
        splitter_10 = new QSplitter(stackedWidgetPage3);
        splitter_10->setObjectName(QStringLiteral("splitter_10"));
        splitter_10->setGeometry(QRect(20, 330, 221, 20));
        splitter_10->setOrientation(Qt::Horizontal);
        label_19 = new QLabel(splitter_10);
        label_19->setObjectName(QStringLiteral("label_19"));
        splitter_10->addWidget(label_19);
        AddedItemName = new QLineEdit(splitter_10);
        AddedItemName->setObjectName(QStringLiteral("AddedItemName"));
        splitter_10->addWidget(AddedItemName);
        stackedWidget->addWidget(stackedWidgetPage3);
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName(QStringLiteral("stackedWidgetPage4"));
        LogInButton = new QPushButton(stackedWidgetPage4);
        LogInButton->setObjectName(QStringLiteral("LogInButton"));
        LogInButton->setGeometry(QRect(390, 220, 71, 31));
        LogInButton->setCursor(QCursor(Qt::PointingHandCursor));
        LogInButton->setStyleSheet(QStringLiteral(""));
        splitter_2 = new QSplitter(stackedWidgetPage4);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(240, 180, 221, 21));
        splitter_2->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(splitter_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        splitter_2->addWidget(label_13);
        pass = new QLineEdit(splitter_2);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setStyleSheet(QStringLiteral(""));
        pass->setEchoMode(QLineEdit::Password);
        splitter_2->addWidget(pass);
        splitter_3 = new QSplitter(stackedWidgetPage4);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(240, 140, 221, 20));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        name = new QLineEdit(splitter_3);
        name->setObjectName(QStringLiteral("name"));
        name->setStyleSheet(QStringLiteral(""));
        splitter_3->addWidget(name);
        stackedWidget->addWidget(stackedWidgetPage4);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Light"));
        label->setFont(font);
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

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        normalTrip->setText(QApplication::translate("MainWindow", "Regular Trip", 0));
        CustomTrip1->setText(QApplication::translate("MainWindow", "Custom Trip 1", 0));
        CustomTrip2->setText(QApplication::translate("MainWindow", "Custom Trip 2", 0));
        startTrip->setText(QApplication::translate("MainWindow", "Start Trip", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Locations:</span></p></body></html>", 0));
        Selected_Locations_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Distances:</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Number of Cities:</span></p></body></html>", 0));
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
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Selected Food Items:</span></p></body></html>", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Purchase", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Next City", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Current Location: </span></p></body></html>", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">NameOfCity</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Menu:</span></p></body></html>", 0));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Total Purchase:</span></p></body></html>", 0));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">$</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Current Purchase:</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">$</span></p></body></html>", 0));
        label_15->setText(QApplication::translate("MainWindow", "Remove City:", 0));
        addCityButton->setText(QApplication::translate("MainWindow", "Add", 0));
        label_17->setText(QApplication::translate("MainWindow", "Add City:", 0));
        label_18->setText(QApplication::translate("MainWindow", "Add item:", 0));
        AddItemButton->setText(QApplication::translate("MainWindow", "Add", 0));
        LogOut_Button->setText(QApplication::translate("MainWindow", "Log Out", 0));
        label_14->setText(QApplication::translate("MainWindow", "Name:", 0));
        removeCityButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        label_16->setText(QApplication::translate("MainWindow", "Distance From Berlin", 0));
        label_21->setText(QApplication::translate("MainWindow", "City Name: ", 0));
        label_20->setText(QApplication::translate("MainWindow", "Price:", 0));
        label_19->setText(QApplication::translate("MainWindow", "Name:", 0));
        LogInButton->setText(QApplication::translate("MainWindow", "Log In", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Password:</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Username:</span></p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; text-decoration: underline; color:#000000;\">Tour de Europe:</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
