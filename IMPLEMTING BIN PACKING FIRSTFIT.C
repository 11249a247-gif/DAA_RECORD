#include <stdio.h>

void FitFirst(int arr[], int n, int cap) {
    int space[n];
    int used = 0;

    for (int i = 0; i < n; i++)
        space[i] = cap;

    for (int i = 0; i < n; i++) {
        int done = 0;
        for (int j = 0; j < used; j++) {
            if (space[j] >= arr[i]) {
                space[j] -= arr[i];
                done = 1;
                break;
            }
        }
        if (!done) {
            space[used] -= arr[i];
            used++;
        }
    }
    printf("Total bins used = %d\n", used);
}

int main() {
    int n, cap;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &cap);

    FitFirst(arr, n, cap);
    return 0;
}
