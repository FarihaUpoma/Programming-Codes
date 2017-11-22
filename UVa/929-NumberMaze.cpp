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

int g[1000][1000], visit[1000][1000], cost[1000][1000];

struct Node {
    int ux;
    int uy;
    int cost;
    bool operator < (Node a) const
    {
        return cost > a.cost;
    }
};

void dijkstra(int x, int y, int row, int col)
{
    int tx, ty, i;
    memset(visit, 0, sizeof(visit));
    memset(cost, 0x3f, sizeof(cost));
    cost[x][y]=0;
    priority_queue <Node> pq;
    Node u;
    u.ux= x; u.uy= y;
    u.cost= 0;
    //printf("ost %d\n", u.cost);
    pq.push(u);
    while( !pq.empty() ) {
        u= pq.top(), pq.pop();
        if(visit[u.ux][u.uy]==1) continue;
        visit[u.ux][u.uy]=1;
        for(i=0 ; i<4 ; i++) {
            tx= u.ux+dx[i];
            ty= u.uy+dy[i];
            if(tx<0 || tx>=row || ty<0 || ty>=col) continue;
            if( visit[tx][ty]==0 && cost[tx][ty] > cost[u.ux][u.uy]+ g[tx][ty]) {
                cost[tx][ty]= cost[u.ux][u.uy]+g[tx][ty];
                Node p;
                p.ux= tx;
                p.uy= ty;
                p.cost= cost[tx][ty];
                pq.push(p);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, i, j, row, col;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &row, &col);
        for(i=0 ; i<row ; i++) {
            for(j=0 ; j<col ; j++)
                scanf("%d", &g[i][j]);
        }
        dijkstra(0, 0, row, col);
        printf("%d\n", cost[row-1][col-1]+g[0][0]);
        memset(g, 0, sizeof(g));
    }
    return 0;
}
