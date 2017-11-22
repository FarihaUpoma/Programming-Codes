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

///same bit pattern as A except it has all bits 1 within 9th and 30th position.

int main()
{
    unsigned int a=12;
    unsigned x=0, i, p= 30-9+1;
    for(i=0 ; i< p ; i++) {
        x = (x<<1) |1;
    }
    x = x<<9;
    printf("%d\n", a|x);
    return 0;
}
