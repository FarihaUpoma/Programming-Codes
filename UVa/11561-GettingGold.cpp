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

int visit[60][60], gold, n, m;
char a[60][60];

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i, t;
    memset(visit, 0, sizeof(visit));
    queue <int> q1, q2;
    visit[x][y]=1;
    a[x][y]='.';
    q1.push(x);
    q2.push(y);
    gold=0;
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop(); q2.pop();
        for(t=0,i=0 ; i<4 ; i++) {
            tx= xx+ dx[i];
            ty= yy+dy[i];
            if(tx<1 || tx>=n-1 || ty<1 || ty>=m-1) continue;
            if( a[tx][ty]== 'T') t++;
        }
        if(t==0) {
            for(i=0 ; i<4 ; i++) {
                tx= xx+ dx[i];
                ty= yy+dy[i];
                if(tx<1 || tx>=n-1 || ty<1 || ty>=m-1) continue;
                if(a[tx][ty]=='G'  && visit[tx][ty]==0) {
                    a[tx][ty]=='.';
                    visit[tx][ty]=1;
                    gold++;
                    q1.push(tx);
                    q2.push(ty);
                }
                else if(a[tx][ty]=='.' && visit[tx][ty]==0) {
                    visit[tx][ty]=1;
                    q1.push(tx);
                    q2.push(ty);
                }
            }
        }
    }
}

int main()
{
    int i, j;
    while(scanf("%d %d", &m, &n)!=EOF)
    {
        for(i=0 ; i<n ; i++) {
            scanf("%s", a[i]);
        }
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if( a[i][j]=='P') {
                    bfs(i, j);
                    break;
                }
            }
        }
        printf("%d\n", gold);
    }
    return 0;
}
