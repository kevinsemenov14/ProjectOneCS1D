#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <qarraydata.h>

#include <QVector>
#include <qvector.h>

/*!
   * \file dbmanager.h
   * \brief  Header for database wrapper class
   *
   * This file contains all of the declarations of the dbmanager class
   */

/*!
 * \brief The dbManager class
 *
 * Manages the sqlite data base that contians citys and their menu items
 */
class dbManager
{

public:

    /*!
     * \brief dbManager
     *
     * Constructor
     */
    dbManager();


    //get all names for City
    /*!
     * \brief getCityNames
     *
     * Gets all city names and puts them in a QVector
     * \return QVector of city names
     */
    QVector<QString> getCityNames();
    //utility methods to retrieve other attributes


    /*!
     * \brief getSadDist
     *
     * Gets the specified citys distance to saddleback
     * \param CityName
     * \return the citys distance to saddleback
     */
    int getDistfrom(QString startCity, QString endCity);


    /*!
     * \brief getRev
     *
     * Gets the total revenue for the specified city
     * \param CityName
     * \return total lifetime revenue of a city
     */
    QString getRev(QString CityName);


    /*!
     * \brief getNumItems
     *
     * Returns the number of menu items a city has
     * \param CityName
     * \return number of items on the menu
     */
    QString getNumItems(QString CityName);


    /*!
     * \brief getItemPrice
     *
     * Returns the price of a certain item
     * \param CityName
     * \param itemName
     * \return item price
     */
    QString getItemPrice(QString CityName, QString itemName);


    /*!
     * \brief getMenuItems
     *
     * Returns the names of all menu items for a city
     * \param CityName
     * \return menu item names
     */
    QVector<QString> getCityItems(QString CityName);


    /*!
     * \brief Exists
     *
     * checks if a menu item exists
     * \param CityName
     * \param itemName
     * \return t/f if the item exists
     */
    bool Exists(QString CityName, QString itemName);


    /*!
     * \brief cityExists
     *
     * checks if a city exists
     * \param CityName
     * \return t/f if the city exists
     */
    bool cityExists(QString CityName);


    /*!
     * \brief removeItem
     *
     * Removes a menu item
     * \param CityName
     * \param itemName
     * \return t/f result of the operation
     */
    bool removeItem(QString CityName, QString itemName);


    /*!
     * \brief updateItem
     *
     * Updates a menu item's price
     * \param CityName
     * \param itemName
     * \param price
     * \return t/f result of the operation
     */
    bool updateItem(QString CityName, QString itemName, double price);


    /*!
     * \brief addItem
     *
     * Adds a new menu item
     * \param CityName
     * \param itemName
     * \return t/f result of the operation
     */
    bool addItem(QString CityName, QString itemName, double price);


    /*!
     * \brief addCity
     *
     * Adds a new city
     * \param CityName
     * \param sadDist
     * \param distances
     * \return t/f result of the operation
     */
    bool addCity(QString CityName, double sadDist, QVector<double> distances);


    /*!
     * \brief getCityName
     *
     * Gets a city name based on id
     * \param id
     * \return city name
     */
    QString getCityName(int id);


    /*!
     * \brief updateDistances
     *
     * Updates distances of previous citys when adding a new city
     * \param distances
     * \return t/f result of the operation
     */
    bool updateDistances(QVector<double> distances); //updates the previous Cityaurnts


    /*!
     * \brief distancesToString
     *
     * Parses a QVector of doubles into a single string for storage in the database
     * \param distances
     * \return QString of distances
     */
    QString distancesToString(QVector<int> distances); //converts the distances to a string to store in the db


    /*!
     * \brief getDistances
     *
     * Gets the distances to other citys for a city
     * \param CityName
     * \return distances in string form
     */
    QString getDistances(QString CityName);


    /*!
     * \brief updateTotRev
     *
     * Accumulates the total revenue for a city
     * \param CityName
     * \param value
     * \return t/f result of the operation
     */
    bool updateTotRev(QString CityName, double value);

    /*!
     * \brief updateTotRev
     *
     * Accumulates each city's distance to Berlin
     * \return t/f result of the operation
     */
    QVector<QString> getBerlinDist();



private:
    QSqlDatabase db; //the database

};

#endif // DBMANAGER_H
