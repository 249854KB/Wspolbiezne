#include "global.h"
#include <algorithm>
#include <cstring>

int random_files_number()
{
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 5); // define the range

    return distr(gen);
}

int random_file_size()
{
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 100000000); // define the range

    return distr(gen);
}

void filesgenerator(int *filesizes)
{
    filesizes[0]= 0;
    filesizes[1]= 0;
    filesizes[2]= 0;
    filesizes[3]= 0;
    filesizes[4]= 0;
    for (int i = 0; i < random_files_number(); i++) {
        filesizes[i] =random_file_size();
    }
    sort(filesizes,filesizes+5,greater<int>());

}

struct tm timestampgenerator()
{
    struct tm new_time;
    new_time = begin_time;
    int new_min = new_time.tm_min +5 * id_count;
    while(new_min > 60)
    {
        new_min = new_min - 60;
        new_time.tm_hour = new_time.tm_hour +1;
    }
    new_time.tm_min = new_min;
    return new_time;
}


void files_to_string(char* string, int id)
{
    char temp1[15];
    sprintf(string,"%d", users[id].filesizes[0]);
    for (int i = 1; i < 5; i++) {
        if(users[id].filesizes[i]!=0)
        {
            sprintf(temp1,", %d", users[id].filesizes[i]);
            string = strcat(string,temp1);
        }
    }
}


float get_time_diff(int id)
{
    float time_diff;
    time_t     now = time(0);
    struct tm  tstruct;
    tstruct = *localtime(&now);
    time_diff = float(tstruct.tm_hour - users[id].jointime.tm_hour) + (float)(tstruct.tm_min - users[id].jointime.tm_min)/60 + (float)(tstruct.tm_sec - users[id].jointime.tm_sec)/ 3600;
    return time_diff;
}

int get_file_from_user(int id)
{
    if(id!=100)
    {
        int size_to_map;
        for(int files =0; files<5; files++)
        {
            if(users[id].filesizes[files] == 0)
            {
                users[id].filesizes[files-1] = 0;
                if(files == 1)
                {
                    users[id].active =false;
                    active_count --;
                }
            }
            else
            {
                size_to_map = users[id].filesizes[files];
            }
        }
        float x = (size_to_map - 1) / (100000000 - 1);
        return (int)(1000 + (10000 - 1000) * x);
    }
    return 0;
}

int GetHighestScoreUser()
{
    int id = 100;
    double w =0;
    for (int i = 0; i < 100; i++) {
        if(users[i].active == true)
        {
            int filesize = 0;
            for (int file = 0; file < 5; file++) {
                if(users[i].filesizes[file]!=0)
                {
                    filesize = users[i].filesizes[file]!=0; //Getting lowest from array
                }
            }
            // W = t^(1/k) + k/r
            double tempw = pow(get_time_diff(i),1/active_count) + active_count/filesize;
            if (tempw > w)
            {
                w = tempw;
                id = i;
            }

        }

    }
    return id;
}
