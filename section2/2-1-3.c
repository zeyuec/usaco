/*
  ID: zeyuec1
  LANG: C
  TASK: sort3
*/

#include <stdio.h>
#include <stdlib.h>

int N, num[1100], count[4];
int ans = 0;

void swap(int x, int y)
{
    int t = num[x];
    num[x] = num[y];
    num[y] = t;
    ans++;
}

void try(int x, int y, int st, int end)
{
    int i = -1;
    int p = end;
    while (num[p] != x && p < N) {
        p++;
    }
    for (i=st; i<end; i++) {
        if (num[i] == y) {
            if (p < N) {
                swap(i, p);
            }
            while (num[p] != x && p < N) {
                p++;
            }
        }
    }
}

void cal()
{
    try(1, 2, 0, count[1]);
    try(1, 3, 0, count[1]);
    try(2, 3, count[1], count[1]+count[2]);
    printf("%d\n", ans);
}

int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    int i;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &num[i]);
        count[num[i]]++;
    }
    cal();
    return 0;
}
