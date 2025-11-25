#include <stdio.h>
#include <string.h>
#include "../include/data.h"

// 데이터 로드
int loadData(Registration arr[], const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: cannot open input file.\n");
        return 0;
    }

    int count = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d/%10[^/]/%3[^/]/%19[^/]/%d/%49[^/]/%19[^\n]",
            &arr[count].tag,
            arr[count].date,
            arr[count].fee,
            arr[count].name,
            &arr[count].age,
            arr[count].org,
            arr[count].job
        );
        count++;
    }

    fclose(fp);
    return count;
}

// 디버그용 출력
void printArray(Registration arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d | %s | %s | %s | %d | %s | %s\n",
            arr[i].tag, arr[i].date, arr[i].fee,
            arr[i].name, arr[i].age, arr[i].org, arr[i].job);
    }
}
