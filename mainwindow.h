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

    /*!
     * \brief FillTripTable
     *
     * fill up menu items used at current city
     */

    void FillTripTable();

    /*!
     * \brief FillItemMenu
     * \param CityName
     * fill up combo box with the menu items for specified city
     */
    void FillItemMenu(QString CityName);

    /*!
     * \brief FillAdminTableView
     *\param cityName
     *  fills the admins Table view box with the menu items
     * of any given city
     */
    void FillAdminTableView(QString CityName);


    /*!
     * \brief FillAdminComboBox
     *  fills the admins combo boxes for adding, updating and removing items
     */
    void FillAdminCB();

    void on_LogInButton_clicked();

    void on_pass_returnPressed();

    void on_LogOut_Button_clicked();

    void on_LogOut_Button_2_clicked();

    /*!
     * \brief clearCityTable
     *  clears all data when the traveler completes the trip
     */

    void clearCityTable();

    /*!
     * \brief clearItemsTable
     * clears all data from the items table when the traveler completes the trip
     */

    void clearItemsTable();
    /*!
     * \brief clearselectedCitiesTable
     * clears all data from the city table in the user mainPage
     */

    void clearselectedCitiesTable();
    /*!
     * \brief ClearAdminTable
     * clears all data from the Admin table
     */

    void ClearAdminTable();

    void on_addCityButton_clicked();

    void on_RemoveItemCityCB_currentIndexChanged(const QString &arg1);

    void on_AI_CN_CB_currentIndexChanged(const QString &arg1);

    void on_AddItemButton_clicked();

    void on_RemoveItemButton_clicked();

    /*!
     * \brief n_LocationsTableWidget_cellDoubleClicked
     * \param row
     * \param column
     * used when the user double clicks a city in main page for custom trip.
     */
    void on_LocationsTableWidget_cellDoubleClicked(int row, int column);

    void on_NextCity_pushButton_clicked();

    void on_Purchase_pushButton_clicked();


    /*!
     * \brief SortTrip
     *  \param temp
     * \param currCity
     * get queue from sql function.
     * if(first value in queue NOT IN visited list)
     * add to SortedQueue.
     * else - since it is in the list
     * popfirst item in the queue
     * recursively call function 1 (this time the 1st value in queue is the next closes place)
     */

    void SortTrip(QQueue<QString> temp, QString currCity);

    bool Find(QString srchCity);

    void on_NextCity_pushButton_2_clicked();

    /*!
     * \brief SortCustom
     *  \param value
     * used to sort the users chosen cities for trip 3
     * using recursion
     */

    void sortCustom(QString value);


    /*!
     * \brief isThisCitySelected
     *  \param CityToCheck
     * This function will check whether given city have been selected for trip.
     * \return t/f
     */
    bool isThisCitySelected(QString cityToCheck);

    /*!
     * \brief isThisCityVisited
     *  \param CityToCheck
     *  This function will check whether given city has already been visited.
     * \return t/f
     */
    bool isThisCityVisited(QString cityToCheck);

    void on_AddFromDB_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    dbManager db;                   //Instance of the database

    int tripnum;                    //1 is Regular, 2 is custom, 3 is custom
    int index = 0;
    int count;
    double totCityPurch;
    double grandTotSpent;
    QString startingCity;

    QVector<QString> copyList;      //copy of cityNames
    QVector<QString> cityNames;     //Names of all cities
    QVector<QString> berlDists;     //Distance for all cities from berlin
    QVector<QString> cityfoodItems; //food items for a given city
    QQueue <QString> defTrip;       //the cities to visit for default trip
    QVector<ReceiptItem> receipt;   //a list of the total items purchased
    QVector<QString> citiesToVisit;   //a list of the cities to visit
    QVector<QString> sortedQueueToVisit;
    QVector<QString> citiesVisited;   //a list of the cities visited
    QVector<QString> closestCities;   //store the closest cities from any city
};

#endif // MAINWINDOW_H
