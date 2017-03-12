#include "mainwindow.h"
#include "ui_mainwindow.h"

//SELECT EndingCity, distance FROM Distances where StartingCity = "Berlin" order by distance ASC

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tripnum = 0;

    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

    ui->AmountItems_spinBox->setMinimum(1);

    ui->AddedCityBerlDist->setMinimum(1);
    ui->AddedCityBerlDist->setMaximum(15000);
    ui->AddedCityBerlDist->setSuffix(" km");

    ui->AddedItemPrice->setMinimum(1.00);

    cityNames = db.getCityNames();
    berlDists = db.getBerlinDist();

    for(int i = berlDists.length() - 1; i >= 0; i--)
    {
        defTrip.push_back(cityNames[i]);
    }

    ui->spinBox_2->clear();
    ui->spinBox_2->setMinimum(1);
    ui->spinBox_2->setMaximum(cityNames.size()-1);

    double dist;
    dist = db.getDistfrom("Amsterdam", "Berlin");
    qDebug() << dist;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//This function starts the normal trip.
//Here we will start at London.
//We will then visit all possible cities
void MainWindow::on_normalTrip_clicked()
{
    int i = 0;
    tripnum = 1;
    totCityPurch = 0;
    grandTotSpent = 0;
    startingCity = "London";
    cityNames = db.getCityNames();

    citiesToVisit.clear();
    citiesVisited.clear();
    sortedQueueToVisit.clear();

    citiesToVisit.push_front(startingCity);
    sortedQueueToVisit.push_back(startingCity);
    citiesVisited.push_back(startingCity);

    //LOOP:
    //call funtion to find next closest city
    QQueue<QString> temp = db.citiesToTisit(startingCity);

    while( i < cityNames.size() - 1)
    {
        SortTrip(temp, temp.at(0));

        temp.clear();
        //calls the db method that gets the sorted queue of the next city with which the city
        //that recently got added to the sortedQueue gets passed into the db method that uses that
        //recently added city to return a new sorted list of the cities closest to THAT new city
        temp = db.citiesToTisit(sortedQueueToVisit.at(sortedQueueToVisit.size() - 1));
        i++;
    }

}

//Function: CustomTrip1
// Trip starts at Paris
// User gets to select number of cities they want to visit(including Paris).
void MainWindow::on_CustomTrip1_clicked()
{
    tripnum = 2;

    int numberOfCities = 0;
    int i = 0;

    cityNames.clear();
    cityNames = db.getCityNames();
    totCityPurch = 0;
    grandTotSpent = 0;
    citiesToVisit.clear();
    citiesVisited.clear();
    sortedQueueToVisit.clear();

    startingCity = "Paris";
    numberOfCities = ui->spinBox_2->value();
    citiesToVisit.push_front(startingCity);

    //LOOP:
    //call funtion to find next closest city
    sortedQueueToVisit.push_back(startingCity);
    citiesVisited.push_back(startingCity);

    QQueue<QString> temp = db.citiesToTisit(startingCity);

    while( i < numberOfCities)
    {
        SortTrip(temp, temp.at(0));

        temp.clear();
        //calls the db method that gets the sorted queue of the next city with which the city
        //that recently got added to the sortedQueue gets passed into the db method that uses that
        //recently added city to return a new sorted list of the cities closest to THAT new city
        temp = db.citiesToTisit(sortedQueueToVisit.at(sortedQueueToVisit.size() - 1));
        i++;
    }

}


//Function: CustomTrip2
//User will select a list of cities they want to visit.
//First place they select is the starting city
//All following cities will be calculated for nearest distance
void MainWindow::on_CustomTrip2_clicked()
{
    tripnum = 3;
    totCityPurch = 0;
    grandTotSpent = 0;

    citiesToVisit.clear();
    citiesVisited.clear();
    sortedQueueToVisit.clear();
    closestCities.clear();
}


