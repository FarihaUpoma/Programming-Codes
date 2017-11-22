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

int dirx[4]= {-1, 0, 0, +1};
int diry[4]= {0, +1, -1, 0};
int visit[102][102];
char a[102][102];

void bfs(int j, int k)
{
    int xx, yy, i, x, y;
    //memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int> q2;
    visit[j][k]=1;
    q1.push(j);
    q2.push(k);
    while(!q1.empty()) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        //printf("1 xx=%d yy=%d a[xx][yy]=%c\n", xx, yy, a[xx][yy]);
        for(i=0 ; i<4 ; i++) {
            x= xx+dirx[i];
            y= yy+diry[i];
            //printf("x= %d y= %d\n", x, y);
            if( (a[x][y] == 'x' || a[x][y]== '@' ) && visit[x][y]==0) {
                //printf("2 xx=%d yy=%d a[xx][yy]=%c\n", xx, yy, a[xx][yy]);
                visit[x][y]=1;
                a[x][y]= '.';
                q1.push(x);
                q2.push(y);
            }
        }
    }
}


int main()
{
    int t, n, i, j, ship, k=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i=0 ; i<n ; i++) {
            scanf("%s", a[i]);
        }
        ship=0;
        memset(visit, 0, sizeof(visit));
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<n ; j++) {
                if( a[i][j]=='x') {
                    bfs(i, j);
                    //printf("i=%d j=%d\n", i, j);
                    ship++;
                }
            }
        }
        printf("Case %d: %d\n",k++, ship);
    }
    return 0;
}
