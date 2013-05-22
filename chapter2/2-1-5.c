/*
  ID: zeyuec1
  LANG: C
  TASK: hamming
*/

#include <stdio.h>
#include <stdlib.h>

int N, B, D;
int ans[300], ansCount = 0;

void out(int k)
{
    if (ansCount == 0) {
        printf("%d", k);
    } else {
        if (ansCount % 10 == 0) {
            printf("\n%d", k);
        } else {
            printf(" %d", k);
        }
    }
    ans[ansCount++] = k;
}

int times(int k)
{
    int count = 0;
    while (k > 0) {
        count = (k % 2 == 1) ? count+1:count;
        k = k/2;
    }
    return count;
}

int checkBefore(int k)
{
    int i;
    for (i=0; i<ansCount; i++) {
        if (times(k^ans[i]) < D) {
            return 0;
        }
    }
    return 1;
}

void cal()
{
    int i;
    out(0);
    for (i=1; i<(1<<B); i++) {
        if (ansCount < N) {
            if (checkBefore(i)) {
                out(i);
            }
        } else {
            return;
        }
    }
}

int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    scanf("%d %d %d", &N, &B, &D);
    cal();
    printf("\n");
    return 0;
}
