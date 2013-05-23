/*
  ID: zeyuec1
  LANG: C
  TASK: frac1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ANS {
    int x, y;
    double n;
} ANS;

int N, ansLen = 0;
int hash[200][200];
ANS ans[40000];

int gcd(int x, int y)
{
    if (y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

int cmp(const void *a, const void *b)
{
    ANS *fa = (ANS*) a;
    ANS *fb = (ANS*) b;
    return fa->n > fb->n ? 1 : -1;
}

void cal()
{
    int a, b;
    for (a=1; a<=N-1; a++) {
        for (b=a+1; b<=N; b++) {
            int g = gcd(b, a);
            if (hash[a/g][b/g] == 0) {
                ans[ansLen].x = a/g;
                ans[ansLen].y = b/g;
                ans[ansLen].n = (a+0.0)/b;
                ansLen++;
                hash[a/g][b/g] = 1;
            }
        }
    }
    qsort(ans, ansLen, sizeof(ans[0]), cmp);
    int i;
    printf("0/1\n");
    for (i=0; i<ansLen; i++) {
        printf("%d/%d\n", ans[i].x, ans[i].y);
    }
    printf("1/1\n");
}

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    scanf("%d", &N);
    cal();
    return 0;
}
