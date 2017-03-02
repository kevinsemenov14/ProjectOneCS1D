#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "dbmanager.h"
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

struct ReceiptItem
{
    QString itemName;
    double  amount;
    double  price;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_normalTrip_clicked();

    void on_CustomTrip1_clicked();

    void on_CustomTrip2_clicked();

    void on_startTrip_clicked();

    void FillTripTable();

    void FillItemMenu(QString CityName);

    void FillAdminTableView(QString CityName);

    void FillAdminCB();

    void on_LogInButton_clicked();

    void on_pass_returnPressed();

    void on_LogOut_Button_clicked();

    void on_LogOut_Button_2_clicked();

    void clearCityTable();

    void clearItemsTable();

    void clearselectedCitiesTable();

    void ClearAdminTable();

    void on_addCityButton_clicked();

    void on_RemoveItemCityCB_currentIndexChanged(const QString &arg1);

    void on_AI_CN_CB_currentIndexChanged(const QString &arg1);

    void on_AddItemButton_clicked();

    void on_RemoveItemButton_clicked();

    void on_LocationsTableWidget_cellDoubleClicked(int row, int column);

    QVector<int> distancestoStr(QString dist);

    void on_NextCity_pushButton_clicked();

    void on_Purchase_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    dbManager db;                   //Instance of the database

    int tripnum;                    //1 is Regular, 2 is custom, 3 is custom
    double totCityPurch;
    double grandTotSpent;

    QVector<QString> cityNames;     //Names of all cities
    QVector<QString> berlDists;     //Distance for all cities from berlin
    QVector<QString> cityfoodItems; //food items for a given city
    QQueue <QString> defTrip;       //the cities to visit for default trip
    QVector<ReceiptItem> receipt;   //a list of the total items purchased

};

#endif // MAINWINDOW_H
