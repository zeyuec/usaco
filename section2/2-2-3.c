/*
  ID: zeyuec1
  LANG: C
  TASK: runround
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long M;

int num[50], numLen, hash[50];

int roundNum(unsigned long long k) {
    /* printf("%lld\n", k); */
    numLen = 0;
    memset(num, 0, sizeof(num));
    memset(hash, 0, sizeof(hash));
    while (k > 0) {
        if (hash[k%10] == 1 || k % 10 == 0) {
            return 0;
        } else {
            hash[k%10] = 1;
            num[numLen++] = k % 10;
            k = k / 10;
        }
    }
    memset(hash, 0, sizeof(hash));
    int i;
    int st = numLen-1;
    for (i=0; i<numLen; i++) {
        /* printf("%d %d\n", st, num[st]); */
        if (hash[num[st]] == 0) {
            hash[num[st]] = 1;
            st = (st-num[st]+10*numLen)%numLen;
        } else {
            return 0;
        }
    }
    if (i == numLen && st == numLen-1) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    scanf("%lld", &M);
    unsigned long long i = M+1;
    while (roundNum(i) == 0) {
        i++;
    }
    printf("%lld\n", i);
    return 0;
}
