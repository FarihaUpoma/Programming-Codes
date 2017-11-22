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
    bool operator < (const edge & p ) const
    {
        return cost < p.cost;
    }
};

int s, c, par[1000], cost, vis[500];
vector <edge> g;
map <string , int> mp;
bool pos;

int findPar(int u)
{
    if(u==par[u])
        return u;
    else
        return par[u] = findPar(par[u]);
}

void kruskal()
{
    int i, u, v, cnt =0;
    sort(g.begin(), g.end());
    for(i=1 ; i<=s ; i++) {
        par[i] = i;
    }
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if( u!=v) {
            //vis[g[i].u]]=vis[g[i].v]]= 1;
            par[u] = v;
            cost += g[i].cost;
            cnt++;
        }
    }
    if(cnt < s-1) pos = false;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, w;
    char a[20], b[20];
    while(scanf("%d %d", &s, &c)) {
        if(s==0 && c==0)
            break;
        pos = true;
        cost = 0;
        g.clear();
        mp.clear();
        mem(par, 0);
        mem(vis,0);

        for(i=1 ; i<=s ; i++) {
            scanf("%s", a);
            mp[a] = i;
        }
        for(i=0 ; i<c ; i++) {
            scanf("%s %s %d", a, b, &w);
            edge temp;
            temp.u = mp[a];
            temp.v = mp[b];
            temp.cost = w;
            g.pb(temp);
        }
        scanf("%s", a);
        kruskal();
        if(pos)
            printf("%d\n", cost);
        else
            printf("Impossible\n");
    }
    return 0;
}
