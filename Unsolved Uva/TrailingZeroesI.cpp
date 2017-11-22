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

int f[1000009];

void sieve()
{
    int i, j;
    f[0]=f[1]=1;
    int n= 1000000;
    for(i=2 ; i<n ; i++) {
        if(f[i]==0) {
            for(j=i+i ; j<1000000 ; j +=i) {
                f[j]=1;
                pr[j].push_back(i);
        }
    }
}

int main()
{
    int t, k, s, cnt, i;
    long long int n;
    sieve();
    scanf("%d", &t);
    for(k=0 ; k<t ; k++) {
        scanf("%lld", &n);

        printf("Case %d: %d\n", k+1, g[n]);
    }
    return 0;
}
