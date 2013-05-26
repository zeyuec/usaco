/*
  ID: zeyuec1
  LANG: C
  TASK: lamps
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int plan[10];
int lamps[110], N, C;
int onLamps[110], offLamps[110], onLen = 0, offLen = 0, ansLen = 0;
char ans[20][110];

int isIllegal()
{
    int i;
    for (i=0; i<onLen; i++) {
        if (lamps[onLamps[i]] == 0) {
            return 0;
        }
    }
    for (i=0; i<offLen; i++) {
        if (lamps[offLamps[i]] == 1) {
            return 0;
        }
    }
    return 1;
}

void trigger(int button)
{
    int i;
    switch (button) {
    case 1:
        for (i=1; i<=N; i++) {
            lamps[i] = 1-lamps[i];
        }
        break;
    case 2:
        for (i=0; 2*i+1<=N; i++) {
            lamps[2*i+1] = 1-lamps[2*i+1];
        }
        break;
    case 3:
        for (i=1; 2*i<=N; i++) {
            lamps[2*i] = 1-lamps[2*i];
        }
        break;
    case 4:
        for (i=0; 3*i+1<=N; i++) {
            lamps[3*i+1] = 1-lamps[3*i+1];
        }
        break;
    }
}

void try(int k, int n, int count) {
    if (k > n) {
        int i;
        for (i=1; i<=N; i++) lamps[i] = 1;

        if (count <= C) {
            for (i=1; i<=n; i++) {
                if (plan[i] == 1) {
                    trigger(i);
                }
            }

            if (isIllegal() == 1) {
                for (i=1; i<=N; i++) {
                    ans[ansLen][i-1] = '0'+lamps[i];
                }
                ans[ansLen][N] = '\0';
                ansLen++;
            }
        }
    } else {
        plan[k] = 0;
        try(k+1, n, count);
        plan[k] = 1;
        try(k+1, n, count+1);
    }
}


int cmp(const void *p1, const void *p2)
{
    return strcmp((char*) p1, (char*)p2);
}

int main()
{
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    
    int t;
    scanf("%d %d", &N, &C);
    scanf("%d", &t);
    while (t != -1) {
        onLamps[onLen++] = t;
        scanf("%d", &t);
    }
    scanf("%d", &t);
    while (t != -1) {
        offLamps[offLen++] = t;
        scanf("%d", &t);
    }
    
    /* reduce C */
    while (C > 4) {
        C-=2;
    }

    /* try */
    try(1, 4, 0);
    if (ansLen == 0) {
        printf("IMPOSSIBLE\n");
    } else {
        qsort(ans, ansLen, sizeof(ans[0]), cmp);
        int i;
        for (i=0; i<ansLen; i++) {
            if (i == 0 || strcmp(ans[i], ans[i-1]) != 0) {
                printf("%s\n", ans[i]);
            }
        }
    }
    
    return 0;
}