//StartTrip Button:
//Pressing this button will start the selected trip.
void MainWindow::on_startTrip_clicked()
{
    if(tripnum == 0)
    {
        QMessageBox errorBox;
        errorBox.warning(0,"Invalid Selection","Please select a trip!");
        errorBox.setFixedSize(1200,400);
    }
    else if(!sortedQueueToVisit.empty())
    {
        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
        FillItemMenu(sortedQueueToVisit.front());
        int col = 0;
        int row = 0;

        ui->SelectedItemsTableWidget->horizontalHeader()->setVisible(true);

        ui->SelectedItemsTableWidget->insertColumn(col);
        ui->SelectedItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Name:"));

        ui->SelectedItemsTableWidget->resizeColumnsToContents();
        ui->SelectedItemsTableWidget->horizontalHeader()->setStretchLastSection(true);
        ui->CurrentCityLabel->setText(sortedQueueToVisit.front());
    }
    else
    {
        QMessageBox errorBox;
        errorBox.warning(0, "Invalid Selection","You've already taken this trip!");
        errorBox.setFixedSize(1200,400);
    }

    int i = 0;

    if(tripnum == 3)
    {
        qDebug() << "STARTING CITY: " << startingCity;
        sortCustom(startingCity);
//        QQueue<QString> temp = db.citiesToTisit(startingCity);
//        while( i < citiesToVisit.size() - 1)
//        {
//            SortTrip(temp, temp.at(0));

//            temp.clear();
//            //calls the db method that gets the sorted queue of the next city with which the city
//            //that recently got added to the sortedQueue gets passed into the db method that uses that
//            //recently added city to return a new sorted list of the cities closest to THAT new city
//            temp = db.citiesToTisit(sortedQueueToVisit.at(sortedQueueToVisit.size() - 1));
//            i++;
//        }
    }
}




//Function 1:
//get queue from sql function.
//if(first value in queue NOT IN visited list)
// add to SortedQueue.
//else - since it is in the list
// popfirst item in the queue
// recursively call function 1 (this time the 1st value in queue is the next closes place)
void MainWindow::SortTrip(QQueue<QString> temp, QString currCity)
{
    if(!Find(currCity))
    {
        sortedQueueToVisit.push_back(temp.front());

        qDebug() << temp.front();
        citiesVisited.push_back(temp.front());
    }
    else
    {
        temp.pop_front();
        SortTrip(temp, temp.front());
    }
}

void MainWindow::sortCustom(QString value)
{

    QQueue<QString> temp = db.citiesToTisit(value);
    if(citiesToVisit.size() != 0){
        for(int i = 0; i < temp.size(); i++)
        {
             for(int j = 0; j < citiesToVisit.size(); j++)
             {
                 if(temp.at(i) == citiesToVisit.at(j))
                 {

                     qDebug() << "FOUND:" << citiesToVisit.at(j);
                    sortedQueueToVisit.push_back(temp.at(i));
                    citiesVisited.push_back(temp.at(i));
                    citiesToVisit.removeAt(j);
                    sortCustom(sortedQueueToVisit.at(sortedQueueToVisit.size()-1));
                 }

             }

       }
   }// end recursive condition statement
   temp.clear();
}


//Function 2:
//takes in a QString.
//return bool
//checks if that QString is in the visited list vector.
bool MainWindow::Find(QString srchCity)
{
    bool found = false;
    int i = 0;

    while(!found && i < citiesVisited.size())
    {
        if(citiesVisited[i] == srchCity)
        {
            found = true;
        }
        i++;
    }
    return found;
}

/*
 * Function: FillTripTable
 * Task: To take the data from the database and populate the TableWidget for
 *          the user to view in the UI.
 */
