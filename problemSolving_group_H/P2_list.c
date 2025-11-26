// Author: 202534724 권지우
// P2: Build linked list from sorted array

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "P2_list.h"   

// 새 노드를 동적 할당하여 생성하는 함수
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

// 정렬된 배열 데이터를 순서대로 연결 리스트로 변환
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

// 연결 리스트 전체를 출력
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

// 연결 리스트의 모든 노드를 해제
void freeList(Node* head)
{
    Node* cur = head;
    while (cur != NULL) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}

