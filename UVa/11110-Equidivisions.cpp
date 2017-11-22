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

char a[110][2200];
int b[110][2200], g[110][110], cnt, visit[110][110], v[110], n;

void bfs(int x, int y, int k)
{
    int xx, yy, tx, ty, i;
    queue <int> q1,  q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    cnt=1;
    while(!q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop(); q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+ dx[i];
            ty= yy+ dy[i];
            if( tx<1 || tx>n || ty<1 || ty>n) continue;
            if( g[tx][ty]==k && visit[tx][ty]==0) {
                visit[tx][ty]=1;
                g[tx][ty]=0;
                q1.push(tx);
                q2.push(ty);
                cnt++;
            }
        }
    }
    //printf("%d\n", cnt);
}

int main()
{
    int i, j, f;
    while(scanf("%d", &n) && n)
    {
        getchar();
        for(i=0 ; i<n-1 ; i++) {
            gets(a[i]);
        }
        char *p;
        for(i=0 ; i<n-1 ; i++) {
            j=0;
            p= strtok(a[i], " ");
            while(p) {
                b[i][j++]= atoi(p);
                p= strtok(NULL, " ");
            }
        }
        for(i=0 ; i<n-1 ; i++) {
            for(j=0 ; b[i][j] ; j= j+2) {
                g[ b[i][j] ][ b[i][j+1] ]= i+1;
            }
        }
        for(i=1 ; i<=n ; i++) {
            for(j=1 ; j<=n ; j++) {
                if(g[i][j]==0) {
                    //printf("0 chilo %d %d\n", i, j);
                    g[i][j]=n;
                }
            }
        }
        /*for(i=1 ; i<=n ; i++) {
            for(j=1 ; j<=n ; j++)
                printf("%d ", g[i][j]);
            printf("\n");
        }*/

        memset(v, 0, sizeof(v));
        memset(visit, 0, sizeof(visit));

        for(i=1 ; i<=n ; i++) {
            for(j=1 ; j<=n ; j++) {
                if( g[i][j] !=0 && v[ g[i][j] ]==0) {
                    v[ g[i][j] ]=1;
                    bfs(i, j, g[i][j]);
                    if(cnt!=n) break;
                }
            }
            if(cnt!=n) break;
        }
        if(cnt!=n) printf("wrong\n");
        else {
            f=0;
            for(i=1 ; i<=n ; i++) if(v[i]==0) f=1;
            if(f==0) printf("good\n");
            else printf("wrong\n");
        }
        memset(g, 0, sizeof(g));
    }
    return 0;
}
