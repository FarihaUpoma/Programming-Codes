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

int visit[20100], cost[20100];
vector <int> g[20010];
vector <int> value[20010];

struct Node {
    int u;
    int cost;
    bool operator < (Node a) const
    {
        return cost > a.cost;
    }
};

void dijkstra(int s, int n)
{
    int v;
    memset(visit, 0, sizeof(visit));
    memset(cost, 0x3f, sizeof(cost));
    cost[s]=0;
    priority_queue <Node> pq;
    Node u;
    u.u= s;
    u.cost= cost[u.u];
    pq.push(u);
    while( ! pq.empty() ) {
        u= pq.top();
        pq.pop();
        if( visit[u.u]==1) continue;
        visit[u.u]=1;
        for(v=0 ; v<g[u.u].size() ; v++) {
            if( visit[ g[u.u][v] ]==0 && cost[ g[u.u][v] ]> cost[u.u]+value[u.u][ v ]) {
                cost[ g[u.u][v] ]= cost[u.u]+value[u.u][ v ];
                Node x;
                x.u= g[u.u][v];
                x.cost= cost[ g[u.u][v] ];
                pq.push(x);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);

    int t, m, x, y, n, i, p, q, c, k=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &n, &m, &x, &y);
        //memset(value, 0x3f, sizeof(value));
        //memset(g, 0x3f, sizeof(g));
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &p, &q, &c);
            g[p].push_back(q);
            value[p].push_back(c);
            g[q].push_back(p);
            value[q].push_back(c);
        }
        printf("Case #%d: ", k++);
        dijkstra(x, n);
        if(cost[y]==1061109567) printf("unreachable\n");
        else printf("%d\n", cost[y]);
        for(i=0 ; i<n ; i++) {
            g[i].clear();
            value[i].clear();
        }
    }
    return 0;
}
