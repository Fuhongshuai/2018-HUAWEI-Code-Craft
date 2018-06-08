#ifndef __ROUTE_H__
#define __ROUTE_H__

#include <cstdio>
#include <cstdlib>
#include<cmath>
#include <string>
#include "lib/lib_io.h"
using namespace std;
struct Vm{
    int cpu, mem;
};
struct Ecs{
    std::string name;
    int cpu, mem;
};
void predict_server(char * info[MAX_INFO_NUM], char * data[MAX_DATA_NUM], int data_num, char * filename);

#endif
