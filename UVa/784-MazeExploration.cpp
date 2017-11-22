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

int visit[50][100];
char a[50][100];

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q1, q2;
    visit[x][y]=1;
    a[x][y]= '#';
    q1.push(x);
    q2.push(y);
    while (!q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+ dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]==' ' && visit[tx][ty]==0) {
                visit[tx][ty]=1;
                a[tx][ty]= '#';
                q1.push(tx);
                q2.push(ty);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, k, i, l, j;
    scanf("%d", &t);
    getchar();
    while(t--) {
        k=0;
        while(gets(a[k++])) {
            if( strcmp(a[k-1], "_____")==0) break;
        }
        for(i=0 ; i<k ; i++) {
            l= strlen(a[i]);
            for(j=0 ; j<l ; j++) {
                if( a[i][j]=='*') {
                    bfs(i, j);
                    break;
                }
            }
            if(j<l) break;
        }
        for(i=0 ; i<k ; i++) printf("%s\n", a[i]);
        memset(a, 0, sizeof(a));
    }
}
