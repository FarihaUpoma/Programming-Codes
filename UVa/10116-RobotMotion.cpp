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

char a[101][110];
int g[100][100];

int main()
{
    //freopen("input.txt", "r" , stdin);

    int n, m, c, i, x, y, k, f, step, loop, j;
    while(scanf("%d %d %d", &n, &m, &c) && m && n)
    {
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);
        for(i=0 ; i<n ; i++) for(j=0 ; j<m ; j++) g[i][j]= -1;
        x= 0;y= c-1;
        g[x][y]=0;
        k=1;
        f=0;
        while( 1 ) {
            if( a[x][y]== 'N') {
                if( x-1<0  ) break;
                x--;
            }
            else if( a[x][y]== 'W') {
                if(y-1 <0) break;
                y--;
            }
            else if( a[x][y]== 'E') {
                if(y+1 >=m) break;
                y++;
            }
            else if( a[x][y]== 'S') {
                if(x+1 >=n) break;
                x++;
            }
            //printf( "%d %d\n", x, y);
            if( g[x][y] >-1) {
                loop = k++;
                step= g[x][y];
                f=1;
                break;
            }
            else g[x][y]= k++;
        }
        if(f==1) {
            printf("%d step(s) before a loop of %d step(s)\n", step, loop-step);
        }
        else
            printf("%d step(s) to exit\n", g[x][y]+1);
    }
    return 0;
}
