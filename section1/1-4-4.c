/*
  ID: zeyuec1
  LANG: C
  TASK: milk3
*/

#include <stdlib.h>
#include <stdio.h>

int A, B, C;
int status[50][50][50];

void try(int a, int b, int c)
{
    if (status[a][b][c] == 0) {
        status[a][b][c] = 1;
        if (a > 0) {
            if (a+b > B) {
                try(a+b-B, B, c);
            } else {
                try(0, a+b, c);
            }
            
            if (a+c > C) {
                try(a+c-C, b, C);
            } else {
                try(0, b, a+c);
            }
        }

        if (b > 0) {
            if (b+a > A) {
                try(A, a+b-A, c);
            } else {
                try(a+b, 0, c);
            }
            if (b+c > C) {
                try(a, b+c-C, C);
            } else {
                try(a, 0, c+b);
            }
        }

        if (c > 0) {
            if (c+a > A) {
                try(A, b, c+a-A);
            } else {
                try(c+a, b, 0);
            }
            if (c+b > B) {
                try(a, B, c+b-B);
            } else {
                try(a, c+b, 0);
            }
        }
    }
}


int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    int i, isFirst = 1;
    scanf("%d %d %d", &A, &B, &C);
    try(0, 0, C);
    for (i=0; i<=C; i++) {
        if (status[0][C-i][i] == 1) {
            if (isFirst == 1) {
                printf("%d", i);
                isFirst = 0;
            } else {
                printf(" %d", i);
            }
        }
    }
    printf("\n");
    return 0;
}
