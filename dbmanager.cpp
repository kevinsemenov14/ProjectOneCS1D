#include "dbmanager.h"
#include <qdebug.h>
/*!
   * \file dbmanager.cpp
   * \brief  Source file for dbmanager database wrapper class methods
   *
   * This file contains all of the definitions of the dbmanager database wrapper class
   */


dbManager::dbManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Project1Database.db");
//    db.open();
    if(!db.open())
        qDebug() << "Not connected to DB.";
    else if(db.open())
        qDebug() << "Connected to DB.";
}



QVector<QString> dbManager:: getCityNames()
{
    QSqlQuery query(db);
    QVector<QString> names;

    //select in the order they are given
    query.prepare("SELECT name FROM Cities GROUP BY name");

    if(!query.exec())
    {
        qDebug() << query.lastError().text();
    }
    else
    {
        qDebug() << "made it here\n";

        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            QString name = query.value(0).toString();
            names.push_front(name);
        }
    }
    return names;
}



int dbManager::getDistfrom(QString StartingCity, QString EndingCity)
{
    QSqlQuery query(db);

    //select in the order they are given
    query.prepare("SELECT distance FROM Distances WHERE StartingCity = (:StartingCity) and EndingCity = (:EndingCity)");
    query.bindValue(":StartingCity", StartingCity);
    query.bindValue(":EndingCity", EndingCity);
    if(query.exec())
    {
        if(query.next())
        {
            int distancefromDB = query.value(0).toInt();
           // qDebug() << rev;
            return distancefromDB;
        }
        else
        {
            qDebug() << "Error";
        }

    }
    else
    {
        qDebug() << query.lastError();
        qDebug() << "NO distance found";
    }
}



