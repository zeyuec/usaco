/*
ID: zeyuec1
LANG: C
TASK: pprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long A, B;

int isPrime(long long num)
{
    int i;
    for (i=2; i<=sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int getNumWidth(unsigned long long num)
{
    int width = 0;
    while (num > 0){
        width++;
        num = num / 10;
    }
    return width;
}

int isPalindrome(long long num)
{
    long long
        d = 0,
        p = num,
        r = 0;
    while (num > 0)  {
        d = num % 10;
        r = r * 10 + d;
        num = num / 10;
    }
    return (p == r);
}

long long transposition(long long num)
{  
    long long i = 0;
    long long trans = 0;
    while (num != 0) {  
        i = num % 10;  
        num = num / 10;
        trans = trans*10 + i;
    }  
    return trans;  
}  

long long nextPalindrome(long long num) {
    /* tow case:
       12311 -> 12321
       12321 -> 12421
       choose minium which is bigger than num itself
    */
    long long newNum = 0;
    long long newNum2 = 0;

    int width = getNumWidth(num);
    long long half = (num/pow(10, width/2));

    if (width%2 == 0) {
        newNum = (half+1)*pow(10, width/2) + transposition(half+1);
        newNum2 = (half)*pow(10, width/2) + transposition(half);
    } else {
        newNum = (half+1)*pow(10, width/2) + transposition((half+1)/10);
        newNum2 = (half)*pow(10, width/2) + transposition(half/10);
    }
    
    if (newNum2 > num) {
        newNum = newNum2;
    }
    
    return newNum;
}

void cal()
{
    long long i = A;
    do {
        if (isPrime(i)) {
            printf("%lld\n", i);
        }
        i = nextPalindrome(i);
    } while (i <= B);
}

int main()
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    scanf(" %lld %lld", &A, &B);
    cal();
    return 0;
}
