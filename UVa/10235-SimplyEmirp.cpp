#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int st[1000009];

void sieve()
{
    int i, j;
    st[0]=st[1]=1;
    for(i=4 ; i<=1000000 ; i=i+2) st[i]=1;
    for(i=3 ; i<=1000000 ; i++) {
        if( st[i]==0) {
            for(j=i+i ; j<=1000000 ; j=j+i)
                st[j]=1;
        }
    }
}

int main()
{
    int n, x, p;
    sieve();
    while(scanf("%d", &n)!=EOF)
    {
        if(st[n]==1) printf("%d is not prime.\n", n);
        else {
            x=0;
            p=n;
            while(p>0) {
                x= x*10+(p%10);
                p= p/10;
            }
            //printf("%d\n", x);
            if( st[x]==1 || x==n) printf("%d is prime.\n", n);
            else printf("%d is emirp.\n", n);
        }
    }
    return 0;
}
