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

void p_rev(int n)
{
    if(n==0) return;
    printf("%d\n", n%10);
    p_rev(n/10);
}

void p(int n)
{
    if(n==0) return;
    p(n/10);
    printf("%d\n", n%10);
}

int main()
{
    int n;
    scanf("%d", &n);
    p_rev(n);
    printf("-----------\n");
    p(n);
    return 0;
}
