/*
  ID: zeyuec1
  LANG: C
  TASK: money
*/

#include <stdio.h>
#include <stdlib.h>

int V, N, coin[30];
long long f[30][10010];

long long cal()
{
    int i, j;
    for (i=0; i<=V; i++) {
        f[i][0] = 1;
    }
    for (i=1; i<=V; i++) {
        for (j=1; j<=N; j++) {
            if (j-coin[i-1] >=0) {
                f[i][j] = f[i-1][j] + f[i][j-coin[i-1]];
            } else {
                f[i][j] = f[i-1][j];
            }
        }
    }
    return f[V][N];
}

int main()
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int i;
    scanf("%d %d", &V, &N);
    for (i=0; i<V; i++) {
        scanf("%d", &coin[i]);
    }
    printf("%lld\n", cal());
    return 0;
}
