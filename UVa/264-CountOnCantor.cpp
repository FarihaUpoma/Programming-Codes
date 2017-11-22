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

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

int min(int x, int y)
{
    if( x<y) return x;
    else return y;
}

int max(int x, int y)
{
    if( x>y) return x;
    else return y;
}

int a[1000009];

int main()
{
    int i, j, n, sub, u, d;
    for(i=1 ; ; i++) {
        a[i]= i+a[i-1];
        if(a[i]>10000005) break;
    }
    /*for(j=1 ; j<=i ; j++) {
        printf("%d= %d\n", j, a[j]);
    }*/
    while(scanf("%d", &n)!=EOF)
    {
        for(j=0 ; j<i ; j++) {
            if(a[j]>=n)
                break;
        }
        //printf("%d\n", j);
        sub= a[j]-n;
        if(j%2!=0) {
            d= j-sub;
            u= j+1-d;
        }
        else {
            u= j-sub;
            d= j+1-u;
        }
        printf("TERM %d IS %d/%d\n",n, u, d );
    }
    return 0;
}
