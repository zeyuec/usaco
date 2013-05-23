/*
  ID: zeyuec1
  LANG: C
  TASK: ariprog
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct ANS {
    int p, q;
} ANS;

int N, M, max, ansLen = 0;
int hash[250*250*2+10];
ANS ans[10010];

int cmp(const void *a, const void *b)
{
    ANS *fa = (ANS*) a;
    ANS *fb = (ANS*) b;
    if (fa->q == fb->q) {
        return fa->p - fb->p;
    } else {
        return fa->q - fb->q;
    }
}

void preGen(int k)
{
    int p, q;
    for (p=0; p<=k; p++) {
        for (q=0; q<=k; q++) {
            hash[p*p + q*q] = 1;
        }
    }
}

inline int checkSeq(int a, int b, int len)
{
    int i;
    for (i=0; i<len; i++) {
        if (hash[a+i*b] == 0) {
            return 0;
        }
    }
    return 1;
}

void cal()
{
    int a, b;
    int count = 0;
    for (a=0; a<=M*M*2-(N-1); a++) {
        for (b=1; b<=(2*M*M-a)/(N-1); b++) {
            if (a + b*(N-1) <= M*M*2) {
                count++;
                if (checkSeq(a, b, N) == 1) {
                    ans[ansLen].p = a;
                    ans[ansLen].q = b;
                    ansLen++;
                }
            } else {
                break;
            }
        }
    }
}

int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    int i;
    scanf("%d %d", &N, &M);
    preGen(M);
    
    cal();

    if (ansLen == 0) {
        printf("NONE\n");
    } else {
        qsort(ans, ansLen, sizeof(ans[0]), cmp);        
        for (i=0; i<ansLen; i++) {
            printf("%d %d\n", ans[i].p, ans[i].q);
        }
    }
    
    return 0;
}
