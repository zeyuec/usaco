/*
  ID: zeyuec1
  LANG: C
  TASK: zerosum
*/

#include <stdio.h>
#include <stdlib.h>

int N, split[10];

void try(int k) {
    if (k == N) {
        int i=1, sum = 1;
        split[N] = -1;
        
        while (split[i] == 0 && i < N) {
            sum = sum * 10 + i+1;
            i++;
        }
        
        while (i < N) {
            int t = split[i++];
            int next = i;
            while (split[i] == 0 && i < N) {
                next = next * 10 + i+1;
                i++;
            }
            if (t == 1) {
                sum += next;
            }
            if (t == 2) {
                sum -= next;
            }
        }

        if (sum == 0) {
            printf("1");
            for (i=1; i<N; i++) {
                if (split[i] == 0) printf(" %d", i+1);
                if (split[i] == 1) printf("+%d", i+1);
                if (split[i] == 2) printf("-%d", i+1);
            }
            printf("\n");
        }
    } else {
        split[k] = 0;
        try(k+1);
        split[k] = 1;
        try(k+1);
        split[k] = 2;
        try(k+1);
    }
}

int main()
{
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    scanf("%d", &N);
    try(1);
    return 0;
}
