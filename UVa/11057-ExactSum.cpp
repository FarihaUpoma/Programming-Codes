#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int b[1000009], a[1000009];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, m, d, x, y, min;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
            b[ a[i] ]= 1;
        }
        scanf("%d", &m);
        min= m;
        for(i=0 ; i <n ; i++) {
            d= m-a[i];
            if(d<0 || d>1000009) continue;
            if( b[ d ]==1 && abs(d-a[i])<min) {
                x= a[i];
                y= d;
                min=abs(x-y);
            }
        }
        if(x>y) swap(x,y);

        printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
        memset(b, 0, sizeof(b));
    }
    return 0;
}
