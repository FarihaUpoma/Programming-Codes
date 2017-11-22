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
map <string , int> mp;
map <string, int> :: iterator it;
//map <int, string> mm;
//map <int, string> :: iterator im;

char mm[1000][5];

int visit[1000], cost[1000], p[1000], g[1000][1000], track[1000];

void bfs(int x, int y, int n)
{
    int u, i;
    memset(visit,0 ,sizeof(visit));
    memset(p, 0, sizeof(p));
    queue <int> q;
    visit[x]=1;
    cost[x]=0;
    q.push(x);
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        for(i=1 ; i<=n ; i++) {
            if(g[u][i]==1 && visit[i]==0) {
                visit[i]= 1;
                cost[i]= cost[u]+1;
                q.push(i);
                p[i]= u;
                if(i==y) break;
            }
        }
        if(i==y) break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, k, i, x, y, j, blank=0;
    while(scanf("%d", &t)!=EOF)
    {
        k=1;
        for(i=0 ; i<t ; i++) {
            scanf("%s %s", a, b);
            if(mp.find(a) == mp.end() ) {
                mp[a]= k;
                strcpy( mm[k], a);
                //printf("%s\n", mm[k]);
                k++;
            }
            if(mp.find(b) == mp.end() ) {
                mp[b]= k;
                strcpy( mm[k], b);
                k++;
            }
            g[ mp[a] ][ mp[b] ]= g[ mp[b] ][ mp[a] ]=1;

        }
        scanf("%s %s", a, b);
        bfs( mp[a], mp[b], k );

        if(blank==1) printf("\n");
        blank= 1;

        for(i=0 ; i<=k ; i++) for(j=0 ; j<=k ; j++) g[i][j]=g[j][i]=0;

        if( p[ mp[b] ]==0) printf("No route\n");
        else {
            x= mp[a];
            y= mp[b];
            k=0;
            while(1) {
                track[k++]= y;
                if(y==x) break;
                y= p[y];
            }
            //for(i=0 ; i<k ; i++) printf("%d ", track[i]);printf("\n");
            for(i=k-1 ; i>0 ; i--) {
                printf("%s %s\n", mm[track[i]], mm[track[i-1]]);
            }
        }

        mp.clear();
    }
    return 0;
}
