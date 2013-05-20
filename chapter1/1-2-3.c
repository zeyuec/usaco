/*
ID: zeyuec1
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *dict;

int wordLen;
long long N;
char word[5000][50];

void readDict()
{
    dict = fopen("dict.txt", "r");
    wordLen = 0;
    while (fscanf(dict, "%s\n", word[wordLen++]) != EOF) {
    }
}

long long wordToNum(char word[])
{
    int i, d;
    long long num = 0;
    for (i=0; i<strlen(word); i++) {
        if (word[i] == 'A' || word[i] == 'B' || word[i] == 'C') {
            d = 2;
        }
        if (word[i] == 'D' || word[i] == 'E' || word[i] == 'F') {
            d = 3;
        }
        if (word[i] == 'G' || word[i] == 'H' || word[i] == 'I') {
            d = 4;
        }
        if (word[i] == 'J' || word[i] == 'K' || word[i] == 'L') {
            d = 5;
        }
        if (word[i] == 'M' || word[i] == 'N' || word[i] == 'O') {
            d = 6;
        }
        if (word[i] == 'P' || word[i] == 'R' || word[i] == 'S') {
            d = 7;
        }
        if (word[i] == 'T' || word[i] == 'U' || word[i] == 'V') {
            d = 8;
        }
        if (word[i] == 'W' || word[i] == 'X' || word[i] == 'Y') {
            d = 9;
        }
        num = num*10 + d;
    }
    return num;
}

void cal()
{
    int i, ifOutput = 0;
    for (i=0; i<wordLen; i++) {
        if (wordToNum(word[i]) == N) {
            printf("%s\n", word[i]);
            ifOutput = 1;
        }
    }
    if (0 == ifOutput) {
        printf("NONE\n");
    }
}

int main()
{
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    readDict();
    scanf("%lld", &N);
    cal();
    fclose(dict);
    return 0;
}

