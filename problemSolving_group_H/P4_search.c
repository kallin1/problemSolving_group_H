// Author: 2024***** 김학현

#include <stdio.h>
#include <string.h>
#include "P4_search.h"

void Print_Person_Info(Registration p) {
    printf("%d | %s | %s | %s | %d | %s | %s\n", 
           p.tag, p.date, p.fee, p.name, p.age, p.org, p.job); 
}

// ---------------------------------------------------------
// Mark P4-1: Search for "Gachon University" in the Array
// ---------------------------------------------------------
void Search_Gachon_Array(Registration data[], int count) {
    int found_count = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(data[i].org, "Gachon University") == 0) {
            Print_Person_Info(data[i]);
            found_count++;
        }
    }
    printf("P4-1 Total Found: %d\n", found_count);
}

// ---------------------------------------------------------
// Mark P4-2: Search for "Gachon University" in the Linked List
// ---------------------------------------------------------
void Search_Gachon_List(Node* head) {

    Node* current = head;
    int found_count = 0;

    while (current != NULL) {
        if (strcmp(current->data.org, "Gachon University") == 0) {
            Print_Person_Info(current->data);
            found_count++;
        }
        current = current->next; 
    }
    printf("P4-2 Total Found: %d\n", found_count);
}
