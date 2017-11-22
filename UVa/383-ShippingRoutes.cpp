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

char a[5], b[5];

map <string, int> mp;

int visit[50], cost[50], g[50][50], m;

void bfs(int s)
{
    int u, i;
    memset( visit, 0, sizeof(visit));
    memset( cost, 0, sizeof(cost));
    queue <int> q;
    visit[s]= 1;
    cost[s]=0;
    q.push(s);
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        for(i=1 ; i<=m ; i++) {
            if( g[u][i]==1 && visit[i]==0) {
                visit[i]=1;
                cost[i]= cost[u]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, i, n, p, ship, k=1;
    scanf("%d", &t);
    printf("SHIPPING ROUTES OUTPUT\n");
    while(t--) {
        scanf("%d %d %d", &m, &n, &p);
        printf("\nDATA SET  %d\n\n", k++);
        for(i=1 ; i<=m ; i++) {
            scanf("%s", a);
            mp[a]= i;
        }
        /*map <string, int> :: iterator it;
        for(it= mp.begin() ; it!= mp. end() ; it++) {
            printf("%s -> %d\n", it->first.c_str(), it->second);
        }*/
        for(i=0 ; i<n ; i++) {
            scanf("%s %s", a, b);
            g[ mp[a] ][ mp[b] ]= g[ mp[b] ][ mp[a] ]=1;
        }
        for(i=0 ; i<p ; i++) {
            scanf("%d %s %s", &ship, a, b);
            bfs( mp[a] );
            if( cost[ mp[b] ]) {
                printf("$%d\n", cost[ mp[b] ]*ship*100);
            }
            else printf("NO SHIPMENT POSSIBLE\n");
        }
        mp.clear();
        memset(g, 0, sizeof(g));
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
