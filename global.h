#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <random>

using namespace std;

typedef struct {
    int filesizes[5];
    struct tm  jointime;
    bool active;
}User;


extern User users[100];
extern int id_count;
extern int active_count;
extern struct tm  begin_time;

int random_files_number();

int random_file_size();

void filesgenerator(int *filesizes);

void files_to_string(char* string, int id);

float get_time_diff(int id);

int get_file_from_user(int id);

int GetHighestScoreUser();

struct tm timestampgenerator();

#endif // GLOBAL_H
