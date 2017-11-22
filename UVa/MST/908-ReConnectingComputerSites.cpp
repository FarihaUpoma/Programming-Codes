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

int n, m, k, cost, prevCost, par[1000009];
vector <edge> g;

int findPar(int u)
{
    if( u == par[u] )
        return u;
    else
        return par[u] = findPar(par[u]);
}

void kruskal()
{
    int i, u, v, cnt=0;
    sort(g.begin() , g.end() ) ;
    for(i=1 ; i<=n ; i++) {
        par[i] = i;
    }

    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if( u!= v) {
            par[u] = v;
            cost += g[i].cost;
            cnt++;
            if(cnt == n-1)
                break;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, a, b, c,f=0;
    while(scanf("%d", &n)!=EOF ) {

        if(f) {
            printf("\n");
        }
        f=1;

        cost = 0;
        prevCost = 0;
        memset(par, 0, sizeof(par));
        g.clear();
        edge temp;
        for(i=1 ; i<n ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            prevCost += c;
        }
        scanf("%d", &k);
        for(i=0 ; i<k ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            temp.u = a;
            temp.v = b;
            temp.cost = c;
            g.push_back(temp);
        }

        scanf("%d", &m);
        for(i=0 ; i<m ; i++) {
            scanf("%d %d %d", &a, &b, &c);
            temp.u = a;
            temp.v = b;
            temp.cost= c;
            g.push_back(temp);
        }
        kruskal();
        printf("%d\n%d\n", prevCost, cost);
    }
    return 0;
}
