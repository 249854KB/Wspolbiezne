
#include <thread>
#include <mutex>
#include <iostream>
#include "watek_glowny.h"
#include "global.h"
#include <mutex>
using namespace std;
using namespace std::chrono;
mutex shared_user_mutex;
void folder_task(int folder, MainWindow *w){

    int timer = 0;
    while(true)
    {
        while(w->on ==false);   //Waiting if blocked
        // cout << "Hejka mala" << endl;
        shared_user_mutex.lock();
        int temp = GetHighestScoreUser();
        timer = get_file_from_user(temp);
        shared_user_mutex.unlock();
        w->setLabel(temp,folder);
        if(temp!=100){

            w->setMaxProcValue(folder,timer);
            for (int i = 1; i < timer; i+=100) {
                this_thread::sleep_for(milliseconds(100));
                w->setProcentage(folder,i);

            }
        }

    }
}



