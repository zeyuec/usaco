/*
  ID: zeyuec1
  LANG: C
  TASK: preface
*/

#include <stdio.h>
#include <stdlib.h>

int N, count[300];
char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void calRomanNum(int n) {
    if (n >= 1000) {
        count['M']++;
        calRomanNum(n-1000);
    } else if (n >= 900) {
        count['M']++;
        count['C']++;
        calRomanNum(n-900);
    } else if (n >= 500) {
        count['D']++;
        calRomanNum(n-500);
    } else if (n >= 400) {
        count['D']++;
        count['C']++;
        calRomanNum(n-400);
    } else if (n >= 100) {
        count['C']++;
        calRomanNum(n-100);
    } else if (n >= 90) {
        count['C']++;
        count['X']++;
        calRomanNum(n-90);
    } else if (n >= 50) {
        count['L']++;
        calRomanNum(n-50);
    } else if (n >= 40) {
        count['L']++;
        count['X']++;
        calRomanNum(n-40);
    } else if (n >= 10) {
        count['X']++;
        calRomanNum(n-10);
    } else if (n >= 9) {
        count['X']++;
        count['I']++;
        calRomanNum(n-9);
    } else if (n >= 5) {
        count['V']++;
        calRomanNum(n-5);
    } else if (n >= 4) {
        count['V']++;
        count['I']++;
        calRomanNum(n-4);
    } else if (n >= 1) {
        count['I']++;
        calRomanNum(n-1);
    }
}

int main()
{
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    int i;
    scanf("%d", &N);
    for (i=1; i<=N; i++) {
        calRomanNum(i);
    }
    for (i=0; i<7; i++) {
        if (count[(int)ch[i]]>0) {
            printf("%c %d\n", ch[i], count[(int)ch[i]]);
        }
    }
    return 0;
}
