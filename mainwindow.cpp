#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->startTrip->hide();
    ui->LogOut_Button->show();

    ui->stackedWidgetPage1->show();
    ui->stackedWidgetPage2->hide();
    ui->stackedWidgetPage3->hide();
    ui->stackedWidgetPage4->hide();

    ui->label_2->hide();
    ui->Selected_Locations_Label->hide();
    ui->label_4->hide();

    ui->LocationsTableWidget->hide();
    ui->tableWidget_2->hide();
    ui->comboBox->hide();

    cityNames = db.getCityNames();
    berlDists = db.getBerlinDist();
    FillTripTable();

    FillBerlinTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_normalTrip_clicked()
{
    ui->startTrip->show();

    ui->label_2->show();

    ui->Selected_Locations_Label->hide();

    ui->LocationsTableWidget->hide();

    ui->comboBox->hide();

    ui->label_4->hide();

    ui->LocationsTableWidget->show();

    ui->tableWidget_2->show();

    ui->LogOut_Button->show();
}

void MainWindow::on_CustomTrip1_clicked()
{
    ui->startTrip->show();

    ui->label_2->show();
    ui->Selected_Locations_Label->show();

     ui->comboBox->hide();
     ui->label_4->hide();

    ui->LocationsTableWidget->show();
    ui->tableWidget_2->show();

}

void MainWindow::on_CustomTrip2_clicked()
{
    ui->startTrip->show();

    ui->label_4->show();

    ui->Selected_Locations_Label->hide();

    ui->comboBox->show();
    ui->comboBox->setBaseSize(1, 13);
}

void MainWindow::on_startTrip_clicked()
{
    ui->stackedWidgetPage1->hide();
    ui->stackedWidgetPage2->show();
}

void MainWindow::FillTripTable()
{
    ui->LocationsTableWidget->clear();    //Clear the table
    int col = 0;                          //Initialize row and column to 0
    int row = 0;

    ui->LocationsTableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->LocationsTableWidget->insertColumn(col);
    ui->LocationsTableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("City Names"));

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
    ui->stackedWidgetPage1->hide();
    ui->stackedWidgetPage2->hide();
    ui->stackedWidgetPage3->hide();
    ui->stackedWidgetPage4->show();

    if(ui->LogOut_Button->text() == "Log Out")
    {
        ui->LogOut_Button->setText("Log In");
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString rightname = "Admin";
    QString rightpass = "cs1d";

    if(rightname == ui->name->text()&& rightpass == ui->pass->text())
    {
        ui->stackedWidget->setCurrentIndex(3);
        ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);    //Something's wrong here... Figure it out later
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
