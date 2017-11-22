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

int a[105],b[105], c[105];

int main()
{
    int n, i, j, k;
    while(scanf("%d", &n) && n)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for(i=1 ; i<=n ; i++) {
            a[i]=a[i+n]= 1;
            b[i]= i;
        }
        j=n+1;
        k=0;
        for(i=1 ; b[i] ; i++) {
            if(a[i]==1) {
                a[i]= a[i+1]=0;
                b[j++]= b[i+1];
                c[k++]= b[i];
            }
        }
        printf("Discarded cards:");
        for(i=0 ; i<k-1 ; i++) {
            printf(" %d", c[i]);
            if(i<k-2) printf(",");
        }
        printf("\nRemaining card: %d\n", c[k-1]);
    }
    return 0;
}
