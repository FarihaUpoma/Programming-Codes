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

int visit[500][500], cnt, n, m, g[2510][3];
char a[500][500];

void bfs(int x, int y, char k)
{
    int xx, yy, i, tx, ty;
    queue <int> q1,q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
	//a[x][y] = '.';
    cnt=1;
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
            if( a[tx][ty]== k && visit[tx][ty]==0) {
                a[tx][ty]= '.';
                visit[tx][ty]= 1;
                q1.push(tx);
                q2.push(ty);
                cnt++;
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out1.txt", "w", stdout);


    int i, k, j, temp, t=1;
    while(scanf("%d %d", &n, &m) && (n || m))
    {
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);

        memset(visit, 0, sizeof(visit));
        k=0;
        for(i=0 ; i<n  ; i++) {
            for(j=0 ; j<m ; j++) {
                if( a[i][j] != '.') {
                    bfs(i, j, a[i][j]);
                    g[k][0]= a[i][j];
                    g[k][1]= cnt;
					a[i][j] = '.';
                    k++;
                }
            }
        }

        for(i=0 ; i<k-1 ; i++) {
            for(j=0 ; j<k-i ; j++) {
                if( g[j][1] < g[j+1][1] ) {
                    temp= g[j][1];
                    g[j][1]= g[j+1][1];
                    g[j+1][1]= temp;
                    temp= g[j][0];
                    g[j][0]= g[j+1][0];
                    g[j+1][0]= temp;
                }
                else if( g[j][1] == g[j+1][1]) {
                    if( g[j][0] > g[j+1][0]) {
                       
                        temp= g[j][0];
                        g[j][0]= g[j+1][0];
                        g[j+1][0]= temp;
                    }
                }
            }
        }
        printf("Problem %d:\n", t++);
        for(i=0 ; i<k ; i++) {
            printf("%c %d\n", g[i][0], g[i][1]);
        }
        memset(g, 0, sizeof(g));
    }
    return 0;
}
