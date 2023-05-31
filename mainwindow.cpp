#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include <string>
#include "global.h"

User users[100];
int id_count;
struct tm  begin_time;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabelaTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tabelaTable->setColumnWidth(0,90);
    ui->tabelaTable->setColumnWidth(1,400);
    ui->tabelaTable->horizontalHeader()->setStretchLastSection(true);
    //ui->tabelaTable->setColumnWidth(2,160);
    ui->tabelaTable->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_stopStartButton_clicked()
{
    //qDebug() << "Callback przycisku stopStart";
    if(this->on == false)
    {
        on = true;
        ui->stopStartButton->setText("Stop");
    }
    else
    {
        on = false;
        ui->stopStartButton->setText("Start");
    }


}


void MainWindow::on_addButton_clicked()
{
    for(int i = 0; i<5; i++)
    {
        filesgenerator(users[id_count].filesizes);
        users[id_count].active = true;
        users[id_count].jointime = timestampgenerator();
        id_count++;
    }
    push_users_to_table();
    // Implement adding new users
}

void MainWindow::setLabel1(int id){
    if(id ==0)
        ui->label_1->setText("wolny");
    else
        ui->label_1->setText(QString::fromStdString("ID: "+std::to_string(id)));

}

void MainWindow::setLabel2(int id){

}

void MainWindow::setLabel3(int id){

}

void MainWindow::setLabel4(int id){

}

void MainWindow::setLabel5(int id){

}

void MainWindow::push_users_to_table(void){
    ui->tabelaTable->setRowCount(15);
    QTableWidgetItem *item;
    char temp[100];
    int rows = 0;

    for (int i = 0; i < 100; i++) {

        if(users[i].active == true)
        {
            item = new QTableWidgetItem;
            item->setTextAlignment(Qt::AlignCenter);
            sprintf(temp,"%d",i);
            item->setText(QString::fromStdString(temp));
            ui->tabelaTable->setItem(rows,0,item);

            item = new QTableWidgetItem;
            files_to_string(temp, i);
            item->setText(QString::fromStdString(temp));
            ui->tabelaTable->setItem(rows,1,item);

            item = new QTableWidgetItem;
            item->setTextAlignment(Qt::AlignCenter);
            sprintf(temp,"%d:%d:%d",users[i].jointime.tm_hour, users[i].jointime.tm_min, users[i].jointime.tm_sec);
            item->setText(QString::fromStdString(temp));
            ui->tabelaTable->setItem(rows,2,item);
            rows++;
        }
    }

}


