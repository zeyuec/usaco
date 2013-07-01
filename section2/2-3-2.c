/*
  ID: zeyuec1
  LANG: C
  TASK: nocows
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, K;
int f[210][110];

int cal()
{
    int i, j, k;
    for (j=1; j<=K; j++) {
        f[1][j] = 1;
    }
    for (i=1; i<=N; i++) {
        for (j=1; j<=K; j++) {
            for (k=1; k<=i-2; k++) {
                f[i][j] = (f[i][j] + f[k][j-1]*f[i-k-1][j-1]) % 9901;
            }
        }
    }
    return (f[N][K]-f[N][K-1]+9901) % 9901;
}

int main()
{
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    scanf("%d %d", &N, &K);
    printf("%d\n", cal());
    return 0;
}
