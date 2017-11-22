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
    bool operator < (const node & p) const
    {
        return cost > p.cost;
    }
};

int visit[200], d[200], ache[500];
vector <int> g[200], cost[200];

bool dijkstra(int s, int dd)
{
    int u, v, i;
    bool exist = false;
    mem(visit, 0);
    mem(d, 0x3f);
    d[s] = 0;
    priority_queue <node> pq;
    node x;
    x.u = s;
    x.cost = 0;
    pq.push(x);
    int t=1;
    while(!pq.empty() ) {
        x = pq.top();
        pq.pop();
        u = x.u;
        if(visit[u] == 1) continue;
        visit[u] = 1;
        for(i=0 ; i<g[u].size() ; i++) {
            v = g[u][i];
            if(v==dd) {
                exist = true;
            }
            int tmpCst = max(d[u], cost[u][i]);
            if( d[v] > tmpCst)
                d[v] = tmpCst;
            node a;
            a.u = v;
            a.cost = d[v];
            pq.push(a);
        }
    }
    return exist;
}


int main()
{
   // freopen("input.txt", "r", stdin);

    int c, s, q, i, a, b, t=1, cc;
    while(scanf("%d %d %d", &c, &s, &q) ) {
        if(c==0 && s==0 && q==0)
            break;
        if(t>1)
            printf("\n");
        for(i=0 ; i<s ; i++) {
            scanf("%d %d %d", &a, &b, &cc);
            g[a].pb(b);
            g[b].pb(a);
            cost[a].pb(cc);
            cost[b].pb(cc);
            ache[a]=ache[b]=1;
        }

        printf("Case #%d\n", t++);
        for(i=0 ; i<q ; i++) {
            scanf("%d %d", &a, &b);
            if(dijkstra(a, b))
                printf("%d\n", d[b]);
            else
                printf("no path\n");
        }
        for(i=1 ; i<=c ; i++) {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
