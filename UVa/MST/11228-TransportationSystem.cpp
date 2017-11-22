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
    int u, v;
    double cost;
    bool operator < (const edge & p) const
    {
        return cost < p.cost;
    }
};

int n, r, d[1009][2], par[1009], rail;
double railCost, roadCost;
vector <edge> g;

int findPar(int u)
{
    if(u==par[u])
        return u;
    else
        return par[u] = findPar(par[u]);
}

void kruskal()
{
    int i, u, v, cnt = 0;
    sort(g.begin() , g.end() ) ;
    for(i=0 ; i<n ; i++) {
        par[i] = i;
    }
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            par[u] = v;
            if(g[i].cost > r) {
                rail++;
                railCost += g[i].cost;
            }
            else
                roadCost += g[i].cost;
            cnt ++;
            if(cnt == n-1)
                break;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int tCase, i, j, a, b, k;
    double dis;
    scanf("%d", &tCase);
    for(i=1 ; i<=tCase ; i++) {

        g.clear();
        mem(par,0);
        mem(d, 0);
        rail = 0;
        railCost = 0.0;
        roadCost = 0.0 ;

        scanf("%d %d", &n, &r);
        for(j=0 ; j<n ; j++) {
            scanf("%d %d" , &a, &b);
            d[j][0] = a;
            d[j][1] = b;
        }

        edge temp;
        for(j=0 ; j<n ; j++) {
            for(k=j+1 ; k<n ; k++) {
                dis = sqrt( (d[j][0]-d[k][0])*(d[j][0]-d[k][0]) + (d[j][1]-d[k][1])*(d[j][1]-d[k][1]) );
                temp.u = j;
                temp.v = k;
                temp.cost = dis;
                g.pb(temp);
            }
        }
        kruskal();

        printf("Case #%d: %d %.0lf %.0lf\n",i, rail+1, roadCost, railCost);
    }
    return 0;
}
