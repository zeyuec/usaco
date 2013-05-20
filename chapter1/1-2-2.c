/*
ID: zeyuec1
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 11

int N;
char source[MAXN][MAXN], dest[MAXN][MAXN];

void rotate(char m[MAXN][MAXN], char new[MAXN][MAXN])
{
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            new[j][N-1-i] = m[i][j];
        }
    }
}

void reflect(char m[MAXN][MAXN], char new[MAXN][MAXN])
{
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            new[i][j] = m[i][N-1-j];
        }
    }
}

void copy(char from[MAXN][MAXN], char to[MAXN][MAXN])
{
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            to[i][j] = from[i][j];
        }
    }
}

int isEqual(char m1[MAXN][MAXN], char m2[MAXN][MAXN])
{
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (m1[i][j] != m2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int cal()
{
    int i;
    char temp[MAXN][MAXN], map[MAXN][MAXN];

    // 1-3
    copy(source, map);
    for (i=0; i<3; i++) {
        rotate(map, temp);
        if (isEqual(temp, dest) == 1) {
            return i+1;
        }
        copy(temp, map);
    }

    // 4
    copy(source, map);
    reflect(map, temp);
    if (isEqual(temp, dest) == 1) {
        return 4;
    }

    // 5 (now temp is a reflaction of source)
    copy(temp, map);
    for (i=0; i<3; i++) {
        rotate(map, temp);
        if (isEqual(temp, dest) == 1) {
            return 5;
        }
        copy(temp, map);
    }

    // 6
    if (isEqual(source, dest) == 1) {
        return 6;
    }

    return 7;
}

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int i, ret;
    scanf("%d\n", &N);
    for (i=0; i<N; i++) {
        scanf("%s", source[i]);
    }
    for (i=0; i<N; i++) {
        scanf("%s", dest[i]);
    }
    ret = cal();
    printf("%d\n", ret);

    return 0;
}
