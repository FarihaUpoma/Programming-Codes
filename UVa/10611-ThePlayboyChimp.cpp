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

int a[1000009], b[1000009];

int main()
{
    int n, i, d, j, w,q, start, end, mid, m, k;
    scanf("%d", &n);
    int r=n;
    for(i=0 ,k=0; i<r ; i++) {
        scanf("%d", &d);
        if(d==a[k-1]) {
            n--;
            continue;
        }
        else {
            a[k]= d;
            k++;
        }
    }
    //printf("n=%d\n", n);

    //for(i=0 ; i<n ; i++) printf("%d ", a[i]); printf("\n");
    scanf("%d", &q);
    for(i=0 ; i<q ; i++)
    {
        scanf("%d", &w);
        if(w>a[n-1]) printf("%d X\n", a[n-1]);
        else {
            start= 0; end= n-1;
            while(1)
            {
                mid= (start+end)/2;
                if( start==end) break;
                else if( a[mid]<w) start= mid+1;
                else end= mid;
            }

            for(j=mid ; j>=0 ; j--)
            {
                if(a[j]<w) break;
            }
            //printf("after:\n");
            if( a[mid]==w) mid++;
            if(j<0) printf("X ");
            else printf("%d ", a[j]);
            if(mid==n) printf("X\n");
            else printf("%d\n", a[mid]);
        }

    }
    return 0;
}
