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
    void setLabel1(int id);
    void setLabel2(int id);
    void setLabel3(int id);
    void setLabel4(int id);
    void setLabel5(int id);
    void push_users_to_table();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_stopStartButton_clicked();
    void on_addButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
