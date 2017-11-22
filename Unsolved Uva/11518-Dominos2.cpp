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

int visit[10009], dom, n;
vector <int> g[10009];
queue <int> q;

void bfs()
{
    int u, i;
    //memset(visit, 0, sizeof(visit));
    //queue <int> q;
    //if(visit[s]==1) dom--;
    //printf("dom=%d\n", dom);
    //visit[s]=1;
    //q.push(s);
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        for(i=0 ; i<g[u].size() ; i++) {
            if( visit[ g[u][i] ]==0) {
                //printf("falling %d\n", i);
                visit[ g[u][i] ]=1;
                //g[u][i]=0;
                q.push( g[u][i] );
                dom++;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int t, m, l, x, y, s, i, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &l);
        while(m--) {
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
        }
        //for(i=1 ; i< g[i].size() ; i++) printf("%d")
        dom=0;
        memset(visit, 0, sizeof(visit));
        while(l--) {
            scanf("%d", &s);
            if(visit[s]==0) {
                q.push(s);
                dom++;
            }
            visit[s]=1;
        }
        bfs();
        printf("%d\n", dom);
        for(i=1 ; i<=n ; i++) g[i].clear();
    }
    return 0;
}
