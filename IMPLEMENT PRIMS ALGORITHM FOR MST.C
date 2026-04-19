#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define NODES 5

int getMinKey(int key[], bool used[]) {
    int minVal = INT_MAX, idx = -1;

    for (int i = 0; i < NODES; i++) {
        if (!used[i] && key[i] < minVal) {
            minVal = key[i];
            idx = i;
        }
    }
    return idx;
}

void printMST(int parent[], int graph[NODES][NODES]) {
    for (int i = 1; i < NODES; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
    }
}

void prims(int graph[NODES][NODES]) {
    int parent[NODES];
    int key[NODES];
    bool used[NODES];

    for (int i = 0; i < NODES; i++) {
        key[i] = INT_MAX;
        used[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < NODES - 1; count++) {
        int u = getMinKey(key, used);
        used[u] = true;

        for (int v = 0; v < NODES; v++) {
            if (graph[u][v] && !used[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[NODES][NODES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prims(graph);

    return 0;
}
