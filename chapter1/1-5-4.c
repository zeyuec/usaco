/*
  ID: zeyuec1
  LANG: C
  TASK: checker
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N, limit = 1, sum = 0;
int ans[40], ansLen=0;

void try(int r, int ld, int rd)
{
    if (r != limit) {
        int pos = limit & ~(r | ld | rd);
        while (pos) {
            int legalPos = pos & -pos;
            pos -= legalPos;
            ans[ansLen++] = legalPos;
            try(r+legalPos, (ld+legalPos)<<1, (rd+legalPos)>>1);
            ansLen--;
        }
    } else {
        if (sum < 3) {
            int i;
            for (i=0; i<ansLen-1; i++) {
                printf("%d ", (int)(log(ans[i])/log(2))+1);
            }
            printf("%d\n", (int)(log(ans[ansLen-1])/log(2)) + 1);
        }
        sum++;
    }
}

int main()
{
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
    scanf("%d", &N);
    limit = (limit << N) - 1;
    try(0, 0, 0);
    printf("%d\n", sum);
    return 0;
}