//SELECT EndingCity, distance FROM Distances where StartingCity = "Berlin" order by distance ASC
QQueue<QString> dbManager::citiesToTisit(QString StartingCity)
{
    QSqlQuery query(db);
    QQueue<QString> citiesnearby;

    query.prepare("SELECT EndingCity FROM Distances where StartingCity = (:StartingCity) order by distance DESC");
    query.bindValue(":StartingCity", StartingCity);
    if(query.exec())
    {
        while(query.next())
        {
            QString current = query.value(0).toString();
            citiesnearby.push_front(current);
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }
    return citiesnearby;
}


QVector<QString> dbManager::getBerlinDist()
{
    QSqlQuery query(db);
    QVector<QString> berlDist;

    query.prepare("SELECT Dist2Ber FROM Cities ORDER BY CityId");

    if(query.exec())
    {
        while(query.next())
        {
            QString dist2Ber = query.value(0).toString();
            berlDist.push_front(dist2Ber);
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    return berlDist;
}



QString dbManager::getRev(QString CityName)
{
    QSqlQuery query(db);

    query.prepare("SELECT totRev FROM Cities WHERE name = (:CityName)");
    query.bindValue(":CityName", CityName);
    if(query.exec())
    {
        if(query.next())
        {
            double rev = query.value(0).toDouble();
           // qDebug() << rev;
            return QString::number(rev, 'f', 2);
        }
        else
        {
            return "Error";
        }

    }
    else
    {
        qDebug() << query.lastError();
        return "NO City found";
    }
}




QString dbManager::getNumItems(QString CityName)
{
    QSqlQuery query(db);

    query.prepare("SELECT numItems FROM Cities WHERE name = (:CityName)");
    query.bindValue(":CityName", CityName);
    if(query.exec())
    {
        if(query.next())
        {
            QString rev = query.value(0).toString();
           // qDebug() << rev;
            return rev;
        }
        else
        {
            return "Error";
        }

    }
    else
    {
        qDebug() << query.lastError();
        return "NO City found";
    }
}



QVector<QString> dbManager::getCityItems(QString CityName)
{

    QSqlQuery query(db);
    QVector<QString> names;

    query.prepare("SELECT food FROM foodTable WHERE city = (:CityName)");
    query.bindValue(":CityName", CityName );

    if(query.exec())
    {
        qDebug() << "Getting items";
        while(query.next()) //these seem to be coming out in alphabetical order by default
        {

            QString name =query.value(0).toString();
            names.push_back(name);
        }
    }
    else
    {
        qDebug() << query.lastError();
    }

    return names;

}



QString dbManager::getItemPrice(QString CityName, QString itemName)
{
    QSqlQuery query(db);

    query.prepare("SELECT cost FROM foodTable WHERE city = (:CityName) AND food = (:itemName)");
    query.bindValue(":CityName", CityName);
    query.bindValue(":itemName", itemName);

    if(query.exec())
    {
        if(query.next())
        {
            double price =  query.value(0).toDouble();
           // qDebug() << price;
            return QString::number(price, 'f', 2);
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
    return "price" ;
}



bool dbManager::Exists(QString CityName, QString itemName)
{
    QSqlQuery query(db);

    query.prepare("SELECT * FROM foodTable WHERE city = (:CityName) AND food = (:itemName)");
    query.bindValue(":CityName", CityName);
    query.bindValue(":itemName", itemName);
    if(query.exec())
    {
        if(query.next())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}




bool dbManager::cityExists(QString CityName)
{
    QSqlQuery query(db);

    query.prepare("SELECT name FROM Cities WHERE name = (:CityName)");
    query.bindValue(":CityName", CityName);

    if(query.exec())
    {
        if(query.next())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}


void dbManager::addCitiesFromDatabase()
{
    QSqlQuery query(db);

    query.prepare("INSERT into Distances SELECT * from newCitys");

    if(query.exec())
    {
        if(query.next())
        {
            qDebug() << "Value found";
        }
        else
        {
            qDebug() << "Value not found";
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
}


bool dbManager::removeItem(QString CityName, QString itemName)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM foodTable WHERE city = (:CityName) AND food = (:itemName)");
    query.bindValue(":CityName", CityName);
    query.bindValue(":itemName", itemName);
    if(query.exec())
    {
        QSqlQuery query2(db);
        query2.prepare("SELECT numItems FROM Cities WHERE name = (:CityName) ");
        query2.bindValue(":CityName", CityName);
        if(query2.exec())
        {
            if(query2.next())
            {
                int count= query2.value(0).toInt(); //update the item count for the City
                QSqlQuery query3(db);
                query3.prepare("UPDATE Cities SET numItems = (:count) WHERE name = (:CityName)");
                query3.bindValue(":CityName", CityName);
                query3.bindValue(":count", (count-1));
                if(query3.exec())
                {
                  //  qDebug() << "should be gone!";

                    return true;
                }
                else
                {
                    qDebug() << query3.lastError();
                }
            }
            else
            {
                qDebug() << "grabbing didn't work, query okay";
            }
        }
        else
        {
            qDebug() << query2.lastError();
        }
    }
    else
    {
        qDebug() << query.lastError();
        return false;
    }
}



bool dbManager::updateItem(QString CityName, QString itemName, double price)
{
    QSqlQuery query(db);
    if(Exists(CityName, itemName))
    {
        query.prepare("UPDATE foodTable SET cost = (:price) WHERE city = (:CityName) AND food = (:itemName)");
        query.bindValue(":CityName", CityName);
        query.bindValue(":itemName", itemName);
        query.bindValue(":price", price);
        if(query.exec())
        {
            qDebug() << "Updated";
            return true;
        }
        else
        {
            qDebug() << query.lastError();
        }
        return false;
    }
}




bool dbManager::addItem(QString CityName, QString itemName, double price)
{

    QSqlQuery query(db);
    if(!Exists(CityName, itemName))
    {
        query.prepare("INSERT INTO foodTable (city, food, cost) VALUES (:CityName, :itemName, :price)");
        query.bindValue(":CityName", CityName);
        query.bindValue(":itemName", itemName);
        query.bindValue(":price", price);
        if(query.exec())
        {

            qDebug() << "Value inserted";

            QSqlQuery query2(db);
            query2.prepare("SELECT numItems FROM Cities WHERE name = (:CityName) ");
            query2.bindValue(":CityName", CityName);

            if(query2.exec())
            {
                if(query2.next())
                {
                    int count= query2.value(0).toInt(); //update the item count for the City
                    QSqlQuery query3(db);
                    query3.prepare("UPDATE Cities SET numItems = (:count) WHERE name = (:CityName)");
                    query3.bindValue(":CityName", CityName);
                    query3.bindValue(":count", (count+1));
                    if(query3.exec())
                    {
                       // qDebug() << "Should be updated";
                        return true;
                    }
                    else
                    {
                        qDebug() << query3.lastError();
                    }
                }
                else
                {
                    qDebug() << "grabbing didn't work, query okay";
                }
            }
            else
            {
                qDebug() << query2.lastError();
            }
        }
        else
        {
            qDebug() << query.lastError();
        }
    }
    else
    {
        //do something if the item exists
        return false;
    }
    return false;
}

bool dbManager::addCity(QString CityName, double berDist)
{
    QSqlQuery query(db);
    QVector<QString> totNames = getCityNames();

    int newSize = totNames.size() + 1;

    query.prepare("INSERT INTO Cities (name, Dist2Ber, totRev, CityId) VALUES (:CityName, :berDist, :totRev, :newSize)");
    query.bindValue(":CityName", CityName);
    query.bindValue(":berDist", berDist);
    query.bindValue(":totRev", 0);
    query.bindValue(":newSize", newSize);

    if(query.exec())
    {
        //qDebug() << "should be added";
        return true;
    }
    else
    {
        qDebug() << query.lastError();
    }
    return false;

}

bool dbManager::AddDistance(QString startCity, QString endCity,double newDist)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO Distances (StartingCity, EndingCity, distance) VALUES (:startCity, :endCity, :newDist)");
    query.bindValue(":startCity", startCity);
    query.bindValue(":endCity", endCity);
    query.bindValue(":newDist", newDist);

    if(query.exec())
    {
        qDebug() << "new distance added";

        return true;
    }
    else
    {
        qDebug() << query.lastError();
    }
}

QString dbManager::distancesToString(QVector<int> distances)
{
    QString distancesStr = "";
    for(int i = 0; i < distances.size(); i++)
    {
        distancesStr += QString::number(distances.at(i) )+ " ";
    }
    return distancesStr.trimmed(); //cut of the ending white space
}

bool dbManager::updateDistances(QVector<double> distances)
{
//    QSqlQuery query(db);
//    qDebug() << distances.size();
//     for(int i = 0; i < distances.size(); i++)
//     {
//         query.prepare("SELECT Distances FROM Cities WHERE CityId = (:iId)");
//         query.bindValue(":iId", i);
//         if(query.exec())
//         {
//             while(query.next())
//             {
//                QString dist = query.value(0).toString(); //get the current City string
//                QSqlQuery query2(db);
//              //  qDebug() << dist;
//               // qDebug() <<
//                query2.prepare("UPDATE Cities SET Distances = (:distStr) WHERE CityId = (:iId)");
//                query2.bindValue(":iId", i);
//                query2.bindValue(":distStr", (dist + " " + QString::number(distances.at(i))));
//                if(query2.exec())
//                {

//                    //qDebug() << "Updated";
//                }
//                else
//                {
//                    qDebug() << query2.lastError();
//                    return false;
//                }

//             }

//         }

//         else{
//             query.lastError();
//             return false;
//         }
//     }

//    return true;
}


QString dbManager::getDistances(QString CityName)
{
    QSqlQuery query(db);
    query.prepare("SELECT Distances FROM Cities WHERE name = (:CityName)");
        query.bindValue(":CityName", CityName );
        if(query.exec())
        {
            if(query.next())
            {
                QString dist = query.value(0).toString();
                return dist;
            }
            else
            {
                qDebug() << "Error";
                return "Error";
            }
        }
        else
        {
            qDebug() << query.lastError();
            return "Error";
        }

}


bool dbManager::updateTotRev(QString CityName, double value)
{
    QSqlQuery query(db);
    query.prepare("SELECT totRev FROM Cities WHERE name = (:CityName)");
     query.bindValue(":CityName", CityName );

     if(query.exec())
     {
         if(query.next())
         {
             double rev = query.value(0).toDouble();


             QSqlQuery query2(db);
             query2.prepare("UPDATE Cities SET totRev = (:newRev) WHERE name = (:CityName)");
             query2.bindValue(":CityName", CityName );
             query2.bindValue(":newRev", rev+value );
             if(query2.exec())
             {
                 qDebug() << "Should be updated rev";
             }

         }
     }
     else
     {
         qDebug() << query.lastError();
         return "Error";
     }
}
