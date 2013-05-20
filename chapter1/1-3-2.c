/*
ID: zeyuec1
LANG: C
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>

int M, S, C;
int cow[1000];
int space[1000], spaceLen = 0;

int cmp0(const void *a, const void *b) {
    int *fa = (int*) a;
    int *fb = (int*) b;
    return *fa - *fb;
}

int cmp(const void *a, const void *b) {
    int *fa = (int*) a;
    int *fb = (int*) b;
    return *fb - *fa;
}

int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int i, sum = 0;
    scanf("%d %d %d", &M, &S, &C);
    
    for (i=0; i<C; i++) {
        scanf("%d", &cow[i]);
    }
    
    qsort(cow, C, sizeof(cow[0]), cmp0);
    
    for (i=1; i<C; i++) {
        space[spaceLen++] = cow[i] - cow[i-1]-1;
    }
    
    qsort(space, spaceLen, sizeof(space[0]), cmp);

    for (i=0; i<M-1; i++) {
        sum += space[i];
    }
    printf("%d\n", cow[C-1]-cow[0]+1 - sum);
    return 0;
}
