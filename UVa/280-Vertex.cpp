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

vector <int> g[110];
int res[105];

int visit[110], c;

void bfs(int s)
{
    int u, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q;
    q.push(s);
    c=0;
    while( ! q.empty() ) {
        u= q.front();
        q.pop();
        for(i=0 ; i<g[u].size() ; i++) {
            if( visit[ g[u][i] ]==0) {
                visit[ g[u][i] ]=1;
                c++;
                q.push( g[u][i] );
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, p, q, t, s, i, j;
    while(scanf("%d", &n) && n) {
        while(scanf("%d", &p) && p) {
            while(scanf("%d", &q) && q) {
                g[p]. push_back(q);
            }
        }

        scanf("%d", &t);
        while(t--) {
            scanf("%d", &s);
            bfs(s);
            printf("%d", n-c);
            for(i=1 ; i<=n ; i++) {
                if( visit[i]==0) {
                    printf(" %d", i);
                }
            }
            printf("\n");
        }
        for(i=0 ; i<=n ; i++) g[i].clear();
    }
    return 0;
}
