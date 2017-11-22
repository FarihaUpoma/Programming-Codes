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

int visit[1010], cost[1010], g[1010][1010], f;
vector <int> edge[1010];

struct Node {
    int u;
    int cost;
    bool operator < (Node a) const
    {
        return cost> a.cost;
    }
};

void dijkstra()
{
    memset(visit, 0, sizeof(visit));
    memset(cost, 0x3f, sizeof(cost));
    int v;
    cost[0]=0;
    priority_queue <Node> pq;
    Node u;
    u.u= 0;
    u.cost=0;
    pq.push(u);
    while(!pq.empty()) {
        u= pq.top(), pq.pop();
        if(visit[u.u]==1) continue;
        visit[u.u]=1;
        for(v=0 ; v< edge[u.u]. size() ; v++) {
            if( cost[ edge[u.u][v] ] > cost[u.u]+g[u.u][ edge[u.u][v] ]) {
                if(visit[ edge[u.u][v] ]==1) {
                    f=1;
                    break;
                }
                else {
                    cost[ edge[u.u][v] ]= cost[u.u]+ g[u.u][edge[u.u][v] ];
                    Node x;
                    x.u= edge[u.u][v];
                    x.cost= cost[ edge[u.u][v] ];
                    pq.push(x);
                }
            }
        }
        if(f==1) break;
    }
}

int main()
{
    int t_case, n, m, a, b, t, i;
    scanf("%d", &t_case);
    while(t_case--) {
        scanf("%d %d", &n, &m);
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &a, &b, &t);
            edge[a].push_back(b);
            g[a][b]= t;
        }
        dijkstra();
        if(f==1) printf("possible\n");
        else printf("not possible\n");
        f=0;
        for(i=0 ; i<=n ; i++) edge[i].clear();
        memset(g, 0, sizeof(g));
    }
    return 0;
}
