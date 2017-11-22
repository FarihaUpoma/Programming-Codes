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

int cnt, n, m;
char a[50][50];

void fill(int x, int y, char c)
{
    int xx, yy, tx, ty, i;
    queue <int> q1, q2;
    a[x][y]=a[x][y+m]='1';
    //q1.push(x);
    //q2.push(y);
    q1.push(x);
    q2.push(y+m);
    while(!q1.empty() ) {
        xx= q1.front(), q1.pop();
        yy= q2.front(), q2.pop();
        for(i=0 ; i<4 ;  i++) {
            tx= dx[i]+xx;
            ty= dy[i]+yy;
            if(tx<0 || tx>=n || ty<0 || ty>=2*m) continue;
            if( a[tx][ty]==c) {
                a[tx][ty]=a[tx][ty+m]=a[tx][ty-m]='1';
                q1.push(tx);
                q2.push(ty);
            }
        }
    }
}

void bfs(int x, int y, char c)
{
    int xx, yy, tx, ty, i;
    queue <int> q1, q2;
    a[x][y]=a[x][y+m]='1';
    //q1.push(x);
    //q2.push(y);
    q1.push(x);
    q2.push(y+m);
    cnt=1;
    while( !q1.empty() ) {
        xx= q1.front(), q1.pop();
        yy= q2.front(), q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= dx[i]+xx;
            ty= dy[i]+yy;
            if(tx<0 || tx>=n || ty<0 || ty>=2*m) continue;
            if(a[tx][ty]==c ) {
                a[tx][ty]=a[tx][ty+m]=a[tx][ty-m]= '1';
                q1.push(tx);
                q2.push(ty);
                cnt++;
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r", stdin);
    //freopen("fariha.txt","r", stdin);

    int i, j, k, max, x, y;
    char c;
    while(scanf("%d %d", &n, &m)!=EOF) {
        memset(a, 0, sizeof(a));
        for(i=0 ; i<n ; i++) {
            scanf("%s", a[i]);
        }
        scanf("%d %d", &x, &y);
        c= a[x][y];
        for(k=0 ; k<n ; k++) {
            for(i=m, j=0 ; j<m ; i++, j++)
                a[k][i]= a[k][j];
        }
        //printf("%d %d %c\n%d %d %c\n", x, y, a[x][y], x, y+m, a[x][y+m]);
        fill(x, y, a[x][y]);
        max=0;
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<2*m ; j++) {
                if( a[i][j]==c) {
                    //printf("%d %d %c\n", i, j, c);
                    bfs(i, j, c);
                    if(cnt>max) max=cnt;
                }
            }
        }
        //for(i=0 ; i<n ; i++) printf("%s\n", a[i]);
        printf("%d\n", max);
    }
    return 0;
}
