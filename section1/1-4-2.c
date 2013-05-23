/*
  ID: zeyuec1
  LANG: C
  TASK: clocks
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int clocks[20], times[20], minTimes[20], solved = 0;

int check()
{
    int i;
    for (i=0; i<9; i++) {
        if (clocks[i] != 12) {
            return 0;
        }
    }
    return 1;
}

void change(int num, ... )
{
    int i;
    va_list ap;
    va_start (ap, num);
    for (i= 0; i<num; i++ ) {
        int t = va_arg(ap, int);
        clocks[t] = (clocks[t] + 2) % 12 +1;
    }
    va_end(ap);
} 

void changeByType(int type)
{
    switch (type) {
    case 1:
        change(4, 0, 1, 3, 4);
        break;
    case 2:
        change(3, 0, 1, 2);
        break;
    case 3:
        change(4, 1, 2, 4, 5);
        break;
    case 4:
        change(3, 0, 3, 6);
        break;
    case 5:
        change(5, 1, 3, 4, 5, 7);
        break;
    case 6:
        change(3, 2, 5, 8);
        break;
    case 7:
        change(4, 3, 4, 6, 7);
        break;
    case 8:
        change(3, 6, 7, 8);
        break;
    case 9:
        change(4, 4, 5, 7, 8);
        break;
    }
}

void try(int k) {
    if (!solved) {
        if (k > 9) { 
            int i = 0, j = 0, bkClocks[10], sum = 1;
        
            for (i=0; i<9; i++) {
                bkClocks[i] = clocks[i];
            }
        
            for (i=1; i<=9; i++) {
                for (j=0; j<times[i]; j++) {
                    changeByType(i);
                }
                sum = sum*10 + i;
            }

            int isFirst = 1;
            if (check() == 1) {
                for (i=1; i<=9; i++) {
                    for (j=0; j<times[i]; j++) {
                        if (isFirst) {
                            printf("%d", i);
                            isFirst = 0;
                        } else {
                            printf(" %d", i);
                        }
                    }
                }
                printf("\n");
                solved = 1;
            }
            for (i=0; i<9; i++) {
                clocks[i] = bkClocks[i];
            }
        
        } else {
            int t;
            for (t=0; t<4; t++) {
                times[k] = t;
                try(k+1);
            }
        }
    }
}

int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    int i;
    for (i=0; i<9; i++) {
        scanf(" %d", &clocks[i]);
    }
    try(1);
    return 0;
}
