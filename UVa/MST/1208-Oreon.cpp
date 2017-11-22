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

int city, par[100], cost;
vector <edge> g, costEdge;

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
    sort(g.begin() , g.end() );
    for(i=0 ; i<city ; i++)
        par[i] = i;
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            par[u] = v;
            costEdge.pb(g[i]);
            cnt++;
            if(cnt==city-1)
                break;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int tCase , i, j, k, c;
    scanf("%d", &tCase);
    for(i=1 ; i<=tCase ; i++) {
        scanf("%d", &city);

        cost = 0;
        costEdge.clear();
        g.clear();
        edge temp;

        for(j=0 ; j<city ; j++) {
            for(k=0 ; k<city ; k++) {
                scanf("%d,", &c);
                if(c==0 || k<=j) continue;
                temp.u = j;
                temp.v = k;
                temp.cost = c;
                g.pb(temp);
            }
        }
        kruskal();
        printf("Case %d:\n", i);
        for(j=0 ; j< costEdge.size() ; j++) {
            printf("%c-%c %d\n", costEdge[j].u+65 , costEdge[j].v+65, costEdge[j].cost);
        }
    }
    return 0;
}
