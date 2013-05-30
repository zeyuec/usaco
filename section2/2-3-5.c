/*
  ID: zeyuec1
  LANG: C
  TASK: concom
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M, visited[110][110], control[110][110];

void try(int a, int b)
{
    if (visited[a][b] == 0) {
        visited[a][b] = 1;
        int k = 0;
        for (k=1; k<=M; k++) {
            if (control[b][k] > 0) {
                if (control[a][k] < 100) {
                    control[a][k] += control[b][k];
                }
                if (control[a][k] > 50) {
                    try(a, k);
                }
            }
        }
    }
}

void cal()
{
    int i, j;
    for (i=1; i<=M; i++) {
        for (j=1; j<=M; j++) {
            if (i != j && control[i][j] > 50) {
                try(i, j);
            }
        }
    }
    for (i=1; i<=M; i++) {
        for (j=1; j<=M; j++) {
            if (i != j && control[i][j] > 50) {
               printf("%d %d\n", i, j);
            }
        }
    }
}

int main()
{
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    memset(control, 0, sizeof(control));
    memset(visited, 0, sizeof(visited));
    int i, a, b, p;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d %d %d", &a, &b, &p);
        control[a][b] = p;
        M = a > M ? a : M;
        M = b > M ? b : M;
    }
    cal();
    return 0;
}
