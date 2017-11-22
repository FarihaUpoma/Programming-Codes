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
#define check printf("done\n")

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

int findPar(int i)
{
    if(par[i] == i)
        return i;
    else
        return par[i] = findPar(par[i]);
}

bool kruskal()
{
    int i, u, v, cnt = 0;
    //check;
    sort(g.begin(), g.end());

    for(i=1 ; i<=n ; i++) {
        par[i] = i;
    }
    cost = 0;
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            par[u] = v;
            if(!testing)
                road.pb(g[i]);
            cost += g[i].cost;
            cnt ++;
            if(cnt == n-1)
                break;
        }
    }
    testing = true;
    if(cnt == n-1)
        return true;
    else
        return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int tCase, e, i, a, b, c, fCost, sCost, j, t=1;
    scanf("%d", &tCase);
    while(tCase--) {

        g.clear();
        road.clear();
        testing = false;

        scanf("%d %d", &n, &e);
        for(i=0 ; i<e ; i++) {
            scanf("%d %d %d" , &a, &b, &c);
            edge temp;
            temp.u = a;
            temp.v = b;
            temp.cost = c;
            g.pb(temp);
        }
        printf("Case #%d : ", t++);
        if(!kruskal() )
            printf("No way\n");
        else {
            fCost = cost;
            sCost = 999999;
            for(i=0 ; i<road.size() ; i++) {
                for(j=0 ; j<g.size() ; j++) {
                    if(road[i].u == g[j].u && road[i].v == g[j].v && road[i].cost == g[j].cost) {
                        g[j].cost = 999999;
                        if(kruskal()) {
                            if(cost < sCost) {
                                sCost = cost;
                            }
                            g.pop_back();
                            g.pb(road[i]);
                        }
                    }
                }
            }
            if(sCost == 999999)
                printf("No second way\n");
            else
                printf("%d\n", sCost);
        }
    }
    return 0;
}
