#include <stdio.h>
#include <limits.h>

#define MAXCITIES 15
#define INF INT_MAX

int cities;
int cost[MAXCITIES][MAXCITIES];
int dp[MAXCITIES][1 << MAXCITIES];

int tsp(int pos, int mask) {
    if (mask == 0)
        return cost[pos][0];

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int minCost = INF;

    for (int next = 0; next < cities; next++) {
        if (mask & (1 << next)) {
            int currCost = cost[pos][next] + tsp(next, mask & ~(1 << next));
            if (currCost < minCost) {
                minCost = currCost;
            }
        }
    }

    return dp[pos][mask] = minCost;
}

int main() {
    scanf("%d", &cities);

    for (int i = 0; i < cities; i++)
        for (int j = 0; j < cities; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < cities; i++)
        for (int mask = 0; mask < (1 << cities); mask++)
            dp[i][mask] = -1;

    int mask = 0;
    for (int i = 1; i < cities; i++)
        mask |= (1 << i);

    int result = tsp(0, mask);

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
