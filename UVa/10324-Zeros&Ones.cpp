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

char g[1000009];

int main()
{
    int n, i, x, y, a, b, f, l, j, T=1;
    while(gets( g)!=NULL) {
        //getchar();
        if(strlen(g)==0) break;
        scanf("%d", &n);
        printf("Case %d:\n", T++);
        for(j=0 ; j<n ; j++) {
            scanf("%d %d", &a, &b);
            x= min(a, b);
            y= max(a, b);
            f=0;
            //printf("min %d max %d\n", x, y);
            for(i=x ; i<=y ; i++) {
                if( g[i] != g[x]) {
                    f=1;
                    break;
                }
            }
            if(f==1) printf("No\n");
            else printf("Yes\n");
        }
        getchar();
    }
    return 0;
}
