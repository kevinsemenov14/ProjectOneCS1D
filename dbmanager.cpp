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
    db.setDatabaseName("../project1.sqlite");
    db.open();
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
      query.prepare("SELECT name FROM City ORDER BY CityId");
    if(query.exec())
    {
        while(query.next()) //these seem to be coming out in alphabetical order by default
        {
            QString name =query.value(0).toString();
            //qDebug() << name;
            names.push_front(name);
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
    return names;

}

QString dbManager::getSadDist(QString CityName)
{
    QSqlQuery query(db);
    //QString dist;
    query.prepare("SELECT Dis2Sad FROM City WHERE name = (:CityName)");
    query.bindValue(":CityName", CityName);
    if(query.exec())
    {
        if(query.next())
        {
            double dist = query.value(0).toDouble();
           // qDebug() << dist;
            return QString::number(dist);
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
QString dbManager::getRev(QString CityName)
{
    QSqlQuery query(db);

    query.prepare("SELECT totRev FROM City WHERE name = (:CityName)");
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

    query.prepare("SELECT numItems FROM City WHERE name = (:CityName)");
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

QVector<QString> dbManager::getMenuItems(QString CityName)
{

    QSqlQuery query(db);
    QVector<QString> names;

    query.prepare("SELECT Name FROM MenuItems WHERE Owner = (:CityName)");
    query.bindValue(":CityName", CityName );

    if(query.exec())
    {

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

    query.prepare("SELECT Price FROM MenuItems WHERE Owner = (:CityName) AND Name = (:itemName)");
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

    query.prepare("SELECT * FROM MenuItems WHERE Owner = (:CityName) AND Name = (:itemName)");
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
bool dbManager::removeItem(QString CityName, QString itemName)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM MenuItems WHERE Owner = (:CityName) AND Name = (:itemName)");
    query.bindValue(":CityName", CityName);
    query.bindValue(":itemName", itemName);
    if(query.exec())
    {
        QSqlQuery query2(db);
        query2.prepare("SELECT numItems FROM City WHERE name = (:CityName) ");
        query2.bindValue(":CityName", CityName);
        if(query2.exec())
        {
            if(query2.next())
            {
                int count= query2.value(0).toInt(); //update the item count for the City
                QSqlQuery query3(db);
                query3.prepare("UPDATE City SET numItems = (:count) WHERE name = (:CityName)");
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
        query.prepare("UPDATE MenuItems SET Price = (:price) WHERE Owner = (:CityName) AND Name = (:itemName)");
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
        query.prepare("INSERT INTO MenuItems (Owner, Name, Price) VALUES (:CityName, :itemName, :price)");
        query.bindValue(":CityName", CityName);
        query.bindValue(":itemName", itemName);
        query.bindValue(":price", price);
        if(query.exec())
        {

           // qDebug() << "We good";

            QSqlQuery query2(db);
            query2.prepare("SELECT numItems FROM City WHERE name = (:CityName) ");
            query2.bindValue(":CityName", CityName);
            if(query2.exec())
            {
                if(query2.next())
                {
                    int count= query2.value(0).toInt(); //update the item count for the City
                    QSqlQuery query3(db);
                    query3.prepare("UPDATE City SET numItems = (:count) WHERE name = (:CityName)");
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

bool dbManager::addCity(QString CityName, double sadDist, QVector<double> distances)
{
    QSqlQuery query(db);
    QString distancesStr = distancesToString(distances);
    query.prepare("INSERT INTO City (name, dis2Sad, distances) VALUES (:CityName, :sadDist, :distStr)");
    query.bindValue(":CityName", CityName);
    query.bindValue(":sadDist", sadDist);
    query.bindValue(":distStr", distancesStr +" " + "0.0");
    if(query.exec())
    {
        //qDebug() << "should be added";
        updateDistances(distances);
        return true;
    }
    else
    {
        qDebug() << query.lastError();
    }
    return false;

}
QString dbManager::distancesToString(QVector<double> distances)
{
    QString distancesStr="";
    for(int i = 0; i < distances.size(); i++)
    {
        distancesStr += QString::number(distances.at(i) )+ " ";
    }

    return distancesStr.trimmed(); //cut of the ending white space
}

bool dbManager::updateDistances(QVector<double> distances)
{
    QSqlQuery query(db);
    qDebug() << distances.size();
     for(int i = 0; i < distances.size(); i++)
     {
         query.prepare("SELECT distances FROM City WHERE CityId = (:iId)");
         query.bindValue(":iId", i);
         if(query.exec())
         {
             while(query.next())
             {
                QString dist = query.value(0).toString(); //get the current City string
                QSqlQuery query2(db);
              //  qDebug() << dist;
               // qDebug() <<
                query2.prepare("UPDATE City SET distances = (:distStr) WHERE CityId = (:iId)");
                query2.bindValue(":iId", i);
                query2.bindValue(":distStr", (dist + " " + QString::number(distances.at(i))));
                if(query2.exec())
                {

                    //qDebug() << "Updated";
                }
                else
                {
                    qDebug() << query2.lastError();
                    return false;
                }

             }

         }

         else{
             query.lastError();
             return false;
         }
     }

    return true;
}

//QString dbManager::getCityName(int id)
//{
//    QSqlQuery query(db);
//    query.prepare("SELECT name FROM City WHERE CityId = (:id)");
//    query.bindValue(":id", id);
//    if(query.exec())
//    {
//        if(query.next())
//        {
//            QString name = query.value(0).toString();
//            return name;
//        }



//    }
//    return "error";
//}

QString dbManager::getDistances(QString CityName)
{
    QSqlQuery query(db);
    query.prepare("SELECT Distances FROM City WHERE name = (:CityName)");
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
    query.prepare("SELECT totRev FROM City WHERE name = (:CityName)");
     query.bindValue(":CityName", CityName );

     if(query.exec())
     {
         if(query.next())
         {
             double rev = query.value(0).toDouble();


             QSqlQuery query2(db);
             query2.prepare("UPDATE City SET totRev = (:newRev) WHERE name = (:CityName)");
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
