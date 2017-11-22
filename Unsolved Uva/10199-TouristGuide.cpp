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

char a[50], b[50], q[200][50];
int g[300][300], n, visit[150];
map <string, int> mp;
map <string, int> :: iterator it;

void bfs(int k)
{
    int s, u, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q;
    s= k+1;
    if(k==n-1) s=1;
    visit[s]=1;
    q.push(s);
    while(! q.empty() ) {
        u= q.front();
        q.pop();
        for(i=0 ; i<n ; i++) {
            if(i==k) continue;
            if( g[u][i]==1 && visit[i]==0) {
                visit[i]=1;
                q.push(i);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int k, i, f, m, t=1;
    while(scanf("%d", &n) && n)
    {
        if(t>1) printf("\n");
        k=0;
        for(i=0 ; i<n ; i++) {
            scanf("%s", a);
            mp [a] = k;
            k++;
        }
        //for(it=mp.begin() ; it!=mp.end() ; it++) printf("%s %d\n", it->first.c_str(), it->second);
        scanf("%d", &m);
        for(i=0 ; i<m ; i++) {
            scanf("%s %s", a, b);
            g[ mp[a] ][ mp[b] ]= g[ mp[b] ][ mp[a] ]=1;
        }
        k=0;
        for(it=mp.begin() ; it!= mp.end() ; it++) {
            //printf("mp %d\n", it->second);
            bfs( it->second);
            f=0;
            for(i=0 ; i<n ; i++) {
                if( visit[i]==0) f++;
            }
            if(f>1) {
                strcpy( q[k++], it->first.c_str());
                //printf("cam %s\n", it->first.c_str());
            }
        }
        printf("City map #%d: %d camera(s) found\n", t++,k);
        for(i=0 ; i<k ; i++) {
            printf("%s\n", q[i]);
        }
        mp.clear();
        memset(g, 0, sizeof(g));
    }
    return 0;
}
