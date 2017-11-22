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

int visit[1000],  pi[1000], g[1000][1000], k, track[1000];
map <char, int> mp;

char mm[1000][100];

void bfs(int x, int y)
{
    int u, v;
    memset(visit, 0, sizeof(visit));
    memset(pi, 0, sizeof(pi));                      ///doesn't matter!
    queue <int> q;
    visit[x]=1;
    q.push(x);
    while ( !q.empty() ) {
        u= q.front();
        q.pop();
        for(v=0 ; v<k ; v++) {
            if( g[u][v]== 1 && visit[v]==0) {
                visit[v]=1;
                q.push(v);
                pi[v]=u;
                if(v==y) break;
            }
        }
        if(v==y) break;
    }
}

int main()
{
    int t, n, q, i, x, y, p, j;
    char a[100], b[100];
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        k=0;
        for(i=0 ; i<n ; i++) {
            scanf("%s %s" , a, b);
            if( mp.find(a[0]) == mp.end() ) {
                mp[a[0]]= k;
                strcpy( mm[k], a);
                k++;
            }
            if( mp.find(b[0]) == mp.end() ) {
                mp[b[0]]= k;
                strcpy( mm[k], b);
                k++;
            }
            g[ mp[a[0]] ][ mp[b[0]] ]= g[ mp[b[0]] ][ mp[a[0]] ]= 1;
        }
        //for(i=0 ; i<k ; i++) printf("%s\n", mm[i]);
        for(i=0 ; i<q ; i++) {
            scanf("%s %s", a, b);
            bfs( mp[a[0] ], mp[b[0] ]);
            x= mp[a[0]];y=mp[b[0]];p=0;
            while(1) {
                track[p++]= y;
                if(y==x) break;
                y= pi[y];
            }
            for(j=p-1 ; j>=0 ; j--) printf("%c", mm[ track[j] ][0]);
            printf("\n");
        }
        if(t>0) printf("\n");
        memset(g, 0, sizeof(g));
        mp.clear();
    }
    return 0;
}
