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
    bool operator < (const edge &p) const
    {
        return cost < p.cost;
    }
};

int a[1000][2], par[1000], n, m;
vector <edge> g, road;

int findPar(int u)
{
    if(par[u] == u)
        return u;
    else
        return par[u] = findPar(par[u]);
}

bool kruskal()
{
    int i, u, v, cnt=0;
    bool path = false;
    sort(g.begin(), g.end());
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            //printf("%d %d %.3lf\n", g[i].u, g[i].v, g[i].cost);
            par[u] = v;
            road.pb(g[i]);
            path= true;
            cnt++;
            if(cnt >= n-1)
                break;
        }
    }
    return path;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int tCase, i, j, x, y, u, v;
    double dis;
    scanf("%d", &tCase);
    while(tCase--) {

        g.clear();
        road.clear();
        mem(par,0);
        mem(a, 0);

        scanf("%d", &n);
        for(i=1 ; i<=n ; i++) {
            scanf("%d %d", &a[i][0], &a[i][1]);
            par[i] = i;
        }


        scanf("%d", &m);
        for(i=0 ; i<m ; i++) {
            scanf("%d %d", &x, &y);
            u = findPar(x);
            v = findPar(y);
            if(u!=v) {
                par[u] = v;
                //printf("scan %d %d %d %d %d %d\n", x, y, u, v, par[x], par[y]);
            }
        }
        for(i=1 ; i<=n ; i++) {
            for(j= i+1 ; j<=n ; j++) {
                u = findPar(i);
                v = findPar(j);
                if(u!=v) {
                    //printf("push %d %d %d %d\n", i, j, u, v);
                    dis = sqrt( (a[i][0]-a[j][0])*(a[i][0]-a[j][0]) + (a[i][1]-a[j][1])*(a[i][1]-a[j][1]) );
                    edge temp;
                    temp.u = i;
                    temp.v = j;
                    temp.cost = dis;
                    g.pb(temp);
                }
            }
        }
        if(!kruskal()) {
            printf("No new highways need\n");
        }
        else {
            for(i=0 ; i<road.size() ; i++) {
                printf("%d %d\n", road[i].u, road[i].v);
            }
        }
        if(tCase>0)
            printf("\n");
    }
    return 0;
}
