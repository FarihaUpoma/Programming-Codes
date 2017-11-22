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
#define pb push_back
#define mem(a, n) memset(a, n, sizeof(a))

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

struct node
{
    int u, cost;
    bool operator < (const node &p) const
    {
        return cost < p.cost;
    }
};

int visit[200], d[200];
vector <int> g[200], cost[200];

void dijkstra(int s)
{
    int i, u, v;
    mem(visit, 0);
    mem(d, 0);
    d[s] = 999999;
    priority_queue <node> pq;
    node x;
    x.u = s;
    x.cost = d[s];
    pq.push(x);
    while(!pq.empty()) {
        x = pq.top();
        pq.pop();
        u = x.u;
        if(visit[u] == 1)
            continue;
        visit[u] = 1;
        for(i=0 ; i<g[u].size() ; i++) {
            v = g[u][i];
            int tmpCost = min(d[u], cost[u][i]);
            //printf("u=%d d[u]=%d cost[u][v]=%d v=%d d[v]=%d\n", u, d[u], cost[u][i], v, d[v]);
            if( d[v] < tmpCost ) {
                d[v] = tmpCost;
                //printf("updated d[%d]=%d\n",v, d[v]);
            }
            node a;
            a.u = v;
            a.cost = d[v];
            pq.push(a);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m, i, a, b, c, tourist, t=1;
    while(scanf("%d %d", &n, &m)) {
        if(n==0 && m==0)
            break;
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            g[a].pb(b);
            g[b].pb(a);
            cost[a].pb(c);
            cost[b].pb(c);
        }
        scanf("%d %d %d", &a, &b, &tourist);
        dijkstra(a);
        double db = d[b]-1;
        int  trip = ceil( tourist / db );
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",t++, trip);
        for(i=1 ; i<=n ; i++) {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
