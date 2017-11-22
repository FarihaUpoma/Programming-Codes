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

int a[310], visit[310], pi[310], track[310];
char b[310][200];
vector <int> g[310];

void bfs(int x, int y)
{
    int u, i, f;
    memset(visit, 0, sizeof(visit));
    memset(pi, 0, sizeof(pi));
    queue <int> q;
    visit[x]= 1;
    q.push(x);
    f=0;
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        for(i=0 ; i<g[u].size() ; i++) {
            if( visit[ g[u][i] ]==0) {
                visit[ g[u][i] ]= 1;
                q.push( g[u][i] );
                pi[ g[u][i] ]=u;
                if( g[u][i] ==y) {
                    f=1;
                    break;
                }
            }
        }
        if(f==1) break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, n, k, x, y, m, j;
    while(scanf("%d", &n)!=EOF)
    {
        for(i=1 ; i<=n ; i++) {
            scanf("%d %s", &a[i], b[i]);
            strcpy( &b[i][0], &b[i][1]);
        }
        for(i=1 ; i<=n ; i++) {
            char *p;
            int j;
            p= strtok(b[i], ",");
            while(p) {
                g[i].push_back( atoi(p));
                p= strtok(NULL, ",");
            }
        }
        /*for(i=1 ; i<=n ; i++) {
            printf("%d -> ", i);
            for(j=0 ; j<g[i].size() ; j++)
                printf("%d ", g[i][j]);
            printf("\n");
        }*/

        scanf("%d", &m);
         printf("-----\n");
        for(i=0 ; i<m ; i++) {
            scanf("%d %d", &x, &y);
            bfs(x, y);

            if(visit[y]==0) printf("connection impossible");
            else {
                k=0;
                while(1) {
                    track[k++]= y;
                    if(y==x) break;
                    y= pi[y];
                }
                printf("%d", track[k-1]);
                for(j=k-2 ; j>=0 ; j--) printf(" %d", track[j]);
            }
            printf("\n");
        }
        for(i=1 ; i<=n ; i++) g[i].clear();
    }
    return 0;
}
