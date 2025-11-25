// Author: 202234861 ±Ë¥Ÿ¿Œ
// load txt file, P1(sort array, store P1.txt)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int tag;
    char date[11];
    char fee[4];
    char name[20];
    int age;
    char org[50];
    char job[20];
} Registration;

// load registration
int loadData(Registration arr[], const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: cannot open %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%d/%10[^/]/%3[^/]/%19[^/]/%d/%49[^/]/%19[^\n]",
        &arr[count].tag,
        arr[count].date,
        arr[count].fee,
        arr[count].name,
        &arr[count].age,
        arr[count].org,
        arr[count].job
    ) == 7)
    {
        count++;
    }

    fclose(fp);
    return count;
}

// print array(test)
void printArray(Registration arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d | %s | %s | %s | %d | %s | %s\n",
            arr[i].tag,
            arr[i].date,
            arr[i].fee,
            arr[i].name,
            arr[i].age,
            arr[i].org,
            arr[i].job
        );
    }
}

// P1: Selection Sort
void selectionSort(Registration arr[], int n)
{
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j].age < arr[minIndex].age) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Registration temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// store as file
void writeSortedToFile(const char* filename, Registration arr[], int n)
{
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: cannot write to %s\n", filename);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d/%s/%s/%s/%d/%s/%s\n",
            arr[i].tag,
            arr[i].date,
            arr[i].fee,
            arr[i].name,
            arr[i].age,
            arr[i].org,
            arr[i].job
        );
    }

    fclose(fp);
    printf("Sorted data saved to %s\n", filename);
}
