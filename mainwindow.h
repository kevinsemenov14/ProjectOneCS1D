#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

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

    void FillBerlinTable();

    void FillItemMenu(QString CityName);

    void FillAdminTableView();

    void on_LogInButton_clicked();

    void on_pass_returnPressed();

    void on_LogOut_Button_clicked();

    void on_LogOut_Button_2_clicked();

    void clearCityTable();

    void clearItemsTable();

    void clearselectedCitiesTable();

    void ClearAdminTable();

private:
    Ui::MainWindow *ui;
    dbManager db;                   //Instance of the database

    int tripnum;                    //1 is Regular, 2 is custom, 3 is custom

    QVector<QString> cityNames;     //Names of all cities
    QVector<QString> berlDists;     //Distance for all cities from berlin
    QVector<QString> cityfoodItems; //food items for a given city

};

#endif // MAINWINDOW_H
