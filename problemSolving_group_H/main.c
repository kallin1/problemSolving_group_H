#include <stdio.h>
#include "P1_sort.h"
#include "list.h"

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

    // P2 : 배열 -> 연결리스트
    printf("\n< P2 : Linked List >\n");

    Node* head = buildListFromArray(arr, n);
    printList(head);         

    freeList(head);

    return 0;
}



    return 0;
}
