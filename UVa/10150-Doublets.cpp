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

char g[25145][20], a[20], b[20];

int visit[25145], pi[25145], k, track[25145];

void bfs(int x, int y)
{
    int u, v, lu, lv, i, c;
    memset(visit, 0, sizeof(visit));
    memset(pi, 0, sizeof(pi));
    queue <int> q;
    visit[x]=1;
    q.push(x);
    while( !q.empty() ) {
        u= q.front();
        lu= strlen(g[u]);
        q.pop();
        for(v=0 ; v<k ; v++) {
            lv= strlen(g[v]);
            if( lu==lv) {
                c=0;
                for(i=0 ; i<lu ; i++) {
                    if( g[u][i]!=g[v][i]) c++;
                }
                if( c==1 && visit[v]==0) {
                    visit[v]=1;
                    q.push(v);
                    pi[v]=u;
                    if(v==y) break;
                }
            }
        }
        if(v==y) break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int l, i, x, y, xx, yy, p, t=0;
    while(gets(g[k++])) {
        l= strlen(g[k-1]);
        if(l==0) break;
    }
    //for(i=0 ; i<k ; i++) printf("%s\n", g[i]);
    while(scanf("%s %s", a, b)!=EOF)
    {
        if(t>0) printf("\n");
        t++;
        memset(track, 0, sizeof(track));
        for(i=0 ; i<k ; i++) {
            if( strcmp(a, g[i])==0) {
                x= i;
            }
            if( strcmp( b, g[i])==0) {
                y= i;
            }
        }
        bfs(x, y);
        if(visit[y]==0) printf("No solution.\n");
        else {
            xx= x;
            yy= y;
            p=0;
            while(1) {
                track[p++]= yy;
                if(yy==xx) break;
                yy= pi[yy];
            }
            for(i=p-1 ; i>=0 ; i--) printf("%s\n", g[ track[i] ]);
        }
    }
    return 0;
}
