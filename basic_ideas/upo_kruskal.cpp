#include <stdio.h>
#include <string.h>
#include <math.h.>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct edge
{
    int u, v, cost;
    bool operator < (const edge &p) const
    {
        return cost < p.cost;
    }
};

vector <edge> g, ara[100];
int par[100], tot=0, n, e, k=0;

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
    sort(g.begin(), g.end());

    int i, u, v, cnt=0;
    for(i=0 ; i<n ; i++) {
        par[i] = i;
    }
    for(i=0 ; i<g.size() ; i++) {
        u = findPar( g[i].u );
        v = findPar( g[i].v );
        if( u != v ) {
            par[u] = v;
            ara[k++].push_back(g[i]);
            tot = tot+g[i].cost;
            cnt++;
            if(cnt == n-1)
                break;
        }
    }
}

int main()
{
    //freopen("in.txt", "r" , stdin);

    int i, a, b, c, j;
    scanf("%d %d", &n, &e);
    for(i=0 ; i<e ; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge temp;
        temp.u = a;
        temp.v = b;
        temp.cost = c;
        g.push_back(temp);
    }
    kruskal();

    for(i=0 ; i<n ; i++) {
        printf("%d 's par = %d\n", i, par[i]);
    }

    printf("Total Cost=%d\n\n", tot);
    for(i=0 ; i<k ; i++) {
        for(j=0 ; j<ara[i].size() ; j++) {
            printf("%d->%d\n" , ara[i][j].u, ara[i][j].v);
        }
    }
    return 0;
}
