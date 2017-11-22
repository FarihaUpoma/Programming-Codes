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
        return cost > p.cost;
    }
};

int par[200], n, mc;
vector <edge> g;

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
    for(i=0 ; i<n ; i++) {
        par[i] = i;
    }
    sort(g.begin(), g.end());

    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            par[u] = v;
            if(g[i].cost < mc)
                mc = g[i].cost;
            cnt ++;
            if(cnt == n-1)
                break;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int tCase, m, i, a, b, c, t=1;
    scanf("%d", &tCase);
    while(tCase--) {

        g.clear();
        mem(par, 0);

        scanf("%d %d", &n, &m);
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edge temp;
            temp.u = a;
            temp.v = b;
            temp.cost = c;
            g.pb(temp);
        }
        mc = 99999;
        kruskal();
        printf("Case #%d: %d\n",t++, mc);
    }
    return 0;
}
