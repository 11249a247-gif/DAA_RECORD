#include <stdio.h>

struct Obj {
    int p;   // profit
    int w;   // weight
    float r; // ratio
};

void sortByRatio(struct Obj arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].r < arr[j + 1].r) {
                struct Obj temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Obj arr[], int n, int cap) {
    float profit = 0.0f;

    for (int i = 0; i < n; i++) {
        if (cap >= arr[i].w) {
            profit += arr[i].p;
            cap -= arr[i].w;
        } else {
            profit += arr[i].r * cap;
            break;
        }
    }
    return profit;
}

int main() {
    int cap, n;
    scanf("%d %d", &cap, &n);

    struct Obj arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].w, &arr[i].p);
        arr[i].r = (float)arr[i].p / arr[i].w;
    }

    sortByRatio(arr, n);

    float ans = fractionalKnapsack(arr, n, cap);
    printf("%.2f\n", ans);

    return 0;
}
