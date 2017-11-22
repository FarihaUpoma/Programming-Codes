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

int dw[8]= {1, 9, 0, 0, 0, 0, 0, 0};
int dx[8]= {0, 0, 1, 9, 0, 0, 0, 0};
int dy[8]= {0, 0, 0, 0, 1, 9, 0, 0};
int dz[8]= {0, 0, 0, 0, 0, 0, 1, 9};

int visit[10][10][10][10], cost[10][10][10][10];

void bfs(int w,int x, int y, int z, int p, int q, int r, int s)
{
    int xx, yy, zz ,ww, tw, tx, ty, tz, i, f;

    queue <int> q1,q2,q3,q4;
    visit[w][x][y][z]=1;
    cost[w][x][y][z]=0;
    q1.push(w);
    q2.push(x);
    q3.push(y);
    q4.push(z);
    f=0;
    while( !q1.empty() ) {
        ww= q1.front();
        xx= q2.front();
        yy= q3.front();
        zz= q4.front();
        q1.pop();q2.pop();q3.pop();q4.pop();
        for(i=0 ; i<8 ; i++) {
            tw= (ww+ dw[i])%10;
            tx= (xx+ dx[i])%10;
            ty= (yy+ dy[i])%10;
            tz= (zz+ dz[i])%10;
            //printf("tw=%d tx=%d ty=%d tz=%d\n", tw, tx, ty, tz);
            if( visit[tw][tx][ty][tz]==0) {
                visit[tw][tx][ty][tz]=1;
                cost[tw][tx][ty][tz]= cost[ww][xx][yy][zz]+1;
                q1.push(tw);
                q2.push(tx);
                q3.push(ty);
                q4.push(tz);
                if( tw==p && tx==q && ty==r && tz==s) {
                    f=1;
                    break;
                }
            }
        }
        if(f==1) break;
    }
}

int main()
{
    int t, w, x, y, z, p, q, r, s, a, b, c, d, n, i;
    scanf("%d", &t);
    while(t--) {
        memset(visit, 0, sizeof(visit));
        memset(cost, 0, sizeof(cost));
        scanf("%d %d %d %d", &w, &x, &y, &z);
        scanf("%d %d %d %d", &p, &q, &r, &s);
        scanf("%d", &n);

        for(i=0 ; i<n ; i++) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            visit[a][b][c][d]=1;
        }
        //printf("done\n");

        bfs(w,x,y,z,p,q,r,s);
        if(visit[p][q][r][s]==1) printf("%d\n", cost[p][q][r][s]);
        else printf("-1\n");
    }
    return 0;
}
