/*
ID: zeyuec1
LANG: C
TASK: packrec
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct RECT {
    int h, w;
} RECT;

RECT rect[5], ans[2000];
int len = 0;

int cmp(const void *a, const void *b)
{
    RECT *fa = (RECT*) a;
    RECT *fb = (RECT*) b;
    if (fa->w * fa->h == fb->w * fb->h) {
        if (fa->w == fb->w) {
            return fa->h - fb->h;
        } else {
            return fa->w - fb->w;
        }
    } else {
        return fa->w*fa->h - fb->w*fb->h;
    }
}

int max(int num, ... )
{
    int i, m = -1;
    va_list ap;
    va_start (ap, num);
    for (i= 0; i<num; i++ ) {
        int t = va_arg(ap, int);
        if (t > m) {
            m = t;
        }
    }
    va_end(ap);
    return m;
}

void addToAns(int w, int h)
{
    if (w > h) {
        int t = w;
        w = h;
        h = t;
    }
    ans[len].w = w;
    ans[len].h = h;
    len++;
}


void cal(RECT a, RECT b, RECT c, RECT d)
{
    int maxw, maxh;
    /* 1 */
    maxh = max(4, a.h, b.h, c.h, d.h);
    maxw = a.w + b.w + c.w + d.w;
    addToAns(maxw, maxh);
    
    /* 2 */
    maxh = a.h + max(3, b.h, c.h, d.h);
    maxw = max(2, a.w, b.w+c.w+d.w);
    addToAns(maxw, maxh);
    
    /* 3 */
    maxh = max(3, a.h+c.h, b.h+c.h, d.h);
    maxw = max(2, a.w+b.w, c.w) + d.w;        
    addToAns(maxw, maxh);
    
    /* 4 */
    maxh = max(3, a.h, c.h+d.h, b.h);
    maxw = a.w + b.w + max(2, c.w, d.w);
    addToAns(maxw, maxh);
    
    /* 5 */
    maxh = max(2, a.h+c.h, b.h+d.h);
    if (c.h>=b.h+d.h) {
        maxw = max(3, a.w, b.w+c.w, c.w+d.w);
    }
    if (c.h > d.h && c.h < b.h+d.h) {
        maxw = max(3, a.w+b.w, b.w+c.w, c.w+d.w);
    }
    if (c.h < d.h && d.h < a.h+c.h) {
        maxw = max(3, a.w+b.w, a.w+d.w, c.w+d.w);
    }
    if (d.h >= a.h+c.h) {
        maxw = max(3, b.w, a.w+d.w, c.w+d.w);
    }
    if (c.h == d.h) {
        maxw = max(2, a.w+b.w, c.w+d.w);
    }
    addToAns(maxw, maxh);
}

RECT flip(RECT r, int f) {
    if (f == 0) {
        return r;
    } else {
        RECT nr;
        nr.w = r.h;
        nr.h = r.w;
        return nr;
    }
}

void try()
{
    int a, b, c, d, fa, fb, fc, fd;
    for (a=1; a<=4; a++) {
        for (b=1; b<=4; b++) {
            for (c=1; c<=4; c++) {
                for (d=1; d<=4; d++) {
                    
                    if (a+b+c+d==10 && a*b*c*d==24) {
                        for (fa=0; fa<=1; fa++) {
                            for (fb=0; fb<=1; fb++) {
                                for (fc=0; fc<=1; fc++) {
                                    for (fd=0; fd<=1; fd++) {
                                        cal(flip(rect[a], fa),
                                            flip(rect[b], fb),
                                            flip(rect[c], fc),
                                            flip(rect[d], fd));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    qsort(ans, len, sizeof(ans[0]), cmp);
    int i = 0, min = ans[0].w*ans[0].h;
    ans[len].w = 0;
    ans[len].h = 0;
    printf("%d\n", min);
    while (i < len && ans[i].w*ans[i].h == min) {
        printf("%d %d\n", ans[i].w, ans[i].h);
        while (ans[i+1].w == ans[i].w && ans[i+1].h == ans[i].h) {
            i++;
        }
        i++;
    }
}
    

int main()
{
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    int i, x, y;
    for (i=1; i<=4; i++) {
        scanf("%d %d", &x, &y);
        if (x > y) {
            rect[i].h = x;
            rect[i].w = y;
        } else {
            rect[i].h = y;
            rect[i].w = x;
        }
    }
    try();
    return 0;
}
