// Author: 202534029 변예서

// P5_update.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "P5_update.h"

static int isChoiCanceled(const Registration* r)
{
    if (r == NULL) return 0;

    // 이름에 "Choi" 포함?
    if (strstr(r->name, "Choi") == NULL) return 0;

    // fee 가 "no" (미납 / 취소) 인지?
    if (strcmp(r->fee, "no") != 0) return 0;

    return 1;
}

// [P5-1] 배열에서 비우기
void removeChoiCanceled_Array(Registration arr[], int n)
{
    int i;

    printf("\n[P5-1] Remove Choi's canceled registration in ARRAY\n");

    for (i = 0; i < n; i++) {
        if (isChoiCanceled(&arr[i])) {
            printf("  -> Remove index %d : %s, fee=%s\n",
                   i, arr[i].name, arr[i].fee);

            // “empty” 로 만드는 방법 : 문자열을 전부 빈 문자열로
            arr[i].name[0]       = '\0';
            arr[i].org[0] = '\0';
            arr[i].fee[0]        = '\0';
        }
    }
}

// [P5-2] 연결리스트에서 노드 삭제
void removeChoiCanceled_List(Node** head)
{
    Node* cur  = *head;
    Node* prev = NULL;

    printf("\n[P5-2] Remove Choi's canceled registration in LINKED LIST\n");

    while (cur != NULL) {
        if (isChoiCanceled(&cur->data)) {
            Node* temp = cur;

            printf("  -> Remove node : %s, fee=%s\n",
                   cur->data.name, cur->data.fee);

            if (prev == NULL) {
                *head = cur->next;
                cur   = cur->next;
            } else {
                prev->next = cur->next;
                cur        = cur->next;
            }

            free(temp);
        }
        else {
            prev = cur;
            cur  = cur->next;
        }
    }
}
