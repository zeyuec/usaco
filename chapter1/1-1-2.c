/*
ID: zeyuec1
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int NP;
char nameList[20][20];
int moneyList[20];

int nameToId(char name[20])
{
    int i;
    for (i=0; i<NP; i++) {
        if (strcmp(name, nameList[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main()
{
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int i, j, money, giveCount;
    char name[20];
    scanf("%d", &NP);
    for (i=0; i<NP; i++) {
        scanf("%s\n", nameList[i]);
    }
    for (i=0; i<NP; i++) {
        scanf("%s\n%d %d", name, &money, &giveCount);
        int id = nameToId(name);
        if (giveCount > 0) {
            moneyList[id] -= (int)(money/giveCount) * giveCount;
        }
        for (j=0; j<giveCount; j++) {
            scanf("%s\n", name);
            id = nameToId(name);
            moneyList[id] += money/giveCount;
        }
    }
    for (i=0; i<NP; i++) {
        printf("%s %d\n", nameList[i], moneyList[i]);
    }
    return 0;
}
