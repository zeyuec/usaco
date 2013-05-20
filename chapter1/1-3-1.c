/*
ID: zeyuec1
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct FARMER{
    int price, amount;
} FARMER;

int N, M;
FARMER farmer[6000];

int cmp(const void *a, const void *b) {
    FARMER *fa = (FARMER *) a;
    FARMER *fb = (FARMER *) b;
    return fa->price - fb->price;
}

int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int i;
    scanf("%d %d", &N, &M);
    for (i=0; i<M; i++) {
        scanf("%d %d", &farmer[i].price, &farmer[i].amount);
    }
    qsort(farmer, M, sizeof(farmer[0]), cmp);

    int nowAmount = 0, totalPrice = 0;
    for (i=0; i<M; i++) {
        if (nowAmount < N) {
            if (farmer[i].amount >= N-nowAmount) {
                totalPrice += (N-nowAmount) * farmer[i].price;
                nowAmount = N;
            } else {
                totalPrice += farmer[i].amount * farmer[i].price;
                nowAmount += farmer[i].amount;
            }
        } 
    }
    printf("%d\n", totalPrice);
    
    return 0;
}
