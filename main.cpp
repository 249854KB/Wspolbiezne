#include "mainwindow.h"

#include <QApplication>


#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include "watek_glowny.h"
#include <ctime>
#include "global.h"

/*
    Założenia:
    - Najmniejszy rozmiar pliku to 1B (Zakres losowania)
    - Maksymalny rozmiar to 100 GB
    - Czas przekazywania pliku to wylosowany rozmiar zmapowany na długości czasu od 2s do 10s
    - Dodawanie pod przcysiekiem
    - Dodawanie klienta z losową liczbą plików od 1 do 5
    Wzór na współczynnik:
    W = t^(1/k) + k/r, gdzie
    t - czas czekania w kolejce
    r - rozmiar najmniejszego pliku
    k - liczba osób czekających w kolejce
    To Do:
    - Zmienić tak, aby rozmiary plików były po przecinku

*/

using namespace std;
using namespace std::chrono;




int main(int argc, char *argv[])
{
    int folder = 0;
    // Calling thread with the function
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    thread folder1(folder_task,folder++,&w);
    thread folder2(folder_task,folder++,&w);
    thread folder3(folder_task,folder++,&w);
    thread folder4(folder_task,folder++,&w);
    thread folder5(folder_task,folder++,&w);
     cout << clock() << endl; // Ms from program start

    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    begin_time = tstruct;
    begin_time.tm_hour = begin_time.tm_hour - 1;
    cout << tstruct.tm_hour << ":" << tstruct.tm_min << ":" << tstruct.tm_sec << endl;
    return a.exec();
}
