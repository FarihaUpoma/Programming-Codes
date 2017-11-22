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

int visit[50][50], d, n;
char a[50][50];

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q1, q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    while(!q1.empty() ) {
        xx= q1.front(), q1.pop();
        yy= q2.front(), q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]=='.') {
                if(visit[tx][ty]==0) {
                    visit[tx][ty]=1;
                    q1.push(tx);
                    q2.push(ty);
                }
            }
            else if(a[tx][ty]=='#' || ty<0 || tx<0 || tx>=n || ty>=n){
                d= d+9;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++) {
        scanf("%s", a[i]);
    }
    d=0;
    bfs(0,0);
    if(visit[n-1][n-1]==0) bfs(n-1, n-1);
    printf("%d\n", d-36);
    return 0;
}
