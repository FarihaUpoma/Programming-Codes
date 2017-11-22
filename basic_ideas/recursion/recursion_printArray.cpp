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

void p(int i, int x, int n)
{
    printf("%d %d\n", a[i], a[x]);
    if(i==(n-1)/2 && x==n/2) return ;
    p(i+1, x-1, n);
}

int main()
{
    int i, n;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) scanf("%d", &a[i]);
    p(0, n-1, n);
    return 0;
}
