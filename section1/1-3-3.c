/*
ID: zeyuec1
LANG: C
TASK: calfflac
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char text[21000], line[100];
char pureText[21000];
int pureTextLen = 0, hash[21000];

int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

void cal()
{
    int i, j, max, maxA, maxB;
    for (i=0; i<pureTextLen; i++) {
        j = 0;
        while (i-j >= 0 && i+j < pureTextLen && pureText[i-j] == pureText[i+j]) {
            j++;
        }
        j--;
        if (1+j*2 > max) {
            max = 1+j*2;
            maxA = i-j;
            maxB = i+j;
        }

        j = 0;
        while (i-j >=0 && i+1+j < pureTextLen && pureText[i-j] == pureText[i+1+j]) {
            j++;
        }
        j--;
        if (j*2 > max) {
            max = j*2;
            maxA = i-j;
            maxB = i+j+1;
        }
    }
    printf("%d\n", maxB-maxA+1);
    for (i=hash[maxA]; i<=hash[maxB]; i++) {
        printf("%c", text[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    while (fgets(line, 100, stdin) != NULL) {
        strcat(text, line);
    }
    for (i=0; i<strlen(text); i++) {
        if (isLetter(text[i]) == 1) {
            pureText[pureTextLen] = toupper(text[i]);
            hash[pureTextLen] = i;
            pureTextLen++;
        }
    }
    pureText[pureTextLen] = '\0';
    cal();

    return 0;
}
