#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int a[110];

int wrap(int m, int n)
{
    int i, x, c=0, k=1;
    for(i=1 ; i<=n ; i++) a[i]=1;
    a[1]=0;
    for(i=1; ; i++)
    {
        x= i%n;
        if(x==0) x= n;
        if(a[x]==1)
        {
            c++;
            if(c==m) {
                a[x]=0;
                //printf("%d out\n", x);
                c=0;
                k++;
            }
        }
        if(k==n-1) break;
    }
    return a[13];
}

int main()
{
    int n, i;
    while(scanf("%d", &n) && n)
    {
        for(i=1 ; i<=n ; i++) {
            if(wrap(i, n)==1) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
