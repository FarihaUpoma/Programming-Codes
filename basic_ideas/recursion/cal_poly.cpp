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

int s, j, r;

int cal_poly_ME(int i, int x, int n)
{
    if(i==n) return s;
    if(i==0) {
        s = 1;
    }
    else {
        s = s+ pow(x, i);
    }
    cal_poly_ME(i+1, x, n);
}

int cal_poly(int i, int x, int n)
{
    if(n==0)
        return 1;
    if(i<n)
        return (int)pow(x, i) + cal_poly(i+1, x, n);
    return 0;
}

int main()
{
    int x, n, res;
    scanf("%d %d", &x, &n);
    res= cal_poly(0, x, n);
    printf("%d\n", res);
    return 0;
}
