/*
ID: zeyuec1
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int B, len, orgLen;
int num[50], orgNum[50];

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

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int i, j;
    scanf("%d", &B);
    for (i=1; i<=300; i++) {
        memset(num, 0, sizeof(int) * 50);
        len = 0;
        numChangeBase(i*i, B, num, &len);
        if (isPalin(num, len)) {
            
            memset(orgNum, 0, sizeof(int) * 50);
            orgLen = 0;
            numChangeBase(i, B, orgNum, &orgLen);
            
            for (j=orgLen-1; j>=0; j--) {
                if (orgNum[j] > 9) {
                    printf("%c", 'A'+orgNum[j]-10);
                } else {
                    printf("%d", orgNum[j]);
                }
            }
            printf(" ");

            for (j=0; j<len; j++) {
                if (num[j] > 9) {
                    printf("%c", 'A'+num[j]-10);
                } else {
                    printf("%d", num[j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