void MainWindow::FillTripTable()
{

    cityNames.clear();
    berlDists.clear();

    cityNames = db.getCityNames();
    berlDists = db.getBerlinDist();

    ui->LocationsTableWidget->clear();    //Clear the table
    ui->selectedCitiesTable->clear();

    int col = 0;                          //Initialize row and column to 0
    int row = 0;

    ui->LocationsTableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->LocationsTableWidget->insertColumn(col);
    ui->LocationsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Distance to Berlin(km)"));

    ui->LocationsTableWidget->insertColumn(col);
    ui->LocationsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("City Names"));

    ui->LocationsTableWidget->resizeColumnsToContents();
    ui->LocationsTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < cityNames.size(); i++)
    {
        int numRows = ui->LocationsTableWidget->rowCount();
        ui->LocationsTableWidget->insertRow(numRows);
        ui->LocationsTableWidget->setItem(numRows, 0, new QTableWidgetItem(cityNames.at(i)));
        ui->LocationsTableWidget->setItem(numRows, 1, new QTableWidgetItem(berlDists.at(i)));
    }

    ui->LocationsTableWidget->resizeColumnsToContents();
    ui->LocationsTableWidget->horizontalHeader()->setStretchLastSection(true);
}



/*
 * Function: FillItemMenu
 * Task: To take the items of a given city from the database and populate the
 *        TableWidget for the user to view in the UI.
 */
void MainWindow::FillItemMenu(QString CityName)
{
    cityfoodItems.clear();
    cityfoodItems = db.getCityItems(CityName);

    ui->ItemsComboBox->clear();
    ui->ItemsTableWidget->clear();

    ui->ItemsTableWidget->setRowCount(0);
    ui->ItemsTableWidget->setColumnCount(0);
    int col = 0;
    int row = 0;

    ui->ItemsTableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->ItemsTableWidget->insertColumn(col);
    ui->ItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Price:"));


    ui->ItemsTableWidget->insertColumn(col);
    ui->ItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Name:"));


    ui->ItemsTableWidget->resizeColumnsToContents();
    ui->ItemsTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < cityfoodItems.size(); i++)
    {
        int numRows = ui->ItemsTableWidget->rowCount();
        ui->ItemsTableWidget->insertRow(numRows);

        ui->ItemsTableWidget->setItem(numRows, 0, new QTableWidgetItem(cityfoodItems.at(i)));
        ui->ItemsTableWidget->setItem(numRows, 1, new QTableWidgetItem(db.getItemPrice(CityName, cityfoodItems.at(i))));

        ui->ItemsComboBox->addItem(cityfoodItems.at(i));
    }

    ui->ItemsTableWidget->resizeColumnsToContents();
    ui->ItemsTableWidget->horizontalHeader()->setStretchLastSection(true);

}



/*
 * Function: FillAdminTableView
 * Task: To take the items of a given city from the database and populate the
 *        TableWidget for the admin to view in the UI.
 */
void MainWindow::FillAdminTableView(QString CityName)
{
    cityfoodItems.clear();
    cityfoodItems = db.getCityItems(CityName);
    ui->RemoveItemCB->clear();

    int col = 0;                          //Initialize row and column to 0
    int row = 0;

    ui->tableWidgetAdmin->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->tableWidgetAdmin->insertColumn(col);
    ui->tableWidgetAdmin->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Price"));

    ui->tableWidgetAdmin->insertColumn(col);
    ui->tableWidgetAdmin->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Name"));

    ui->tableWidgetAdmin->resizeColumnsToContents();
    ui->tableWidgetAdmin->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < cityfoodItems.size(); i++)
    {
        ui->tableWidgetAdmin->insertRow(row);
        ui->tableWidgetAdmin->setItem(row, 0, new QTableWidgetItem(cityfoodItems.at(i)));
        ui->tableWidgetAdmin->setItem(row, 1, new QTableWidgetItem(db.getItemPrice(CityName, cityfoodItems.at(i))));
        ui->RemoveItemCB->addItem(cityfoodItems.at(i));
    }
    ui->tableWidgetAdmin->resizeColumnsToContents();
    ui->tableWidgetAdmin->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::FillAdminCB()
{

    ui->RemoveItemCityCB->clear();
    ui->AI_CN_CB->clear();

    for(int i = 0; i < cityNames.size(); i++)
    {
        ui->RemoveItemCityCB->addItem(cityNames.at(i));
        ui->AI_CN_CB->addItem(cityNames.at(i));
    }

}


