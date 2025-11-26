// Author: 202534724 권지우
// P2: build linked list from sorted array

#ifndef P2_LIST_H
#define P2_LIST_H

#include "P1_sort.h"   

typedef struct Node {
    Registration data;    
    struct Node* next;
} Node;

// 새 노드 하나 만들기
Node* createNode(Registration r);

// 정렬된 배열 → 연결 리스트 만들기
Node* buildListFromArray(Registration arr[], int n);

// 리스트 전체 출력 (P2 결과용)
void printList(Node* head);

// 메모리 해제
void freeList(Node* head);

#endif

