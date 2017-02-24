#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

}

void MainWindow::on_CustomTrip1_clicked()
{

}

void MainWindow::on_CustomTrip2_clicked()
{

    ui->comboBox->setBaseSize(1, 13);
}

void MainWindow::on_startTrip_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);

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
    ui->tableWidget_2->clear();
    int col = 0;
    int row = 0;

    ui->tableWidget_2->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->tableWidget_2->insertColumn(col);
    ui->tableWidget_2->setHorizontalHeaderItem(col, new QTableWidgetItem("Distance From Berlin (km)"));

    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < berlDists.size(); i++)
    {
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(berlDists.at(i)));
    }

    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
}



void MainWindow::on_LogOut_Button_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);

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


void MainWindow::on_LogOut_Button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage4);
}

void MainWindow::FillAdminTableView(){

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

void MainWindow::on_pass_returnPressed()
{
    ui->LogInButton->click();
}
