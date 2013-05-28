/*
  ID: zeyuec1
  LANG: C
  TASK: prefix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[210][15], str[80];
int wordLen[210], f[200010];
char text[200010];
int wordCount = 0;

int cal()
{
    int i, j, k, max = 0;
    int len = strlen(text);
    f[0] = 1;
    for (i=0; i<len; i++) {
        if (!f[i]) {
            continue;
        }
        for (j=0; j<wordCount; j++) {
            if (i+wordLen[j] > len) continue;
            for (k=0; k<wordLen[j]; k++) {
                if (text[i+k] != word[j][k]) {
                    break;
                }
            }
            if (k == wordLen[j]) {
                f[i+wordLen[j]] = 1;
                if (i+wordLen[j] > max) {
                    max = i+wordLen[j];
                }
            }
        }
    }
    return max;
}

int main()
{
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    scanf("%s", str);
    wordCount = 0;
    while (strcmp(str, ".") != 0) {
        strcpy(word[wordCount], str);
        wordLen[wordCount++] = strlen(str);
        scanf("%s", str);
    }
    str[0] = '\0';    
    while (scanf("%s", str) != EOF) {
        strcat(text, str);
    }
    printf("%d\n", cal());
    return 0;
}
