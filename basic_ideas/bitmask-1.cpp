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

///same bit pattern as A except it has all bits 0 within 4th to 23rd position.

int main()
{
    unsigned int a=923857;
    unsigned int x=2147483647, i, p;
    printf("%d\n", x & (x+1));
    x<< 20;
    for(i=0 ; i<4 ; i++) {
         x = (x<<1) |1;
    }
    printf("%d\n", a & x);
    return 0;
}
