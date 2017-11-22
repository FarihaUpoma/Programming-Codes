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

int dx[6]= {-1, 0, 1, 0, -1, 1};
int dy[6]= {0, -1, 0, 1, -1, 1};

int visit[250][250], f, n;
char a[250][250];

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i;
    memset(visit, 0, sizeof(visit));
    queue <int>q1, q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    f=0;
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop(); q2.pop();
        for(i=0 ; i<6 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]=='w' && visit[tx][ty]==0) {
                visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
                if( ty==n-1) {
                    f=1;
                    break;
                }
            }
        }
        if(f==1) break;
    }
}

int main()
{
    int i, t=1;
    while(scanf("%d", &n) && n)
    {
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);
        for(i=0 ; i<n ; i++) {
            if( a[i][0]=='w') {
                bfs(i, 0);
                if(f==1)
                    break;
            }
        }
        if(f==1) printf("%d W\n", t++);
        else printf("%d B\n", t++);
        memset(a, 0, sizeof(a));
    }
    return 0;
}
