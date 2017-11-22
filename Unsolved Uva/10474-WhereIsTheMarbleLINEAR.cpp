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

int a[10010];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, i, w, f, j, k=1;
    while(scanf("%d %d", &n, &q) && n && q)
    {
        for(i=0 ; i<n ; i++) scanf("%d", &a[i]);
        sort(a,a+n);
        printf("CASE# %d:\n", k++);
        for(i=0 ; i<q ; i++) {
            scanf("%d", &w);
            for(f=0,j=0 ; j<n ; j++) {
                if( a[j]==w) {
                    f=1;
                    break;
                }
            }
            if(f==0) printf("%d not found\n", w);
            else printf("%d found at %d\n", w,j+1);
        }
        for(i=0 ; i<n ; i++) a[i]=0;
    }
    return 0;
}
