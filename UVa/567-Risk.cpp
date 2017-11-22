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

int g[25][25], visit[25], cost[25];

void bfs(int s)
{
    int u, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q;
    visit[s]=1;
    cost[s]=0;
    q.push(s);
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        for(i=1 ; i<=20 ; i++) {
            if(g[u][i]==1 && visit[i]==0) {
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

    int t=0, i, n, m, q, a, b, k=1, w=1;
    while(scanf("%d", &n)!=EOF) {
        for(i=0 ; i<n ; i++) {
            scanf("%d", &m);
            g[k][m]=g[m][k]=1;
        }
        t++;
        k++;
        if(t==19) {
            t=0;
            k=1;
            printf("Test Set #%d\n", w++);
            scanf("%d", &q);
            for(i=0 ; i<q ; i++) {
                scanf("%d %d", &a, &b);
                bfs(a);
                printf("%2d to %2d: %d\n", a, b, cost[b]);
            }
            memset(cost, 0, sizeof(cost));
            memset(g, 0, sizeof(g));
            printf("\n");
        }
    }
    return 0;
}
