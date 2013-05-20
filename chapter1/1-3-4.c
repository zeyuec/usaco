/*
ID: zeyuec1
LANG: C
TASK: crypt1
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, hash[10];

int isLegal(int n)
{
    while (n > 0) {
        if (hash[n % 10] == 0) {
            return 0;
        }
        n = n / 10;
    }
    return 1;
}

int cal()
{
    int count = 0;
    int a, b, k1, k2, k3;
    
    for (a=111; a<=999; a++) {
        for (b=11; b<=99; b++) {
            if (isLegal(a) == 1 && isLegal(b) == 1) {
                k1 = (b % 10) * a;
                k2 = (b / 10) * a;
                k3 = a * b;
                if (k1 > 999 || k2 > 999 || k3 > 9999) {
                    continue;
                }
                if (isLegal(k1) == 1 && isLegal(k2) == 1 && isLegal(k3) == 1) {
                    count++;
                } else {
                    continue;
                }
            }
        }
    }
    return count;
}

int main()
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    int i, d, ret;
    memset(hash, 0, sizeof(int)*10);
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &d);
        hash[d] = 1;
    }

    ret = cal();
    printf("%d\n", ret);
    
    return 0;
}
