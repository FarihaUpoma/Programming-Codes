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

int dx[6]= {-1, 0, 1, 0, 0, 0};
int dy[6]= {0, -1, 0, 1, 0, 0};
int dl[6]= {0, 0, 0, 0, +1, -1};

char g[60][60][60];
int visit[60][60][60], cost[60][60][60], cst, n, m, l;

void bfs(int d, int x, int y)
{
    int ll, xx, yy, tl, tx, ty, i, f;
    memset(visit, 0, sizeof(visit));
    //memset(cost, 0, sizeof(cost));
    queue <int> q1, q2, ql;
    visit[d][x][y]=1;
    cost[d][x][y]=0;
    ql.push(d);
    q1.push(x);
    q2.push(y);
    cst=0;
    f=0;
    while( !q1.empty() ) {
        ll= ql.front();
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        ql.pop();
        for(i=0 ; i<6; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            tl= ll+ dl[i];
            if( tx<0 || tx>=n || ty<0 || ty>=m || tl<0 || tl>=l) continue;
            if(visit[tl][tx][ty]==0) {
                if( g[tl][tx][ty]=='.') {
                    visit[tl][tx][ty]=1;
                    cost[tl][tx][ty]= cost[ll][xx][yy]+1;
                    ql.push(tl);
                    q1.push(tx);
                    q2.push(ty);
                }
                else if( g[tl][tx][ty]=='E') {
                    //printf("%d %d %d\n", tl, tx, ty);
                    cost[tl][tx][ty]= cost[ll][xx][yy]+1;
                    f=1;
                    cst= cost[tl][tx][ty];
                    break;
                }
            }
        }
        if(f==1) break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int k, i, j, f;
    while(scanf("%d %d %d", &l, &n, &m) && l && n && m)
    {
        for(j=0 ; j<l ; j++) {
            for(i=0 ; i<n ; i++) {
                scanf("%s", g[j][i]);
            }
        }

        for(i=0 ; i<l ; i++) {
            for(j=0 ; j<n ; j++) {
                for(k=0 ; k<m ; k++) {
                    if( g[i][j][k]=='S') {
                        bfs(i, j, k);
                    }
                }
            }
        }
        if(cst==0) printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", cst);
        memset(g,0,sizeof(g));
    }
    return 0;
}
