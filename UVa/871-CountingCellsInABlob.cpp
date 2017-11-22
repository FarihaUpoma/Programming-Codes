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

int visit[50][50], cnt;
char a[50][50];

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i;
    queue <int> q1, q2;
    visit[x][y]= 1;
    a[x][y]= '0';
    q1.push(x);
    q2.push(y);
    cnt=1;
    while (!q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<8 ; i++) {
            tx= xx+dirx[i];
            ty= yy+diry[i];
            if( a[tx][ty]=='1' && visit[tx][ty]==0) {
                a[tx][ty]='0';
                visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
                cnt++;
            }
        }
    }
}

int main()
{
    int t, l, i, max, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", a[0]);
        l= strlen( a[0]);
        for(i=1 ; i<l ; i++)
            scanf("%s", a[i]);
        max=0;
        memset(visit, 0, sizeof(visit));
        for(i=0 ; i<l ; i++) {
            for(j=0 ; j<l ; j++) {
                if( a[i][j]=='1') {
                    bfs(i, j);
                    if(cnt>max) max= cnt;
                }
            }
        }
        printf("%d\n", max);
        if(t>0) printf("\n");
        memset(a, 0, sizeof(a));
    }
    return 0;
}
