/*
  ID: zeyuec1
  LANG: C
  TASK: sprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int seed[100] = {2, 3, 5, 7};

int isPrime(int num)
{
    int i;
    for (i=2; i<=sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void cal()
{
    int i, dight;
    int st = 0, end = 0, len = 0, qEnd = 4;
    while (len < N) {
        st = end;
        end = qEnd;
        for (i=st; i<end; i++) {
            for (dight=0; dight<10; dight++) {
                if (isPrime(seed[i]*10+dight)) {
                    seed[qEnd++] = seed[i]*10+dight;
                }
            }
        }
        len++;
    }
    for (i=st; i<end; i++) {
        printf("%d\n", seed[i]);
    }
}


int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    scanf("%d", &N);
    cal();
    return 0;
}
