/*
ID: zeyuec1
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[100], str2[100];

int main()
{
    int i, sum1=1, sum2=1;
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    scanf("%s\n%s\n", str1, str2);
    for (i=0; i<strlen(str1); i++) {
        sum1 *= (str1[i]-'A'+1);
    }
    for (i=0; i<strlen(str2); i++) {
        sum2 *= (str2[i]-'A'+1);
    }
    if (sum1 % 47 == sum2 % 47) {
        printf("GO\n");
    } else {
        printf("STAY\n");
    }
    return 0;
}
