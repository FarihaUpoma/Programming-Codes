#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int visit[100], cost[100], v, e;
vector<int>g[1009];
void bfs(int s)
{
    memset(visit, 0, sizeof visit);
    queue <int> q;
    int u, i;
    visit[s]=1;
    cost[v]=0;
    q.push(s);
    while( !q.empty() )
    {
        u= q.front();
        q.pop();
        for(i=0 ; i<g[u].size() ; i++)
        {
            if( visit[i]==0 && g[u][i]==1)
            {
                visit[i]=1;
                cost[i]= cost[u]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int  a, b, i, j;
    //vector<int> g[1009];
    scanf("%d %d", &v, &e);
    for(i=0 ; i<e ; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }
    for(i=1 ; i<=v ; i++) {
        printf("%d-> ", i);
        for(j=0 ; j< g[i].size() ; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }

}
