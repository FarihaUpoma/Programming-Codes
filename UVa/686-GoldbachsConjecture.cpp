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

int status[40000];

void sieve()
{
     int i,j , SIZE=40000;
     for(i=0;i<SIZE;i++) status[i]= 0;
     int sq = sqrt(SIZE);
     for(i=4;i<=SIZE;i+=2) status[i] = 1;
     for(i=3;i<=sq;i+=2){
        if(status[i]==0) {
            for(j=2*i;j<=SIZE;j+=i) status[j]=1;
        }
     }
     status[1] = 1;
}

int main()
{
    int n, i, c=0, x;
    while(scanf("%d", &n) && n)
    {
    sieve();
    x=n/2;
    for(c=0,i=1 ; i<=x ; i++) {
        if( status[i]==0 && status[n-i]==0) {
            //printf("%d+%d=n\n", i,n-i);
            //status[i]=1;
            //status[n-i]=1;
            c++;
        }
    }
    printf("%d\n", c);
    }
    return 0;
}
