#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swapValues(&arr[i], &arr[j]);
        }
    }
    swapValues(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortArray(int arr[], int low, int high) {
    if (low < high) {
        int randomIndex = low + rand() % (high - low + 1);
        swapValues(&arr[randomIndex], &arr[high]);
        int pi = partitionArray(arr, low, high);
        quickSortArray(arr, low, pi - 1);
        quickSortArray(arr, pi + 1, high);
    }
}

int main() {
    int n;
    srand(time(NULL));
    scanf("%d", &n);
    if (n <= 0) return 1;

    int numbers[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    quickSortArray(numbers, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}
