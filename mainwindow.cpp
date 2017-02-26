#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * WORKING ON: Selecting items from ItemsTableWidget to SelectedItemsTableWidget
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
    ui->AddedItemPrice->setMinimum(1.25);
    cityNames = db.getCityNames();
    berlDists = db.getBerlinDist();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_normalTrip_clicked()
{
    tripnum = 1;
}

void MainWindow::on_CustomTrip1_clicked()
{
    tripnum = 2;
}

void MainWindow::on_CustomTrip2_clicked()
{

    tripnum = 2;
    ui->comboBox->show();
    ui->comboBox->setBaseSize(1, 13);

}

void MainWindow::on_startTrip_clicked()
{
    ui->comboBox->hide();
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
    FillItemMenu("Amsterdam");
    ui->CurrentCityLabel->setText("Hardcoded: Amsterdam");
}

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



void MainWindow::FillItemMenu(QString CityName)
{
    cityfoodItems = db.getCityItems(CityName);

    ui->ItemsComboBox->clear();
    ui->ItemsTableWidget->clear();

    int col = 0;
    int row = 0;

    ui->ItemsTableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->ItemsTableWidget->insertColumn(col);
    ui->ItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Name:"));


    ui->ItemsTableWidget->insertColumn(col);
    ui->ItemsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("Item Price:"));


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


void MainWindow::FillAdminTableView()
{

        int col = 0;                          //Initialize row and column to 0
        int row = 0;

        ui->tableWidgetAdmin->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

        ui->tableWidgetAdmin->insertColumn(col);
        ui->tableWidgetAdmin->setHorizontalHeaderItem(col, new QTableWidgetItem("City Names"));

        ui->tableWidgetAdmin->resizeColumnsToContents();
        ui->tableWidgetAdmin->horizontalHeader()->setStretchLastSection(true);

        for(int i = 0; i < cityNames.size(); i++)
        {
            ui->tableWidgetAdmin->insertRow(row);
            ui->tableWidgetAdmin->setItem(row, 0, new QTableWidgetItem(cityNames.at(i)));
        }

        ui->tableWidgetAdmin->resizeColumnsToContents();
        ui->tableWidgetAdmin->horizontalHeader()->setStretchLastSection(true);
}

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
        FillAdminTableView();
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
void MainWindow::on_pass_returnPressed()
{
    ui->LogInButton->click();
}
void MainWindow::on_LogOut_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

    clearCityTable();
    clearItemsTable();
    clearselectedCitiesTable();
    ClearAdminTable();
}
void MainWindow::on_LogOut_Button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

    clearCityTable();
    clearItemsTable();
    clearselectedCitiesTable();
    ClearAdminTable();
}


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
