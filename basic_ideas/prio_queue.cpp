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

priority_queue <int> q;
int g[100][100], n, visit[100], cost[100];

struct Node {
    int u;
    int cost;
    bool operator < (Node a) const
    {
        return cost >a.cost;
    }
};

void dijkstra(int s)
{
    int v;
    memset(visit, 0, sizeof(visit));
    memset(cost, 0x3f, sizeof(cost));
    cost[0]=0;
    priority_queue< Node> pq;
    Node u;
    u.u= s;
    u.cost= 0;
    pq.push(u);
    while( !pq.empty() ) {
        u= pq.top();
        pq.pop();
        if(visit[u.u]) continue;
        visit[u.u]=1;
        for(v=0 ; v<n ; v++) {
            if( visit[v]==0 && cost[v]> cost[u.u]+g[u.u][v]) {
                cost[v]= cost[u.u]+g[u.u][v];
                Node x;
                x.u= v;
                x.cost= cost[v];
                pq.push(x);
            }
        }
    }
}

int main()
{
    int i, a[100], j, m, x, y, v;
    while(scanf("%d", &n) && n)
    {
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
            q.push(a[i]);
        }
        for(i=0 ; i<n ; i++) {
            printf("%d\n", q.top());
            q.pop();
        }
        scanf("%d %d", &n, &m);
        memset(g, 0x3f, sizeof(g));
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &x, &y, &v);
            g[x][y]=g[y][x]=v;
        }
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<n ; j++)
                printf("%d ", g[i][j]);
            printf("\n");
        }
        dijkstra(0);
        for(i=0 ; i<n ; i++) printf("%d ", cost[i]);
        printf("\n");
    }
    return 0;
}
