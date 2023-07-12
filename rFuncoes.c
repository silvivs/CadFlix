/*
Refactor Funcoes.c to rFuncoes.c to implement linked lists
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rHead.h"

struct info {
    char director[101];
    char genre[51];
    int year;
    int age;
};

struct movie {
    char name[101];
    float price;
    Info* information;
};

struct list {
    Movie* first;
    Movie* last;
    int size;
};

/*
to do: 
implement the functions according to the prototypes in rHead.h
*/


