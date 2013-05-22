/*
  ID: zeyuec1
  LANG: C
  TASK: holstein
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
int V, G, req[MAX], feed[MAX][MAX], plan[MAX];
int minCost = MAX, minPlan[MAX];

int tryFit()
{
    int i, j, feedCount[MAX];
    memset(feedCount, 0, sizeof(feedCount));
    for (i=0; i<V; i++) {
        if (plan[i] == 1) {
            for (j=0; j<G; j++) {
                feedCount[j] += feed[V-i-1][j];
            }
        }
    }
    for (j=0; j<G; j++) {
        if (feedCount[j] < req[j]) {
            return 0;
        }
    }
    return 1;
}

void try(int k, int count)
{
    if (k == V) {
        int i, fit = tryFit();
        if (fit == 1 && count < minCost) {
            minCost = count;
            for (i=0; i<V; i++) {
                minPlan[i] = plan[i];
            }
        }
    } else {
        plan[k] = 0;
        try(k+1, count);
        plan[k] = 1;
        try(k+1, count+1);
    }
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    int i, j;
    scanf("%d", &G);
    for (i=0; i<G; i++) {
        scanf("%d", &req[i]);
    }
    scanf("%d", &V);
    for (i=0; i<V; i++) {
        for (j=0; j<G; j++) {
            scanf("%d", &feed[i][j]);
        }
    }
    try(0, 0);
    printf("%d", minCost);
    for (i=V-1; i>=0; i--) {
        if (minPlan[i] == 1) {
            printf(" %d", V-i);
        }
    }
    printf("\n");
    return 0;
}
