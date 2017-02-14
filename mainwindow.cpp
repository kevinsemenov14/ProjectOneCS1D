#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->startTrip->hide();

    ui->stackedWidgetPage1->show();
    ui->stackedWidgetPage2->hide();
    ui->stackedWidgetPage3->hide();
    ui->stackedWidgetPage4->hide();

    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();

    ui->tableWidget->hide();
    ui->tableWidget_2->hide();
    ui->comboBox->hide();

    cityNames = db.getCityNames();
    FillTripTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_normalTrip_clicked()
{
    ui->startTrip->show();

    ui->label_2->show();

    ui->tableWidget->show();
}

void MainWindow::on_CustomTrip1_clicked()
{
    ui->startTrip->show();

    ui->label_2->show();
    ui->label_3->show();

    ui->tableWidget->show();
    ui->tableWidget_2->show();

}

void MainWindow::on_CustomTrip2_clicked()
{
    ui->startTrip->show();

    ui->label_4->show();

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
    ui->tableWidget->clear();    //Clear the table
    int col = 0;                 //Initialize row and column to 0
    int row = 0;

    ui->tableWidget->horizontalHeader()->setVisible(true);  //Open up the header to represent the columns

    ui->tableWidget->insertColumn(col);
    ui->tableWidget->setHorizontalHeaderItem(col, new QTableWidgetItem("City Names"));

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    for(int i = 0; i < cityNames.size(); i++)
    {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(cityNames.at(i)));
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

