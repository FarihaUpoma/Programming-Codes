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

int a[1000];

int remv_odd1(int i, int n)
{
    int p;
    if(i==n) return n;
    if(a[i]%2 !=0) {
        for(p=i ; p<n ; p++)
            a[p] = a[p+1];
        i--;
        n--;
    }
    remv_odd1(i+1, n);
}

int remv_odd(int i, int j, int n)
{
    if(i==n) return j;

    if(a[i]%2==0)
        a[j++] =a[i];
    remv_odd(i+1, j, n);
}

int main()
{
    int n, i, x;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) scanf("%d", &a[i]);
    x=remv_odd(0,0, n);
    for(i=0 ; i<x ; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
