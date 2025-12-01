// Author: 202234861 김다인

#ifndef DATA_SORT_H
#define DATA_SORT_H

#define MAX_RECORDS 100

typedef struct {
    int tag;
    char date[11];
    char fee[4];
    char name[20];
    int age;
    char org[50];
    char job[20];
} Registration;

// data load
int loadData(Registration arr[], const char* filename);

// print array(test)
void printArray(Registration arr[], int n);

// P1: Selection Sort
void selectionSort(Registration arr[], int n);

// store as file
void writeSortedToFile(const char* filename, Registration arr[], int n);

#endif
