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

map <int, int> mp;
map <int, int> :: iterator it;
vector <int> g[35000];
int v[40000], cnt, n;

void bfs(int s)
{
    int u, i;
    queue <int> q;
    v[s]=1;
    q.push(s);
    cnt=1;
    while( !q.empty() ) {
        u= q.front(), q.pop();
        for(i=0 ; i<g[u].size() ; i++) {
            if(v[ g[u][i] ]==0) {
                v[ g[u][i] ]=1;
                q.push( g[u][i] );
                cnt++;
            }
        }
    }
}

int main()
{
    int t, m, i, a, b, max;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        memset(v, 0, sizeof(v));

        for(i=0 ; i<m ; i++) {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(max=0, i=1 ; i<=n ; i++) {
            if(v[i]==0) {
                bfs(i);
                if(cnt>max) max= cnt;
            }
        }
        printf("%d\n", max);
        for(i=0 ; i<n ; i++) g[i].clear();
    }
    return 0;
}
