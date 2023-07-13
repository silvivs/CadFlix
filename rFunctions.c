/*
Refactor Funcoes.c to rFunctions.c to implement linked lists
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rHead.h"

struct info {
    char* director;
    char* genre;
    int year;
    int age;
};

struct movie { //this is a node
    char* name;
    float price;
    Info* information;
    Movie* next;
    Movie* prev;
};

struct list {
    Movie* first;
    Movie* last;
    int size;
};

int isEmpty(List* head) {
    return head->size == 0;
}

void verify_mallocError_for_Char(char* string) {
    if(string == NULL) {
        printf("Memory allocation failure\n");
        exit(1);
    }
}

List* createList(void) {
    List* list = malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Movie* createMovie(char* name, float price, char* director, char* genre, int year, int age) {
    Movie* newMovie = (Movie*)malloc(sizeof(Movie));
    
    if(newMovie == NULL) {
        printf("Memory allocation failure\n");
        exit(1);
    }

    newMovie->name = (char*)malloc(strlen(name + 1));
    verify_mallocError_for_Char(newMovie->name);

    newMovie->information->director = (char*)malloc(strlen(director + 1));
    verify_mallocError_for_Char(newMovie->information->director);

    newMovie->information->genre = (char*)malloc(strlen(genre + 1));
    verify_mallocError_for_Char(newMovie->information->genre);

    
    newMovie->price = price;
    strcpy(newMovie->name, name);

    newMovie->information->age = age;
    newMovie->information->year = year;
    strcpy(newMovie->information->director, director);
    strcpy(newMovie->information->genre, genre);

    newMovie->next = NULL;
    newMovie->prev = NULL;

    return newMovie;
}

void delete(List* head, const char* name) {
    Movie* previous = NULL;
    Movie* current = head->first;

    while(current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if(current != NULL) {
        if(previous == NULL) {
            head->first = current->next;
        } else {
            previous->next = current->next;
        }

        free(current);
    }
    
}

void insertAtBeginning(List* head);

//to do :: refactor 

