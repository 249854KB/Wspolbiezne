#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool on = false;

    void push_users_to_table();
    MainWindow(QWidget *parent = nullptr);
    void setLabel(int id, int folder);
    void setProcentage(int folder, int value);
    void setMaxProcValue(int folder, int max);
    ~MainWindow();

private slots:
    void on_stopStartButton_clicked();
    void on_addButton_clicked();



    void on_progressBar_1_valueChanged(int value);

    void on_progressBar_2_valueChanged(int value);

    void on_progressBar_3_valueChanged(int value);

    void on_progressBar_4_valueChanged(int value);

    void on_progressBar_5_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    void setLabel1(int id);
    void setLabel2(int id);
    void setLabel3(int id);
    void setLabel4(int id);
    void setLabel5(int id);

};
#endif // MAINWINDOW_H
