#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "P2_list.h"   

Node* createNode(Registration r)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    newNode->data = r;   
    newNode->next = NULL;
    return newNode;
}

Node* buildListFromArray(Registration arr[], int n)
{
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = createNode(arr[i]);

        if (head == NULL) {   
            head = newNode;
            tail = newNode;
        }
        else {             
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(Node* head)
{
    Node* cur = head;

    while (cur != NULL) {
        printf("%d | %s | %s | %s | %d | %s | %s\n",
            cur->data.tag,
            cur->data.date,
            cur->data.fee,
            cur->data.name,
            cur->data.age,
            cur->data.org,
            cur->data.job
        );

        cur = cur->next;
    }
}

void freeList(Node* head)
{
    Node* cur = head;
    while (cur != NULL) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
