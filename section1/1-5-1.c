/*
ID: zeyuec1
LANG: C
TASK: numtri
*/

#include <stdio.h>
#include <stdlib.h>

int N, tri[1010][1010], f[1010][1010];

int max(int a, int b)
{
    return a > b? a : b;
}

int main()
{
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    int i, j;
    scanf("%d", &N);
    for (i=1; i<=N; i++) {
        for (j=1; j<=i; j++) {
            scanf(" %d", &tri[i][j]);
        }
    }

    for (i=1; i<=N; i++) {
        for (j=1; j<=N; j++) {
            f[i][j] = max(f[i-1][j], f[i-1][j-1]) + tri[i][j];
        }
    }
    

    int m = -1;
    for (i=1; i<=N; i++) {
        m = max(m, f[N][i]);
    }

    printf("%d\n", m);
    
    
    return 0;
}
