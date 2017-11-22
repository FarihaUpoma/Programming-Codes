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

int n, m, par[1000009], cost;
vector <edge> g;
bool pos;

int findPar(int u)
{
    if( u == par[u] )
        return u;
    else {
        return par[u]=findPar(par[u]);
    }
}

void kruskal()
{
    int i, u, v, cnt=0;
    sort(g.begin() , g.end());
    for(i=0 ; i<n ; i++)
        par[i] = i;
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            par[u] = v;
            if( g[i].cost > cost)
                cost = g[i].cost;
            cnt++;
            if(cnt == n-1)
                break;
        }
    }
    if(cnt < n-1)
        pos = false;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, a, b, c;
    while(scanf("%d %d", &n, &m) ) {
        if(n==0 && m== 0)
            break;

        cost = 0;
        pos = true;
        g.clear();

        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            edge temp;
            temp.u = a;
            temp.v = b;
            temp.cost = c;
            g.pb(temp);
        }
        kruskal();
        if(pos)
            printf("%d\n", cost);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
