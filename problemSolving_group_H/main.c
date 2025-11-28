#include <stdio.h>
#include "P1_sort.h"
#include "P2_list.h"
#include "P3-1_search.h"
#include "P3-2_search.h"
#include "P4_search.h"

int main() {

    Registration arr[MAX_RECORDS];
    int n;

    // setup: data load
    n = loadData(arr, "registration_data.txt");
    
    // P1: Selection Sort
    selectionSort(arr, n);

    printf("\n< P1: Selection Sort in Array >\n");
    printArray(arr, n);
    writeSortedToFile("P1.txt", arr, n);

    // P2: Array -> Linked List
    printf("\n< P2: Linked List >\n");

    Node* head = buildListFromArray(arr, n);
    printList(head);         

    // P3-1: Search fee-paid ("yes") in array
    printf("\n< P3-1: Search fee \"yes\" in Array >\n");
    searchArrayFeePaid(arr, n);

    // P3-2: Search fee-paid ("yes") in linked list
    printf("\n< P3-2: Search fee \"yes\" in Linked List >\n");
    searchListFeePaid(head);

    // P4-1: Search "Gachon University" in Array
    printf("\n< P4-1: Search \"Gachon University\" in Array >\n");
    Search_Gachon_Array(arr, n);

    // P4-2: Search "Gachon University" in Linked List
    printf("\n< P4-2: Search \"Gachon University\" in Linked List >\n");
    Search_Gachon_List(head);

    






    freeList(head);
    return 0;
}
