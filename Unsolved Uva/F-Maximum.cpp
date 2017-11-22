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

int a[100000], m[100000];

void faltu()
{
    int i, x;
    a[0]=0;
    a[1]=1;
    m[0]=0;
    m[1]=1;
    for(i=2 ; i<=100000 ; i++) {
        if( i%2==0) {
            x= i/2;
            a[i]= a[x];
            if( a[x] > m[i-1])
                m[i]= a[x];
            else m[i]= m[i-1];
        }
        else {
            x= i/2;
            a[i]= a[x]+a[x+1];
            if( a[x]+a[x+1] > m[i-1])
                m[i]= a[x]+ a[ x+1];
            else m[i]= m[i-1];
        }
    }
}

int main()
{
    int n;
    faltu();
    while(scanf("%d", &n) && n) {
        printf("%d\n", m[n]);
    }
    return 0;
}
