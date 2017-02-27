#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tripnum = 0;

    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

    ui->spinBox->setMinimum(1);
    ui->AddedCityBerlDist->setMinimum(1);
    ui->AddedCityBerlDist->setSuffix(" km");
    ui->AddedItemPrice->setMinimum(0.50);

    cityNames = db.getCityNames();
    berlDists = db.getBerlinDist();
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
}


//Function: CustomTrip1
// Trip starts at Paris
// User gets to select number of cities they want to visit(including Paris).
void MainWindow::on_CustomTrip1_clicked()
{
    tripnum = 2;
    ui->comboBox->setBaseSize(1, 13);
}


//Function: CustomTrip2
//User will select a list of cities they want to visit.
//First place they select is the starting city
//All following cities will be calculated for nearest distance
void MainWindow::on_CustomTrip2_clicked()
{

    tripnum = 3;


}


//StartTrip Button:
//Pressing this button will start the selected trip.
void MainWindow::on_startTrip_clicked()
{
    if(tripnum == 0)
    {
        QMessageBox errorBox;
        errorBox.critical(0,"Invalid Selection","Please select a trip!");
        errorBox.setFixedSize(1200,400);
    }
    else
    {
        ui->comboBox->hide();
        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
        FillItemMenu("Amsterdam");
        ui->CurrentCityLabel->setText("Hardcoded: Amsterdam");
    }
}




/*
 * Function: FillTripTable
 * Task: To take the data from the database and populate the TableWidget for
 *          the user to view in the UI.
 */
void MainWindow::FillTripTable()
{
    ui->LocationsTableWidget->clear();    //Clear the table
    int col = 0;                          //Initialize row and column to 0
    int row = 0;

    ui->LocationsTableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->LocationsTableWidget->insertColumn(col);
    ui->LocationsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("City Names:"));

    ui->LocationsTableWidget->resizeColumnsToContents();
    ui->LocationsTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < cityNames.size(); i++)
    {
        ui->LocationsTableWidget->insertRow(row);
        ui->LocationsTableWidget->setItem(row, 0, new QTableWidgetItem(cityNames.at(i)));
    }

    ui->LocationsTableWidget->resizeColumnsToContents();
    ui->LocationsTableWidget->horizontalHeader()->setStretchLastSection(true);
}




/*
 * Function: FillBerlinTable
 * Task: To take the distance of each city from Berlin from the database
 *        and populate the TableWidget for the user to view in the UI.
 */
void MainWindow::FillBerlinTable()
{
    ui->selectedCitiesTable->clear();
    int col = 0;
    int row = 0;

    ui->selectedCitiesTable->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->selectedCitiesTable->insertColumn(col);
    ui->selectedCitiesTable->setHorizontalHeaderItem(col, new QTableWidgetItem("Distance From Berlin (km)"));

    ui->selectedCitiesTable->resizeColumnsToContents();
    ui->selectedCitiesTable->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < berlDists.size(); i++)
    {
        ui->selectedCitiesTable->insertRow(row);
        ui->selectedCitiesTable->setItem(row, 0, new QTableWidgetItem(berlDists.at(i)));
    }

    ui->selectedCitiesTable->resizeColumnsToContents();
    ui->selectedCitiesTable->horizontalHeader()->setStretchLastSection(true);
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
        ui->ItemsTableWidget->insertRow(row);

        ui->ItemsTableWidget->setItem(row, 0, new QTableWidgetItem(cityfoodItems.at(i)));
        ui->ItemsTableWidget->setItem(row, 1, new QTableWidgetItem(db.getItemPrice(CityName, cityfoodItems.at(i))));

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
    }

    ui->tableWidgetAdmin->resizeColumnsToContents();
    ui->tableWidgetAdmin->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::FillAdminCB()
{

    ui->RemoveCity_CB->clear();
    ui->AI_CN_CB->clear();

    for(int i = 0; i < cityNames.size(); i++)
    {
        ui->RemoveCity_CB->addItem(cityNames.at(i));
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
        FillTripTable();
        FillBerlinTable();
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
    int currentRows = ui->selectedCitiesTable->rowCount();
    int currentCol =  ui->selectedCitiesTable->columnCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->selectedCitiesTable->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->selectedCitiesTable->removeColumn(0);
    }
    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->selectedCitiesTable->removeRow(0);
    }
    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        ui->selectedCitiesTable->removeColumn(0);
    }
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
    if((ui->AddCityName->text() != "") && (ui->AddedCityBerlDist->value() != 0))
    {

    }
}



void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage5);
}


void MainWindow::on_RemoveCity_CB_currentIndexChanged(const QString &arg1)
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