/*
 * Function: LogInButton_clicked
 * Task: Allow user or admin to log in with a valid ID.
 *        Print an error if they enter an incorrect ID or Password.
 */
void MainWindow::on_LogInButton_clicked()
{
    QString adminID = "Admin";
    QString adminPassword = "a";
    QString userID = "User";
    QString userPassword = "a";

    if(adminID == ui->name->text() && adminPassword == ui->pass->text())
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);

        ClearAdminTable();

        ui->AddNewCity_scrollArea->hide();

        FillAdminTableView("Amsterdam");
        FillAdminCB();

        ui->LogOut_Button->setText("Log Out");
    }

    else if(userID == ui->name->text() && userPassword == ui->pass->text())
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);

        clearCityTable();
        clearselectedCitiesTable();
        clearItemsTable();

        FillTripTable();

        ui->LogOut_Button->setText("Log Out");
    }

    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Input","Invalid ID or Password");
        messageBox.setFixedSize(1200,400);
    }

    ui->name->clear();
    ui->pass->clear();

}

/*
 * Function: pass_returnPressed
 * Task: Shortcut to login without having to drag the mouse over LogIn button.
 */
void MainWindow::on_pass_returnPressed()
{
    ui->LogInButton->click();
}

/*
 * Function: LogOut_Button
 * Task: Log out the Admin.
 */
void MainWindow::on_LogOut_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

    clearCityTable();
    clearItemsTable();
    clearselectedCitiesTable();
    ClearAdminTable();
}

/*
 * Function: LogOut_Button_2
 * Task: Log out the User.
 */
void MainWindow::on_LogOut_Button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

    clearCityTable();
    clearItemsTable();
    clearselectedCitiesTable();
    ClearAdminTable();
}



/*
 * Function: clearCityTable
 * Task: To clear the TableWigdet so that data does not repeat incase of
 *        the user decides to make another trip.
 */
void MainWindow::clearCityTable()
{
    int currentRows = ui->LocationsTableWidget->rowCount();
    int currentCol =  ui->LocationsTableWidget->columnCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->LocationsTableWidget->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->LocationsTableWidget->removeColumn(0);
    }
    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->LocationsTableWidget->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->LocationsTableWidget->removeColumn(0);
    }
}


/*
 * Function: clearItemsTable
 * Task: To clear the TableWigdet so that data does not repeat incase of
 *        the user decides to make another trip.
 */
void MainWindow::clearItemsTable()
{
    int currentRows = ui->ItemsTableWidget->rowCount();
    int currentCol =  ui->ItemsTableWidget->columnCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->ItemsTableWidget->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->ItemsTableWidget->removeColumn(0);
    }
    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->ItemsTableWidget->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->ItemsTableWidget->removeColumn(0);
    }
}



/*
 * Function: clearselectedCitiesTable
 * Task: To clear the TableWigdet so that data does not repeat incase of
 *        the user decides to make another trip.
 */
void MainWindow::clearselectedCitiesTable()
{
    ui->selectedCitiesTable->clear();
//    int currentRows = ui->selectedCitiesTable->rowCount();
//    int currentCol =  ui->selectedCitiesTable->columnCount();

//    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
//    {
//        ui->selectedCitiesTable->removeRow(0);
//    }
//    for(int colRemove = 0; colRemove < currentCol; colRemove++)
//    {
//        ui->selectedCitiesTable->removeColumn(0);
//    }
//    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
//    {
//        ui->selectedCitiesTable->removeRow(0);
//    }
//    for(int colRemove = 0; colRemove < currentCol; colRemove++)
//    {
//        ui->selectedCitiesTable->removeColumn(0);
//    }
}



