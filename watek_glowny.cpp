
#include <thread>
#include <mutex>
#include <iostream>
#include "watek_glowny.h"

using namespace std;
using namespace std::chrono;
void folder_task(int folder, MainWindow *w){

    while(true)
    {

       // cout << "Hejka mala" << endl;
        for(int i=0; i< 100; i++)
        {
            w->setLabel1(0);
        this_thread::sleep_for(milliseconds(1000));
            w->setLabel1(1);
            this_thread::sleep_for(milliseconds(1000));
        }
    }
}

void GetHighestScoreUser()
{

}

void progress_and_pick(int folder)
{
    while (true)
    {
        //shared_user_mutex.lock();
        GetHighestScoreUser();
       // shared_user_mutex.unlock();


    }
}
