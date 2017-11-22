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

int par[1000], a[1000][2], p;
vector <edge> g;
priority_queue <double> pq;

int findPar(int u)
{
    if(par[u] == u)
        return u;
    else
        return par[u] = findPar(par[u]);
}

void kruskal()
{
    int i, u, v, cnt=0;
    for(i=1 ; i<=p ; i++) {
        par[i] = i;
    }
    sort(g.begin(), g.end());
    for(i=0 ; i<g.size() ; i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
            //printf("%d %d %.3lf\n", g[i].u, g[i].v, g[i].cost);
            par[u] = v;
            pq.push(g[i].cost);
            cnt++;
            if(cnt == p-1)
                break;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int tCase, s, i, j;
    double dis, x;
    scanf("%d", &tCase);
    while(tCase--) {

        g.clear();
        mem(a, 0);
        mem(par, 0);

        scanf("%d %d", &s, &p);
        for(i=1 ; i<=p ; i++) {
            scanf("%d %d", &a[i][0], &a[i][1]);
        }
        for(i=1 ; i<=p ; i++) {
            for(j=i+1 ; j<=p ; j++) {
                dis = sqrt( (a[i][0]-a[j][0])*(a[i][0]-a[j][0]) + (a[i][1]-a[j][1])*(a[i][1]-a[j][1]) );
                printf("%lf\n", dis);
                edge temp;
                temp.u = i;
                temp.v = j;
                temp.cost = dis;
                g.pb(temp);
            }
        }
        kruskal();
        for(i=1 ; i<p ; i++) {
            //if( i == s )
                x = pq.top();
                printf("%.2lf\n", x);
            pq.pop();
        }
        printf("%.2lf\n", x);
    }
    return 0;
}
