#include <stdio.h>
#include "P1_sort.h"

int main() {

    Registration arr[MAX_RECORDS];
    int n;

    // setup : data load
    n = loadData(arr, "../registration_data.txt");
    
    // P1: Selection Sort
    selectionSort(arr, n);

    printf("\n< P1 >\n");
    printArray(arr, n);
    writeSortedToFile("P1.txt", arr, n);

    // P2 : 



    return 0;
}
