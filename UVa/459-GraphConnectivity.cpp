#include <stdio.h>
#include <string.h>
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

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

char a[10];
int alpha[30], d, visit[30], cost[30], g[30][30];

void bfs(int s)
{
    int u, v;
    //memset(visit, 0, sizeof(visit));
    queue <int> q;
    visit[s]=1;
    cost[s]= 0;
    q.push(s);
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        alpha[u]=1;
        for(v=1 ; v<=d ; v++) {
            if( g[u][v]==1 && visit[v]==0) {
                visit[v]= 1;
                alpha[v]=1;
                cost[v]=cost[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, c, l, i;
    scanf("%d", &t);
    while(t--) {
        memset(alpha, 0, sizeof(alpha));
        memset(g, 0, sizeof(g));
        memset(visit, 0, sizeof(visit));
        scanf("%s", a);
        d= a[0]-64;
        getchar();
        while(gets(a)) {
            l= strlen(a);
            if(l==0) break;
            g[ a[0]-64 ][ a[1]-64 ]= g[a[1]-64][a[0]-64]=1;
        }
        bfs(1);
        for(c=1,i=1 ; i<=d ; i++ ) {
            if( alpha[i]==0) {
                bfs(i);
                c++;
            }
        }
        printf("%d\n", c);
        if(t>0) printf("\n");
    }
    return 0;
}
