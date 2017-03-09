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
    ui->spinBox_2->setMaximum(cityNames.size());

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
    tripnum = 1;
    totCityPurch = 0;
    grandTotSpent = 0;
    citiesToVisit.clear();
    citiesVisited.clear();
    startingCity = "London";
    cityNames = db.getCityNames();
    citiesToVisit = db.getCityNames();
    //LOOP:
    //call funtion to find next closest city
    //
}


//Function: CustomTrip1
// Trip starts at Paris
// User gets to select number of cities they want to visit(including Paris).
void MainWindow::on_CustomTrip1_clicked()
{
    int numberOfCities;

    cityNames = db.getCityNames();
    tripnum = 2;
    totCityPurch = 0;
    grandTotSpent = 0;
    numberOfCities = 0;
    citiesToVisit.clear();
    citiesVisited.clear();
    startingCity = "Paris";
    numberOfCities = ui->spinBox_2->value();

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
    else
    {
        if(!defTrip.empty())
        {
            ui->stackedWidget->setCurrentIndex(2);
            ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
            FillItemMenu(defTrip.front());
            int col = 0;
            int row = 0;

            ui->SelectedItemsTableWidget->horizontalHeader()->setVisible(true);

            ui->SelectedItemsTableWidget->insertColumn(col);
            ui->SelectedItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Name:"));

            ui->SelectedItemsTableWidget->resizeColumnsToContents();
            ui->SelectedItemsTableWidget->horizontalHeader()->setStretchLastSection(true);
            ui->CurrentCityLabel->setText(defTrip.front());
        }
        else
        {
            QMessageBox errorBox;
            errorBox.warning(0, "Invalid Selection","You've already taken this trip!");
            errorBox.setFixedSize(1200,400);
        }
//        ui->comboBox->hide();

    }
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
            QMessageBox CityExistsBox;
            CityExistsBox.setText("Addition Successful!");
            CityExistsBox.setInformativeText("The city has been added");
            CityExistsBox.setStandardButtons(QMessageBox::Ok);
            CityExistsBox.exec();
//            db.addCity(cityToAdd, distToBerlin, "");
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

    if(db.Exists(ui->AI_CN_CB->currentText(), nameToAdd))
    {
//      Update the item price using following statement:
        db.updateItem(ui->AI_CN_CB->currentText(), nameToAdd, ui->AddedItemPrice->value());

        on_AI_CN_CB_currentIndexChanged(ui->AI_CN_CB->currentText());

        QMessageBox ExistingBox;
        ExistingBox.information(0, "Item already exists!", "Price updated to new value");
        ExistingBox.setFixedSize(1200, 400);
        failed = true;
    }
    else if(nameToAdd.isEmpty() || nameToAdd.at(0).isNull())
    {
        QMessageBox msgBox;
        msgBox.critical(0,"Name not found!","Enter a name");
        msgBox.setFixedSize(1200,600);
        failed = true;
    }
    else
    {
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
    }

    if(isSpace)
    {
        failed = false;
    }
    //If all tests for invalid input fail, then the input must be valid.
    //Add it to the database
    if(!failed)
    {
        //ADD ITEM using:
        db.addItem(ui->AI_CN_CB->currentText(), nameToAdd, ui->AddedItemPrice->value());
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
    ui->selectedCitiesTable->addItem(namesS);
}




QVector<int> MainWindow::distancestoStr(QString dist) {
    /* * QVector<double> distDoubles;
     * QString dist = db.getDistances("Chipotle");
     * //get the distances for specified rest
     * //qDebug() << dist;
     * distDoubles= distancestoStr(dist);
     * //parse the distances string out, then assign it to
     * the object, qvector has the = operator overloaded
     * qDebug() << distDoubles; */

//    QVector<int> distDoubles;
//    QStringList list = dist.split(' ');

//    //qDebug() << list;
//    for(int i = 0; i < list.size(); i++){
//        QString temp= list.at(i);
//        distDoubles.push_back(Distance(i, temp.toInt()));
//    }

//    qSort(distDoubles.begin(),distDoubles.end(), DistSort());


//    return distDoubles;
}

void MainWindow::on_NextCity_pushButton_clicked()
{
    defTrip.pop_front();

    if(!defTrip.empty())
    {
        FillItemMenu(defTrip.front());
        ui->CurrentCityLabel->setText(defTrip.front());
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
