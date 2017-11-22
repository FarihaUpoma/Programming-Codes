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

struct node
{
    int u, cost;
    bool operator < (const node & p) const
    {
        return cost > p.cost;                                 /// it  doesn't matter in this case whether > or < . cz we work with each node exactly once
                                                                            /// in dijkstra, it doesn't matter 'When' as long as the update condition is fulfilled & correct.
    }
};

int d[500], visit[500];
map <string, int> mp;
map <string, int> :: iterator it;
vector <int> g[500], cost[500];

void dijkstra(int s)
{
    int u, v, i;
    mem(visit, 0);
    mem(d, 0);
    d[s] = 999999;
    priority_queue <node> pq;
    node x;
    x.u = s;
    x.cost = d[s];
    pq.push(x);
    while( !pq.empty() ) {
        x = pq.top();
        pq.pop();
        u = x.u;
        if(visit[u]) continue;
        visit[u] = 1;
        //printf("working with %d with cost %d\n", u , d[u]);
        for(i=0 ; i<g[u].size() ; i++) {
            v = g[u][i];
            int tmpCst = min(d[u], cost[u][i]);
            if(d[v] < tmpCst)
                d[v] = tmpCst;
            node a;
            a.u = v;
            a.cost = d[v];
            pq.push(a);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t=1, n, m, i, k, c;
    char a[50], b[50];
    while(scanf("%d %d", &n, &m) && n && m ) {
        k=0;
        for(i=0 ; i<m ; i++) {
            scanf("%s %s %d", a, b, &c);
            if(mp[a] == 0)
                mp[a] = k++;
            if(mp[b] == 0)
                mp[b] = k++;
            g[mp[a]].pb(mp[b]);
            g[mp[b]].pb(mp[a]);
            cost[mp[a]].pb(c);
            cost[mp[b]].pb(c);
        }

        /*for(it= mp.begin() ; it!= mp.end() ; it++) {
            //if(strcmp(*it.first(), "hello")==0) printf("hoise!!!\n");
            std::cout << it->first << " => " << it->second << '\n';
        }*/

        scanf("%s %s", a, b);
        dijkstra(mp[a]);
        printf("Scenario #%d\n%d tons\n\n", t++,d[mp[b]]);
        for(i=0 ; i<n ; i++) {
            g[i].clear();
            cost[i].clear();
        }
        mp.clear();
    }
    return 0;
}