/*
 * Function: clearAdminTable
 * Task: To clear the TableWigdet so that data does not repeat.
 */
void MainWindow::ClearAdminTable()
{
    int currentRows = ui->tableWidgetAdmin->rowCount();
    int currentCol =  ui->tableWidgetAdmin->columnCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->tableWidgetAdmin->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->tableWidgetAdmin->removeColumn(0);
    }
    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->tableWidgetAdmin->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->tableWidgetAdmin->removeColumn(0);
    }
}



/*
 * Function: addCityButton
 * Task: To add new city to the database.
 * Restriction: User has to enter a name and distance to berlin.
 *              Without the above data, the city will not be added to database
 */
void MainWindow::on_addCityButton_clicked()
{
    QString cityToAdd;
    int distToBerlin;
    bool failed, allSpaces;

    cityToAdd = ui->AddCityName->text();
    distToBerlin = ui->AddedCityBerlDist->value();
    failed = false;
    allSpaces = true;

    for(int i = 0; i < cityToAdd.size(); i++)
    {
        if(!cityToAdd.at(i).isSpace())
        {
            allSpaces = false;
        }
    }

    for(int i = 0; i < cityToAdd.size(); i++)
    {
        if(cityToAdd.at(i).isNumber())
        {
            QMessageBox CityNumBox;
            CityNumBox.critical(0, "Invalid Entry!", "Numbers are Prohibited");
            CityNumBox.setFixedSize(1200, 400);
            failed = true;
            break;
        }
        else if(cityToAdd.at(i).isPunct())
        {
            QMessageBox CityPunctBox;
            CityPunctBox.critical(0, "Invalid Entry!", "Punctuation is Prohibited");
            CityPunctBox.setFixedSize(1200, 400);
            failed = true;
            break;
        }
        else if(cityToAdd.at(i).isSymbol())
        {
            QMessageBox CitySymbolBox;
            CitySymbolBox.critical(0, "Invalid Entry!", "Symbols are Prohibited");
            CitySymbolBox.setFixedSize(1200, 400);
            failed = true;
            break;
        }
        else
        {
            failed = false;
        }
    }
    if(cityToAdd.isEmpty())
    {
        QMessageBox CityExistsBox;
        CityExistsBox.critical(0, "Entry not found!", "Please Enter a Name!");
        CityExistsBox.setFixedSize(1200, 400);
        failed = true;
    }
    else if(allSpaces)
    {
        QMessageBox CityExistsBox;
        CityExistsBox.critical(0, "Entry not found!", "Please Enter a Name!");
        CityExistsBox.setFixedSize(1200, 400);
        failed = true;
    }
    if(!failed)
    {
        if(db.cityExists(cityToAdd))
        {
            QMessageBox CityExistsBox;
            CityExistsBox.critical(0, "City already exists!", "Can not add existing city");
            CityExistsBox.setFixedSize(1200, 400);
        }
        else
        {
//            db.addCity(cityToAdd, distToBerlin);

            ui->AddNewCity_scrollArea->show();

            copyList = cityNames;

            ui->CityName_label_9->setText(copyList.at(0));

            QMessageBox CityExistsBox;
            CityExistsBox.setText("Addition Successful!");
            CityExistsBox.setInformativeText("The city has been added");
            CityExistsBox.setStandardButtons(QMessageBox::Ok);
            CityExistsBox.exec();

            on_AI_CN_CB_currentIndexChanged(ui->RemoveItemCityCB->currentText());
        }
    }
}


void MainWindow::on_RemoveItemCityCB_currentIndexChanged(const QString &arg1)
{
    ClearAdminTable();
    FillAdminTableView(arg1);
    ui->label_27->setText(arg1);
}



