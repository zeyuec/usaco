/*
ID: zeyuec1
LANG: C
TASK: dualpal
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
long long S;
int num[50], numLen;

void numChangeBase(int n, int b, int num[], int *len)
{
    *len = 0;
    while (n > 0) {
        num[(*len)++] = n % b;
        n = n / b;
    }
}

int isPalin(int num[], int len)
{
    int i=0, j=len-1;
    while (i<=j) {
        if (num[i] == num[j]) {
            i++;
            j--;
        } else {
            return 0;
        }
    }
    return 1;
}

int isDualPin(long long n)
{
    int b, isP = 0;
    for (b=2; b<=10; b++) {
        memset(num, 0, sizeof(int)*50);
        numLen = 0;
        numChangeBase(n, b, num, &numLen);
        if (isPalin(num, numLen)) {
            isP++;
            if (isP >= 2) {
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int count = 0;
    long long i;
    scanf("%d %lld", &N, &S);
    i = S;
    while (count<N) {
        i++;
        if (isDualPin(i)) {
            printf("%lld\n", i);
            count++;
        }
    }
    return 0;
}
