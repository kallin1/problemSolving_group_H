// Author: 202234950 황성욱

#include <stdio.h>
#include <string.h>
#include "P3-2_search.h"

void searchListFeePaid(Node* head)
{
    Node* cur = head;
    int found = 0;

    while (cur != NULL) {
        if (strcmp(cur->data.fee, "yes") == 0) {
            printf("%d | %s | %s | %s | %d | %s | %s\n",
                cur->data.tag, cur->data.date, cur->data.fee,
                cur->data.name, cur->data.age, cur->data.org, cur->data.job);
            found = 1;
        }
        cur = cur->next;
    }

    if (found == 0) {
        printf("No matching records found.\n");
    }

}