void MainWindow::on_AI_CN_CB_currentIndexChanged(const QString &arg1)
{
    ClearAdminTable();
    FillAdminTableView(arg1);
    ui->label_27->setText(arg1);
}


void MainWindow::on_AddItemButton_clicked()
{
    QString nameToAdd = ui->AddedItemName->text();
    bool failed = false;
    bool isSpace = true;

    for(int i = 0; i < nameToAdd.size(); i++)
    {
        if(!nameToAdd.at(i).isSpace())
        {
            isSpace = false;
        }
    }

    for(int i = 0; i < nameToAdd.size(); i++)
    {
        if(nameToAdd.at(i).isDigit())
        {
            QMessageBox msgBox;
            msgBox.critical(0,"Invalid Input","Numbers are prohibited");
            msgBox.setFixedSize(1200,400);
            failed = true;
            break;
        }
        else if(nameToAdd.at(i).isPunct())
        {
            QMessageBox msgBox;
            msgBox.critical(0,"Invalid Input","Punctuations are prohibited");
            msgBox.setFixedSize(1200,400);
            failed = true;
            break;
        }
        else if(nameToAdd.at(i).isSymbol())
        {
            QMessageBox msgBox;
            msgBox.critical(0,"Invalid Input","Symbols are prohibited");
            msgBox.setFixedSize(1200,400);
            failed = true;
            break;
        }
    }

    if(nameToAdd.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.critical(0,"Name not found!","Enter a name");
        msgBox.setFixedSize(1200,600);
        failed = true;
    }

    else if(isSpace)
    {
        failed = false;
    }

    //If all tests for invalid input fail, then the input must be valid.
    //Add it to the database
    if(!failed)
    {
        if(db.Exists(ui->AI_CN_CB->currentText(), nameToAdd))
        {
    //      Update the item price using following statement:
            db.updateItem(ui->AI_CN_CB->currentText(), nameToAdd, ui->AddedItemPrice->value());

            QMessageBox ExistingBox;
            ExistingBox.information(0, "Item already exists!", "Price updated to new value");
            ExistingBox.setFixedSize(1200, 400);
        }
        else
        {
            //ADD ITEM using:
            db.addItem(ui->AI_CN_CB->currentText(), nameToAdd, ui->AddedItemPrice->value());
        }

        on_AI_CN_CB_currentIndexChanged(ui->AI_CN_CB->currentText());
    }
}




void MainWindow::on_RemoveItemButton_clicked()
{
    QString cityforItemRemove = ui->RemoveItemCityCB->currentText();
    QString itemToRemove = ui->RemoveItemCB->currentText();

    db.removeItem(cityforItemRemove, itemToRemove);

    on_RemoveItemCityCB_currentIndexChanged(ui->RemoveItemCityCB->currentText());

    QMessageBox pop;
    pop.information(0, "DELETION SUCCESSFUL", "Value deleted!");
    pop.setFixedSize(1200, 400);
}


void MainWindow::on_LocationsTableWidget_cellDoubleClicked(int row, int column)
{
    QString namesS = db.getCityNames().at(row);
//    qDebug() << "CITY: " << namesS;
    if(isThisCitySelected(namesS))
    {
        QMessageBox msgBox;
        msgBox.critical(0,"Existing City!","Duplicate cities are not permitted");
        msgBox.setFixedSize(1200,400);
    }
    else
    {
        qDebug() << "CITY: " << namesS;
        ui->selectedCitiesTable->addItem(namesS);
        if(citiesToVisit.size() == 0)
        {
            startingCity = namesS;
            citiesToVisit.push_front(startingCity);
            citiesVisited.push_front(startingCity);
            sortedQueueToVisit.push_front(startingCity);

        }
        else
        {
            citiesToVisit.push_back(namesS);


        }
        count++;
    }
}



