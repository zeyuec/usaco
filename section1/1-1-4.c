/*
ID: zeyuec1
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int necklace[2000];

int isEqual(int next, int* now)
{
    if (*now == 0) {
        *now = next;
        return 1;
    }
    if (next == *now || next == 0) {
        return 1;
    }
    return 0;
}

int cal()
{
    int st = N, end = N+N-1, max = 1;
    int p, i, j;
    for (p = st; p<=end; p++) {
        i = p;
        j = p+1;
        int color = necklace[p];
        while ((isEqual(necklace[i-1], &color) == 1 || necklace[i-1] == 0) &&
               (p-(i-1)+1) <= N) {
            i--;
        }
        if ((p-i+1) == N) {
            return N; 
        }

        color = necklace[p+1];
        while ((isEqual(necklace[j+1], &color) == 1 || necklace[j+1] == 0) &&
               (j+1-i+1) <= N) {
            j++;
        }
        if (j-i+1 > max) {
            max = j-i+1;
        }
    }
    return max;
}

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int i, flag;
    char bread;
    scanf("%d\n", &N);
    for (i=0; i<N; i++) {
        scanf("%c", &bread);
        if (bread == 'w') {
            flag = 0;
        }
        if (bread == 'r') {
            flag = 1;
        }
        if (bread == 'b') {
            flag = 2;
        }
        necklace[i] = flag;
        necklace[i+N] = flag;
        necklace[i+N+N] = flag;
    }

    int ret = cal();
    printf("%d\n", ret);
    
    return 0;
}
