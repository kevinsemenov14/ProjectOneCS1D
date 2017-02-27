/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QPushButton *normalTrip;
    QPushButton *CustomTrip1;
    QPushButton *CustomTrip2;
    QSpacerItem *verticalSpacer_5;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_8;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *Selected_Locations_Label;
    QSpacerItem *horizontalSpacer_10;
    QTableWidget *LocationsTableWidget;
    QTableWidget *selectedCitiesTable;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_9;
    QLabel *label_4;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_6;
    QPushButton *startTrip;
    QWidget *stackedWidgetPage2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QTableWidget *SelectedItemsTableWidget;
    QSplitter *splitter;
    QLabel *label_5;
    QLabel *CurrentCityLabel;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTableWidget *ItemsTableWidget;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout;
    QSplitter *splitter_4;
    QComboBox *ItemsComboBox;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_6;
    QWidget *stackedWidgetPage3;
    QPushButton *LogOut_Button;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_3;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_4;
    QSplitter *splitter_5;
    QLabel *label_14;
    QLineEdit *AddCityName;
    QSplitter *splitter_7;
    QLabel *label_16;
    QSpinBox *AddedCityBerlDist;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addCityButton;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_4;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_5;
    QSplitter *splitter_6;
    QComboBox *RemoveCity_CB;
    QPushButton *removeCityButton;
    QWidget *layoutWidget8;
    QGridLayout *gridLayout_5;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_6;
    QSplitter *splitter_8;
    QLabel *label_21;
    QComboBox *AI_CN_CB;
    QSplitter *splitter_10;
    QLabel *label_19;
    QLineEdit *AddedItemName;
    QSplitter *splitter_9;
    QLabel *label_20;
    QDoubleSpinBox *AddedItemPrice;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *AddItemButton;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QLabel *label_6;
    QTableWidget *tableWidgetAdmin;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_27;
    QWidget *stackedWidgetPage4;
    QWidget *layoutWidget9;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *name;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter_2;
    QLabel *label_13;
    QLineEdit *pass;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *LogInButton;
    QWidget *stackedWidgetPage5;
    QPushButton *LogOut_Button_2;
    QWidget *layoutWidget10;
    QGridLayout *gridLayout_10;
    QSplitter *splitter_11;
    QLabel *label_23;
    QLabel *label_24;
    QSpacerItem *verticalSpacer_7;
    QSplitter *splitter_12;
    QLabel *label_25;
    QLabel *label_26;
    QWidget *layoutWidget11;
    QGridLayout *gridLayout_11;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_8;
    QTableWidget *tableWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(767, 595);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 50, 731, 441));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        layoutWidget = new QWidget(stackedWidgetPage1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 77, 381));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        normalTrip = new QPushButton(layoutWidget);
        normalTrip->setObjectName(QStringLiteral("normalTrip"));
        normalTrip->setCursor(QCursor(Qt::PointingHandCursor));
        normalTrip->setStyleSheet(QStringLiteral(""));

        gridLayout_7->addWidget(normalTrip, 0, 0, 1, 1);

        CustomTrip1 = new QPushButton(layoutWidget);
        CustomTrip1->setObjectName(QStringLiteral("CustomTrip1"));
        CustomTrip1->setCursor(QCursor(Qt::PointingHandCursor));
        CustomTrip1->setStyleSheet(QStringLiteral(""));

        gridLayout_7->addWidget(CustomTrip1, 1, 0, 1, 1);

        CustomTrip2 = new QPushButton(layoutWidget);
        CustomTrip2->setObjectName(QStringLiteral("CustomTrip2"));
        CustomTrip2->setCursor(QCursor(Qt::PointingHandCursor));
        CustomTrip2->setStyleSheet(QStringLiteral(""));

        gridLayout_7->addWidget(CustomTrip2, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_5, 3, 0, 1, 1);

        layoutWidget1 = new QWidget(stackedWidgetPage1);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 20, 451, 411));
        gridLayout_8 = new QGridLayout(layoutWidget1);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_8->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_9, 0, 1, 1, 1);

        Selected_Locations_Label = new QLabel(layoutWidget1);
        Selected_Locations_Label->setObjectName(QStringLiteral("Selected_Locations_Label"));

        gridLayout_8->addWidget(Selected_Locations_Label, 0, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_10, 0, 3, 1, 1);

        LocationsTableWidget = new QTableWidget(layoutWidget1);
        LocationsTableWidget->setObjectName(QStringLiteral("LocationsTableWidget"));
        LocationsTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        LocationsTableWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        LocationsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_8->addWidget(LocationsTableWidget, 1, 0, 1, 2);

        selectedCitiesTable = new QTableWidget(layoutWidget1);
        selectedCitiesTable->setObjectName(QStringLiteral("selectedCitiesTable"));
        selectedCitiesTable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        selectedCitiesTable->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        selectedCitiesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_8->addWidget(selectedCitiesTable, 1, 2, 1, 2);

        layoutWidget2 = new QWidget(stackedWidgetPage1);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(590, 50, 111, 381));
        gridLayout_9 = new QGridLayout(layoutWidget2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setCursor(QCursor(Qt::IBeamCursor));

        gridLayout_9->addWidget(label_4, 0, 0, 1, 2);

        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout_9->addWidget(comboBox, 1, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_11, 1, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_6, 2, 0, 1, 2);

        startTrip = new QPushButton(layoutWidget2);
        startTrip->setObjectName(QStringLiteral("startTrip"));
        startTrip->setCursor(QCursor(Qt::PointingHandCursor));
        startTrip->setStyleSheet(QStringLiteral(""));

        gridLayout_9->addWidget(startTrip, 3, 0, 1, 2);

        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QStringLiteral("stackedWidgetPage2"));
        layoutWidget3 = new QWidget(stackedWidgetPage2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(260, 50, 221, 361));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        SelectedItemsTableWidget = new QTableWidget(layoutWidget3);
        SelectedItemsTableWidget->setObjectName(QStringLiteral("SelectedItemsTableWidget"));
        SelectedItemsTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ForbiddenCursor)));
        SelectedItemsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        SelectedItemsTableWidget->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout_2->addWidget(SelectedItemsTableWidget);

        splitter = new QSplitter(stackedWidgetPage2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(20, 20, 201, 16));
        splitter->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setCursor(QCursor(Qt::ForbiddenCursor));
        splitter->addWidget(label_5);
        CurrentCityLabel = new QLabel(splitter);
        CurrentCityLabel->setObjectName(QStringLiteral("CurrentCityLabel"));
        CurrentCityLabel->setCursor(QCursor(Qt::IBeamCursor));
        splitter->addWidget(CurrentCityLabel);
        layoutWidget4 = new QWidget(stackedWidgetPage2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 50, 221, 361));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        ItemsTableWidget = new QTableWidget(layoutWidget4);
        ItemsTableWidget->setObjectName(QStringLiteral("ItemsTableWidget"));
        ItemsTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        ItemsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ItemsTableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ItemsTableWidget->setSortingEnabled(true);

        verticalLayout->addWidget(ItemsTableWidget);

        layoutWidget5 = new QWidget(stackedWidgetPage2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(500, 71, 211, 331));
        gridLayout = new QGridLayout(layoutWidget5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter_4 = new QSplitter(layoutWidget5);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        ItemsComboBox = new QComboBox(splitter_4);
        ItemsComboBox->setObjectName(QStringLiteral("ItemsComboBox"));
        ItemsComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        ItemsComboBox->setStyleSheet(QStringLiteral(""));
        splitter_4->addWidget(ItemsComboBox);
        spinBox = new QSpinBox(splitter_4);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setCursor(QCursor(Qt::PointingHandCursor));
        spinBox->setStyleSheet(QStringLiteral(""));
        splitter_4->addWidget(spinBox);

        gridLayout->addWidget(splitter_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new QLabel(layoutWidget5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout_2->addWidget(label_10);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_11 = new QLabel(layoutWidget5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setCursor(QCursor(Qt::IBeamCursor));

        horizontalLayout->addWidget(label_12);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 7, 0, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButton_6, 8, 0, 1, 1);

        stackedWidget->addWidget(stackedWidgetPage2);
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QStringLiteral("stackedWidgetPage3"));
        LogOut_Button = new QPushButton(stackedWidgetPage3);
        LogOut_Button->setObjectName(QStringLiteral("LogOut_Button"));
        LogOut_Button->setGeometry(QRect(640, 20, 61, 21));
        LogOut_Button->setCursor(QCursor(Qt::PointingHandCursor));
        LogOut_Button->setStyleSheet(QStringLiteral(""));
        layoutWidget6 = new QWidget(stackedWidgetPage3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 10, 251, 111));
        gridLayout_3 = new QGridLayout(layoutWidget6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget6);
        label_17->setObjectName(QStringLiteral("label_17"));
        QFont font;
        font.setUnderline(true);
        label_17->setFont(font);

        gridLayout_3->addWidget(label_17, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        splitter_5 = new QSplitter(layoutWidget6);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label_14 = new QLabel(splitter_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        splitter_5->addWidget(label_14);
        AddCityName = new QLineEdit(splitter_5);
        AddCityName->setObjectName(QStringLiteral("AddCityName"));
        splitter_5->addWidget(AddCityName);

        gridLayout_3->addWidget(splitter_5, 1, 0, 1, 2);

        splitter_7 = new QSplitter(layoutWidget6);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Horizontal);
        label_16 = new QLabel(splitter_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        splitter_7->addWidget(label_16);
        AddedCityBerlDist = new QSpinBox(splitter_7);
        AddedCityBerlDist->setObjectName(QStringLiteral("AddedCityBerlDist"));
        splitter_7->addWidget(AddedCityBerlDist);

        gridLayout_3->addWidget(splitter_7, 2, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        addCityButton = new QPushButton(layoutWidget6);
        addCityButton->setObjectName(QStringLiteral("addCityButton"));

        gridLayout_3->addWidget(addCityButton, 3, 1, 1, 1);

        layoutWidget7 = new QWidget(stackedWidgetPage3);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 160, 251, 61));
        gridLayout_4 = new QGridLayout(layoutWidget7);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget7);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_4->addWidget(label_15, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        splitter_6 = new QSplitter(layoutWidget7);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        RemoveCity_CB = new QComboBox(splitter_6);
        RemoveCity_CB->setObjectName(QStringLiteral("RemoveCity_CB"));
        splitter_6->addWidget(RemoveCity_CB);
        removeCityButton = new QPushButton(splitter_6);
        removeCityButton->setObjectName(QStringLiteral("removeCityButton"));
        splitter_6->addWidget(removeCityButton);

        gridLayout_4->addWidget(splitter_6, 1, 0, 1, 2);

        layoutWidget8 = new QWidget(stackedWidgetPage3);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(20, 260, 241, 151));
        gridLayout_5 = new QGridLayout(layoutWidget8);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget8);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        gridLayout_5->addWidget(label_18, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        splitter_8 = new QSplitter(layoutWidget8);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setOrientation(Qt::Horizontal);
        label_21 = new QLabel(splitter_8);
        label_21->setObjectName(QStringLiteral("label_21"));
        splitter_8->addWidget(label_21);
        AI_CN_CB = new QComboBox(splitter_8);
        AI_CN_CB->setObjectName(QStringLiteral("AI_CN_CB"));
        splitter_8->addWidget(AI_CN_CB);

        gridLayout_5->addWidget(splitter_8, 1, 0, 1, 2);

        splitter_10 = new QSplitter(layoutWidget8);
        splitter_10->setObjectName(QStringLiteral("splitter_10"));
        splitter_10->setOrientation(Qt::Horizontal);
        label_19 = new QLabel(splitter_10);
        label_19->setObjectName(QStringLiteral("label_19"));
        splitter_10->addWidget(label_19);
        AddedItemName = new QLineEdit(splitter_10);
        AddedItemName->setObjectName(QStringLiteral("AddedItemName"));
        splitter_10->addWidget(AddedItemName);

        gridLayout_5->addWidget(splitter_10, 2, 0, 1, 2);

        splitter_9 = new QSplitter(layoutWidget8);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setOrientation(Qt::Horizontal);
        label_20 = new QLabel(splitter_9);
        label_20->setObjectName(QStringLiteral("label_20"));
        splitter_9->addWidget(label_20);
        AddedItemPrice = new QDoubleSpinBox(splitter_9);
        AddedItemPrice->setObjectName(QStringLiteral("AddedItemPrice"));
        splitter_9->addWidget(AddedItemPrice);

        gridLayout_5->addWidget(splitter_9, 3, 0, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 4, 0, 1, 1);

        AddItemButton = new QPushButton(layoutWidget8);
        AddItemButton->setObjectName(QStringLiteral("AddItemButton"));

        gridLayout_5->addWidget(AddItemButton, 4, 1, 1, 1);

        widget = new QWidget(stackedWidgetPage3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(298, 10, 258, 401));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_6->addWidget(label_6, 1, 0, 1, 1);

        tableWidgetAdmin = new QTableWidget(widget);
        tableWidgetAdmin->setObjectName(QStringLiteral("tableWidgetAdmin"));
        tableWidgetAdmin->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetAdmin->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidgetAdmin->setSortingEnabled(true);

        gridLayout_6->addWidget(tableWidgetAdmin, 2, 0, 1, 5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_12, 1, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_13, 1, 3, 1, 1);

        label_27 = new QLabel(widget);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_6->addWidget(label_27, 1, 2, 1, 1);

        stackedWidget->addWidget(stackedWidgetPage3);
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName(QStringLiteral("stackedWidgetPage4"));
        layoutWidget9 = new QWidget(stackedWidgetPage4);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(229, 164, 261, 103));
        gridLayout_2 = new QGridLayout(layoutWidget9);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(layoutWidget9);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_3->addWidget(label_3);
        name = new QLineEdit(splitter_3);
        name->setObjectName(QStringLiteral("name"));
        name->setStyleSheet(QStringLiteral(""));
        splitter_3->addWidget(name);

        gridLayout_2->addWidget(splitter_3, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        splitter_2 = new QSplitter(layoutWidget9);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(splitter_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        splitter_2->addWidget(label_13);
        pass = new QLineEdit(splitter_2);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setStyleSheet(QStringLiteral(""));
        pass->setEchoMode(QLineEdit::Password);
        splitter_2->addWidget(pass);

        gridLayout_2->addWidget(splitter_2, 2, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        LogInButton = new QPushButton(layoutWidget9);
        LogInButton->setObjectName(QStringLiteral("LogInButton"));
        LogInButton->setCursor(QCursor(Qt::PointingHandCursor));
        LogInButton->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(LogInButton, 3, 1, 1, 1);

        stackedWidget->addWidget(stackedWidgetPage4);
        stackedWidgetPage5 = new QWidget();
        stackedWidgetPage5->setObjectName(QStringLiteral("stackedWidgetPage5"));
        LogOut_Button_2 = new QPushButton(stackedWidgetPage5);
        LogOut_Button_2->setObjectName(QStringLiteral("LogOut_Button_2"));
        LogOut_Button_2->setGeometry(QRect(630, 400, 61, 21));
        LogOut_Button_2->setCursor(QCursor(Qt::PointingHandCursor));
        LogOut_Button_2->setStyleSheet(QStringLiteral(""));
        layoutWidget10 = new QWidget(stackedWidgetPage5);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(380, 60, 291, 161));
        gridLayout_10 = new QGridLayout(layoutWidget10);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        splitter_11 = new QSplitter(layoutWidget10);
        splitter_11->setObjectName(QStringLiteral("splitter_11"));
        splitter_11->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(splitter_11);
        label_23->setObjectName(QStringLiteral("label_23"));
        splitter_11->addWidget(label_23);
        label_24 = new QLabel(splitter_11);
        label_24->setObjectName(QStringLiteral("label_24"));
        splitter_11->addWidget(label_24);

        gridLayout_10->addWidget(splitter_11, 0, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_7, 1, 0, 1, 1);

        splitter_12 = new QSplitter(layoutWidget10);
        splitter_12->setObjectName(QStringLiteral("splitter_12"));
        splitter_12->setOrientation(Qt::Horizontal);
        label_25 = new QLabel(splitter_12);
        label_25->setObjectName(QStringLiteral("label_25"));
        splitter_12->addWidget(label_25);
        label_26 = new QLabel(splitter_12);
        label_26->setObjectName(QStringLiteral("label_26"));
        splitter_12->addWidget(label_26);

        gridLayout_10->addWidget(splitter_12, 2, 0, 1, 1);

        layoutWidget11 = new QWidget(stackedWidgetPage5);
        layoutWidget11->setObjectName(QStringLiteral("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(20, 20, 321, 411));
        gridLayout_11 = new QGridLayout(layoutWidget11);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget11);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_11->addWidget(label_22, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        tableWidget = new QTableWidget(layoutWidget11);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_11->addWidget(tableWidget, 1, 0, 1, 2);

        stackedWidget->addWidget(stackedWidgetPage5);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Yu Gothic UI Light"));
        label->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 767, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        normalTrip->setText(QApplication::translate("MainWindow", "Regular Trip", Q_NULLPTR));
        CustomTrip1->setText(QApplication::translate("MainWindow", "Custom Trip 1", Q_NULLPTR));
        CustomTrip2->setText(QApplication::translate("MainWindow", "Custom Trip 2", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Locations:</span></p></body></html>", Q_NULLPTR));
        Selected_Locations_Label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#000000;\">Distances:</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Number of Cities:</span></p></body></html>", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
         << QApplication::translate("MainWindow", "11", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12", Q_NULLPTR)
         << QApplication::translate("MainWindow", "13", Q_NULLPTR)
        );
        startTrip->setText(QApplication::translate("MainWindow", "Start Trip", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Selected Food Items:</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Current Location: </span></p></body></html>", Q_NULLPTR));
        CurrentCityLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">NameOfCity</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Menu:</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Current Purchase:</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">$</span></p></body></html>", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Purchase", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Total Purchase:</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">$</span></p></body></html>", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Next City", Q_NULLPTR));
        LogOut_Button->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Add City:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Distance From Berlin", Q_NULLPTR));
        addCityButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Remove City:", Q_NULLPTR));
        removeCityButton->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Add item/Update Price:", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "City Name: ", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Price:", Q_NULLPTR));
        AddItemButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "View Data for City:", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Username:</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">Password:</span></p></body></html>", Q_NULLPTR));
        LogInButton->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        LogOut_Button_2->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Total Amount Spent ($):", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Total Distance Travelled(km):", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Trip Details:", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Items Bought", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Location", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Price", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; text-decoration: underline; color:#000000;\">Tour de Europe:</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
