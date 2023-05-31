#include "global.h"
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
