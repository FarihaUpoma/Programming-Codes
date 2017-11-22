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
    int i, j, n;
    n= 1000000;
    f[0]=f[1]=1;
    for(i=2; i<n ; i++) {
        if(f[i]==0) {
            for(j=i+i ; j<n ; j +=i) {
                f[j]=1;
            }
        }
    }
}

int main()
{
    int n, i;
    sieve();
    while(scanf("%d", &n) && n)
    {
        for(i=2 ; i<n ; i++) {
            if(f[i]==0) {
                if( f[n-i]==0) {
                    printf("%d = %d + %d\n", n, i, n-i);
                    break;
                }
            }
        }
    }
    return 0;
}
