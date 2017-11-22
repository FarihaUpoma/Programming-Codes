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

struct Node {
    int u;
    int cost;
    bool operator < (Node a) const
    {
        return cost> a.cost;
    }
};

int visit[110], cost[110], g[110][110], n;
vector <int> edge[200];

void dijkstra(int s)
{
    memset(visit, 0, sizeof(visit));
    memset(cost, 0x3f, sizeof(cost));
    int v;
    cost[s]= 0;
    priority_queue <Node> pq;
    Node u;
    u.u=s;
    u.cost= 0;
    pq.push(u);
    while( !pq.empty() ) {
        u= pq.top();
        pq.pop();
        if(visit[u.u]==1) continue;
        visit[u.u]=1;
        for(v=0 ; v<edge[u.u].size() ; v++) {
            if(cost[ edge[u.u][v] ] > cost[u.u]+g[u.u][ edge[u.u][v] ]) {
                cost[ edge[u.u][v] ]= cost[u.u]+g[u.u][ edge[u.u][v] ];
                Node x;
                x.u= edge[u.u][v];
                x.cost= cost[edge[u.u][v] ];
                pq.push(x);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t_case, e, T, m, a, b, t, mice, i;
    scanf("%d", &t_case);
    while(t_case--) {
        memset(g, 0, sizeof(g));
        scanf("%d %d %d", &n, &e, &T);
        scanf("%d", &m);
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &a, &b, &t);
            edge[b].push_back(a);
            g[b][a]= t;
        }
        dijkstra(e);
        for(mice=1,i=1 ; i<=n ; i++) {
            //printf("%d ", cost[i]);
            if(cost[i]<=T && cost[i]>0) mice++;
        }
        printf("%d\n", mice);
        if(t_case>0) printf("\n");
        for(i=0 ; i<=n ; i++) edge[i].clear();
    }
    return 0;
}
