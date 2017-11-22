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

int a[100];

void rec(int i, int n)
{
    if(i==n) return ;
    if(i==0) {
        printf("1");
    }
    else {
        printf(" + x");
        if(i>1) printf("^%d", i);
    }
    rec(i+1, n);
}

int main()
{
    int i, n, x;
    scanf("%d", &n);
    rec(0, n);
    printf("\n");
    return 0;
}
