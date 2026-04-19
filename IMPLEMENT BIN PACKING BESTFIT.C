#include <stdio.h>

void bestFit(int arr[], int n, int cap) {
    int bins[n];
    int used = 0;

    for (int i = 0; i < n; i++)
        bins[i] = cap;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        int minSpace = cap + 1;

        for (int j = 0; j < used; j++) {
            if (bins[j] >= arr[i] && (bins[j] - arr[i]) < minSpace) {
                bestIdx = j;
                minSpace = bins[j] - arr[i];
            }
        }

        if (bestIdx != -1) {
            bins[bestIdx] -= arr[i];
        } else {
            bins[used] -= arr[i];
            used++;
        }
    }

    printf("Total bins used = %d\n", used);
}

int main() {
    int n, cap;
    scanf("%d", &n);
    int arr[n];
    scanf("%d", &cap);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > cap) {
            i--; // re-enter if item exceeds capacity
        }
    }

    bestFit(arr, n, cap);
    return 0;
}
