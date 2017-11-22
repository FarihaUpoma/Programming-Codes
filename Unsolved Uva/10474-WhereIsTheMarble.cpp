#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int a[1000009];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, w, i, start, end, mid, f, k=1;
    while(scanf("%d %d", &n, &q))
    {
        if(n==0 && q==0) break;
        for(i=0 ; i<n ; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        //for(i=0 ; i<n ; i++) printf("%d ", a[i]);
        //printf("\n");
        printf("CASE# %d:\n", k++);
        for(i=0 ; i<q ; i++) {
            f=0;
            scanf("%d", &w);

            start= 0; end= n-1;
            while(1)
            {
                mid= (start+end)/2;
                //printf("a[mid=%d]= %d\n", mid,a[mid]);
                if( w==a[mid]) break;
                else if(start>=end) {
                    f=1;
                    break;
                }
                else if( w> a[mid]) start= mid+1;
                else end= mid;

            }
            if(f==1) printf("%d not found\n", w);
            else
                printf("%d found at %d\n", w,mid+1);
        }
        for(i=0 ; i<n ; i++) a[i]=0;
    }
    return 0;
}
