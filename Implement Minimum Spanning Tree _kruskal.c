#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5
#define E 6

struct Edge {
    int src, dest, weight;
};

int parent[V];

int findSet(int i) {
    if (parent[i] == i)
        return i;
    return findSet(parent[i]);
}

void mergeSets(int u, int v) {
    int rootU = findSet(u);
    int rootV = findSet(v);
    parent[rootU] = rootV;
}

int edgeCompare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void runKruskal(struct Edge edges[]) {
    qsort(edges, E, sizeof(edges[0]), edgeCompare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0;
    int total = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (findSet(u) != findSet(v)) {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            total += edges[i].weight;
            mergeSets(u, v);
            count++;
        }
    }

    printf("Total Cost = %d\n", total);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    runKruskal(edges);
    return 0;
}
