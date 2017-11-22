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

int main()
{
    int x ;
    double y;
    y = 2.57;
    if( ceil(y)-y < y-floor(y)) x = ceil(y);
    else x = floor(y);
    printf("%d %.0lf\n", x,y);
    long long int p=1000000000000000;
    x = 34;
    y = (double)p/x;
    printf("%lf\n", y);
    return 0;
}
