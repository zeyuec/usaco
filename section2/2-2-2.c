/*
  ID: zeyuec1
  LANG: C
  TASK: subset
*/

#include <stdio.h>
#include <stdlib.h>

int N;
long long f[45][1000];

long long cal()
{
    int sum = (1+N)*N/4;
    int i, j;
    f[1][0] = 1;
    f[1][1] = 1;
    for (i=2; i<=N; i++) {
        for (j=0; j<=sum; j++) {
            if (j-i>=0) {
                f[i][j] = f[i-1][j] + f[i-1][j-i];
            } else {
                f[i][j] = f[i-1][j];
            }
        }
    }
    return f[N][sum]/2;
}

int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    scanf("%d", &N);
    if ((1+N)*N/2 %2 == 1) {
        printf("0\n");
    } else {
        printf("%lld\n", cal());
    }
    return 0;
}

