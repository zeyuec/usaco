/*
ID: zeyuec1
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct FARMER{
    int st, end;
} FARMER;

int N;
FARMER farmer[6000];

int cmp(const void *a, const void *b) {
    FARMER *fa = (FARMER *) a;
    FARMER *fb = (FARMER *) b;
    if (fa->st == fb->st) {
        return fa->end - fb->end;
    } else {
        return fa->st - fb->st;
    }
}

void cal() {
    int i = 0, lc = 0, li = 0, maxEnd = 0;
    int lcStart = farmer[i].st;
    while (i < N) {
        if (i > 0) {
            if (farmer[i].st > maxEnd) {
                if (farmer[i].st - maxEnd > li) {
                    li = farmer[i].st - maxEnd;
                }
                lcStart = farmer[i].st;
            } 
        }
        int j = i;
        while (j+1<N && farmer[j+1].st == farmer[i].st) {
            j++;
        }
        if (farmer[j].end > maxEnd) {
            maxEnd = farmer[j].end;
        }
        if (farmer[j].end - lcStart> lc) {
            lc = farmer[j].end - lcStart;
        }
        i = j+1;
    }
    printf("%d %d\n", lc, li);
}

int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int i;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d %d", &farmer[i].st, &farmer[i].end);
    }
    qsort(farmer, N, sizeof(farmer[0]), cmp);

    cal();
    return 0;
}
