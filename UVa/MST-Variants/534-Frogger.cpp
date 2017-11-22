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
    int u;
    double cost;
    bool operator < (const node &p) const
    {
        return  cost > p.cost;
    }
};

int visit[500], a[500][2], n;
double d[500];
vector <int> g[500];
vector <double> cost[500];

void dijkstra(int s)
{
    int i, u, v;
    mem(visit, 0);
    for(i=0 ; i<n ; i++)
        d[i] = 999999.00;
    d[s] = 0;
    priority_queue <node> pq;
    node x;
    x.u = s;
    x.cost = 0;
    pq.push(x);
    while(!pq.empty()) {
        x = pq.top();
        pq.pop();
        if(visit[x.u] == 1 ) continue;
        visit[x.u] = 1;
        u = x.u;
        for(i=0 ; i<g[u].size() ; i++) {
            v = g[x.u][i];
            double tmp_cst;
            if(d[u]>cost[u][i])
                tmp_cst = d[u];
            else
                tmp_cst = cost[u][i];
            if(d[v] > tmp_cst)
                d[v] = tmp_cst;
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

    int i, j, t=1;
    while(scanf("%d", &n) && n) {
        for(i=0 ; i<n ; i++) {
            scanf("%d %d", &a[i][0], &a[i][1]);
        }
        for(i=0 ; i<n ; i++) {
            for(j=i+1 ; j<n ; j++) {
                double dis = sqrt( (a[i][0]-a[j][0])*(a[i][0]-a[j][0]) + (a[i][1]-a[j][1])*(a[i][1]-a[j][1]) );
                g[i].pb(j);
                g[j].pb(i);
                cost[j].pb(dis);
                cost[i].pb(dis);
            }
        }
        dijkstra(0);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", t++,d[1]);
        for(i=0 ; i<n ; i++) {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
