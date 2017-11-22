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

struct edge
{
    int u, v, cost;
    bool operator < (const edge &p) const
    {
        return cost < p.cost;
    }
};

int par[200], n, cost;
vector <edge> g, road;
bool testing;

int findPar(int u)
{
    if(par[u] == u)
        return u;
    else
        return par[u] = findPar(par[u]);
}

void kruskal()
{
    int i, u, v, cnt = 0;
    for(i=1 ; i<=n ; i++) {
        par[i] = i;
    }
    cost = 0;
    sort(g.begin(), g.end());

    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            par[u] = v;
            cost = cost + g[i].cost;
            if(!testing)
                road.pb(g[i]);
            cnt ++;
            if(cnt == n-1)
                break;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int tCase, m, i, j, a, b, c, fCost, sCost;
    scanf("%d", &tCase);
    while(tCase--) {

        g.clear();
        road.clear();
        mem(par, 0);

        scanf("%d %d", &n, &m);
        for(i=1 ; i<=m ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edge temp;
            temp.u = a;
            temp.v = b;
            temp.cost = c;
            g.pb(temp);
        }
        testing = false;
        kruskal();
        testing = true;
        fCost = cost;
        sCost = 99999;
        for(i=0 ; i<road.size() ; i++) {
            //printf("road %d\n", road[i].cost);
            for(j=0 ; j<g.size() ; j++) {
                if(road[i].u == g[j].u && road[i].v == g[j].v && road[i].cost == g[j].cost) {
                    edge temp;
                    temp.cost =road[i].cost;
                    temp.u = road[i].u;
                    temp.v = road[i].v;
                    g[j].cost = 99999;
                    kruskal();
                    g.pop_back();
                    g.pb(temp);
                    if(cost < sCost)
                        sCost = cost;
                }
            }
        }
        printf("%d %d\n", fCost, sCost);
    }
    return 0;
}
