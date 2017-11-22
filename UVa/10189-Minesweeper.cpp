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

char a[110][110];
int b[110][110];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, i, j, k, x, y, t=1;
    while(scanf("%d %d", &n, &m) && n && m)
    {
        memset( b, 0, sizeof(b));
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);
        if(t>1) printf("\n");
        printf("Field #%d:\n", t++);
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if(a[i][j]=='*') {
                    b[i][j]= -1;
                    for(k=0 ; k<8 ; k++) {
                        x= i+dirx[k];
                        y= j+diry[k];
                        if(b[x][y]==-1 || x>=n || x<0 || y>=m || y<0) continue;
                        b[x][y] += 1;
                    }
                }
            }
        }
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if(b[i][j]==-1) printf("*");
                else printf("%d", b[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
