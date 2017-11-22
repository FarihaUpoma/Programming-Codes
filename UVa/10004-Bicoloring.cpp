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

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int g[205][205], visit[205], col[205], f, n;

void bfs(int s)
{
    int u, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q;
    visit[s]=1;
    col[s]=1;
    q.push(s);
    f=0;
    while( !q.empty() )
    {
        u= q.front();
        q.pop();
        for(i=0 ; i<n ; i++)
        {
            if( g[u][i]==1 && visit[i]==0)
            {
                visit[i]=1;
                col[i]= col[u]*(-1);
                q.push(i);
            }
            else if( g[u][i]==1 && visit[i]==1)
            {
                if(col[i]==col[u]) f=1;
                break;
            }
        }
    }
}

int main()
{
    int l, i, a, b, j;
    while(scanf("%d", &n) && n)
    {
        scanf("%d", &l);
        memset(g, 0, sizeof(g));
        for(i=0 ; i<l ; i++) {
            scanf("%d %d", &a, &b);
            g[a][b]=g[b][a]=1;
        }
        bfs(a);
        if(f==1) printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");
    }
    return 0;
}
