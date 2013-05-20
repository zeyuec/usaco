/*
ID: zeyuec1
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>

int N;
int weekTimes[10];

void nextDay(int *d, int *m, int *y)
{
    if (*m == 4 || *m == 6 || *m == 9 || *m == 11) {
        // normal 30
        if (*d < 30) {
            *d  = *d + 1;
        } else {
            *d = 1;
            *m = *m + 1;
        }
    } else if (*m == 1 || *m == 3 || *m == 5 || *m == 7 || *m == 8 || *m == 10) {
        // normal 31
        if (*d < 31) {
            *d  = *d + 1;
        } else {
            *d = 1;
            *m = *m + 1;
        }
    } else if (*m == 2) {
        // feb
        int limit = 28;
        if (*y % 400 == 0) {
            limit++;
        } else if (*y % 4 == 0 && *y % 100 != 0) {
            limit++;
        }
        if (*d < limit) {
            *d = *d + 1;
        } else {
            *d = 1;
            *m = *m + 1;
        }
    } else if (*m == 12) {
        // dec
        if (*d < 31) {
            *d = *d + 1;
        } else {
            *d = 1;
            *m = 1;            
            *y = *y + 1;
        }
    }
    return;
}

void cal()
{
    int day = 1, month = 1, year = 1900, w = 0;
    while (year < 1900+N) {
        if (day == 13) {
            weekTimes[w]++;
        }
        w = (w+1) % 7;
        nextDay(&day, &month, &year);        
    }
    printf("%d %d %d %d %d %d %d\n", weekTimes[5], weekTimes[6], weekTimes[0], weekTimes[1], weekTimes[2], weekTimes[3], weekTimes[4]);
}

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    scanf("%d", &N);
    cal();
    return 0;
}
