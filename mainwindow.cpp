#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include <string>
#include "global.h"

User users[100];
int id_count = 0;
int active_count = 0;
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
    on=false;
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
        active_count++;
    }
    push_users_to_table();
    // Implement adding new users
}

void MainWindow::setLabel1(int id){
    if(id ==100)
        ui->label_1->setText("wolny");
    else
        ui->label_1->setText(QString::fromStdString("ID: "+std::to_string(id)));

}

void MainWindow::setLabel2(int id){
    if(id ==100)
        ui->label_2->setText("wolny");
    else
        ui->label_2->setText(QString::fromStdString("ID: "+std::to_string(id)));
}

void MainWindow::setLabel3(int id){
    if(id ==100)
        ui->label_3->setText("wolny");
    else
        ui->label_3->setText(QString::fromStdString("ID: "+std::to_string(id)));
}

void MainWindow::setLabel4(int id){
    if(id ==100)
        ui->label_4->setText("wolny");
    else
        ui->label_4->setText(QString::fromStdString("ID: "+std::to_string(id)));
}

void MainWindow::setLabel5(int id){
    if(id ==100)
        ui->label_5->setText("wolny");
    else
        ui->label_5->setText(QString::fromStdString("ID: "+std::to_string(id)));
}

void MainWindow::setLabel(int id, int folder){
    switch (folder) {
    case 0:
        setLabel1(id);
        break;
    case 1:
        setLabel2(id);
        break;
    case 2:
        setLabel3(id);
        break;
    case 3:
        setLabel4(id);
        break;
    case 4:
        setLabel5(id);
        break;
    default:
        break;
    }
}

void MainWindow::setProcentage(int folder, int value)
{
    switch (folder) {

    case 0:
        if (ui->progressBar_1->value()!=value)
            ui->progressBar_1->valueChanged(value);
        break;
    case 1:
        if (ui->progressBar_2->value()!=value)
            ui->progressBar_2->valueChanged(value);
        break;
    case 2:
        if (ui->progressBar_3->value()!=value)
            ui->progressBar_3->valueChanged(value);
        break;
    case 3:
        if (ui->progressBar_4->value()!=value)
            ui->progressBar_4->valueChanged(value);
        break;

    case 4:
        if (ui->progressBar_5->value()!=value)
            ui->progressBar_5->valueChanged(value);
        break;
    default:
        break;
    }
}

void MainWindow::setMaxProcValue(int folder, int max)
{
    switch (folder) {
    case 0:
        ui->progressBar_1->setRange(0,max);
        break;
    case 1:
        ui->progressBar_2->setRange(0,max);
        break;
    case 2:
        ui->progressBar_3->setRange(0,max);
        break;
    case 3:
        ui->progressBar_4->setRange(0,max);
        break;
    case 4:
        ui->progressBar_5->setRange(0,max);
        break;
    default:
        break;
    }
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


void MainWindow::on_progressBar_1_valueChanged(int value)
{
    ui->progressBar_1->setValue(value);

}


void MainWindow::on_progressBar_2_valueChanged(int value)
{
    ui->progressBar_2->setValue(value);

}


void MainWindow::on_progressBar_3_valueChanged(int value)
{
    ui->progressBar_3->setValue(value);

}


void MainWindow::on_progressBar_4_valueChanged(int value)
{
    ui->progressBar_4->setValue(value);

}


void MainWindow::on_progressBar_5_valueChanged(int value)
{
    ui->progressBar_5->setValue(value);

}

