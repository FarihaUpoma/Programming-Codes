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

int st[200000], pr[200000];

void seive()
{
    int i, j;
    st[0]=st[1]= 1;
    for(j=2 ; j<200000 ; j++) {
        if(st[j]==0)
            for(i=j+j ; i<200000 ; i= i+j) st[i]= 1;
    }
    j=1;
    for(i=0 ; i<200000 ; i++) if( st[i]==0) pr[j++]= i;
}
int main()
{
    int n, d;
    seive();
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        printf("%d\n", pr[d]);
    }
    return 0;
}
