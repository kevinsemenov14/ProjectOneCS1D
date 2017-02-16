#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_normalTrip_clicked();

    void on_CustomTrip1_clicked();

    void on_CustomTrip2_clicked();

    void on_startTrip_clicked();

    void FillTripTable();

    void FillBerlinTable();

    void on_LogOut_Button_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    dbManager db;
    QVector<QString> cityNames;
    QVector<QString> berlDists;

};

#endif // MAINWINDOW_H
