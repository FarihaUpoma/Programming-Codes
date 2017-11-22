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

int n, par[1000], cost;
vector <edge> g;
char a[1000][10];

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
    int i, u, v, cnt = 0;
    sort(g.begin() , g.end() ) ;
    for(i=0 ; i<n ; i++ ) {
        par[i] = i;
    }
    for(i=0 ; i<g.size(); i++) {
        u = findPar(g[i].u);
        v = findPar(g[i].v);
        if(u!=v) {
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

    int tCase, c, i, j, x, y, ini_cost, k;
    scanf("%d", &tCase);
    while(tCase--) {

        ini_cost = 100;
        g.clear();
        cost = 0;

        scanf("%d", &n);
        for(i=0 ; i<n ; i++) {
            scanf("%s", a[i]);
            c = 0;
            for(j=0 ; j<4 ; j++) {
                x = a[i][j]-48;
                y = 58- a[i][j];
                c += min(x,y);
            }
            if(c < ini_cost)
                ini_cost = c;
            //printf("x=%d y=%d c=%d ini_cost=%d\n", x, y, c, ini_cost);
        }
        for(i=0 ; i<n ; i++) {
            for(j=i+1 ; j<n ; j++) {
                c = 0;
                for(k=0 ; k<4 ; k++) {
                    x = abs( a[j][k] - a[i][k] );
                    y = 10 - x;
                    c += min(x, y);
                    //printf("x=%d y=%d c=%d\n", x, y, c);
                }
                edge temp;
                temp.u = i;
                temp.v = j;
                temp.cost = c;
                g.pb(temp);
            }
        }
        kruskal();
        printf("%d\n", cost+ini_cost);
    }
    return 0;
}