void MainWindow::on_NextCity_pushButton_clicked()
{
    sortedQueueToVisit.pop_front();
    if(tripnum == 3 && isThisCityVisited(sortedQueueToVisit.at(0)))
    {
        sortedQueueToVisit.pop_front();
    }

    if(!sortedQueueToVisit.empty())
    {
        FillItemMenu(sortedQueueToVisit.front());
        ui->CurrentCityLabel->setText(sortedQueueToVisit.front());
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(5);
        ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage5);
    }
    ui->currPurchase_label->setText(QString::number(0.00));
}

void MainWindow::on_Purchase_pushButton_clicked()
{
    double currPurchase;

    currPurchase = (db.getItemPrice(defTrip.front(),ui->ItemsComboBox->currentText()).toDouble())
                  * ui->AmountItems_spinBox->value();
    ReceiptItem item = {ui->ItemsComboBox->currentText(),ui->AmountItems_spinBox->value(), currPurchase};
    receipt.push_back(item);
    totCityPurch += currPurchase;
    grandTotSpent += currPurchase;

    int numRows = ui->SelectedItemsTableWidget->rowCount();
    ui->SelectedItemsTableWidget->insertRow(numRows);
    ui->SelectedItemsTableWidget->setItem(numRows,0,new QTableWidgetItem(item.itemName));
    ui->SelectedItemsTableWidget->resizeColumnsToContents();
    ui->SelectedItemsTableWidget->horizontalHeader()->setStretchLastSection(true);

    int numRows2 = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(numRows2);
    ui->tableWidget->setItem(numRows2,0,new QTableWidgetItem(item.itemName));
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


    ui->label_12->setText("$" + QString::number(totCityPurch));
    ui->currPurchase_label->setText("$" + QString::number(currPurchase));
    ui->label_24->setText("$" + QString::number(totCityPurch));
}

void MainWindow::on_NextCity_pushButton_2_clicked()
{
    QString distance = ui->NewDistance_lineEdit->text();

    bool failed = false;

    if(distance.size() > 0)
    {
        for(int i = 0; i < distance.size(); i++)
        {
            if(!distance.at(i).isDigit())
            {
                QMessageBox msgBox;
                msgBox.critical(0,"Invalid Input","Please enter a VALID NUMBER");
                msgBox.setFixedSize(1200,400);
                failed = true;
                break;
            }
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.critical(0,"Invalid Input","Please enter a NUMBER");
        msgBox.setFixedSize(1200,400);
        failed = true;
    }

    if(!failed)
    {
        if(index < copyList.size() - 1)
        {
            db.AddDistance(ui->AddCityName->text(), ui->CityName_label_9->text(), ui->NewDistance_lineEdit->text().toDouble());
            db.AddDistance(ui->CityName_label_9->text(),ui->AddCityName->text() , ui->NewDistance_lineEdit->text().toDouble());

            index++;
            ui->CityName_label_9->setText(copyList.at(index));

            ui->NewDistance_lineEdit->clear();
        }
        else
        {
            QMessageBox CityExistsBox;
            CityExistsBox.setText("Additions Successful!");
            CityExistsBox.setInformativeText("All distances has been added");
            CityExistsBox.setStandardButtons(QMessageBox::Ok);
            CityExistsBox.exec();
            ui->AddNewCity_scrollArea->hide();
        }
    }
    else
    {
         ui->NewDistance_lineEdit->clear();
    }
}



bool MainWindow::isThisCitySelected(QString cityToCheck)
{
    for(int i = 0; i < citiesToVisit.size(); i++)
    {
        if(cityToCheck == citiesToVisit.at(i))
        {
            return true;
        }
    }
    return false;
}


bool MainWindow::isThisCityVisited(QString cityToCheck)
{
    bool check = false;
    for(int i = 0; i < citiesVisited.size(); i++)
    {
        if(cityToCheck == citiesVisited.at(i))
            check = true;
        else
            check = false;
    }
    return check;
}
