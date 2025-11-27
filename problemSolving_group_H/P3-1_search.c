#include <stdio.h>
#include <string.h>
#include "P3-1_search.h"

void searchArrayFeePaid(Registration arr[], int n)
{
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].fee, "yes") == 0) {
            printf("%d | %s | %s | %s | %d | %s | %s\n",
                arr[i].tag, arr[i].date, arr[i].fee,
                arr[i].name, arr[i].age, arr[i].org, arr[i].job);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No matching records found.\n");
    }
}