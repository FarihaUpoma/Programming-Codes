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

int dot,dott[100], visit[60][60], v[60][60];
char a[60][60];

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

void bbfs(int x, int y)
{
    int xx, yy, i, tx, ty;
    //memset(v, 0, sizeof(v));
    queue <int> q1, q2;
    v[x][y]= 1;
    visit[x][y]=1;
    q1.push(x);
    q2. push(y);
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]=='X' && v[tx][ty]==0) {
                v[tx][ty]= 1;
                visit[tx][ty]=1;
                a[tx][ty]= '*';
                q1.push(tx);
                q2.push(ty);
            }
        }
    }
}

void bfs(int x, int y)
{
    int xx, yy, i, tx, ty;
    //memset(visit, 0, sizeof(visit));
    queue <int> q1, q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    dot=0;
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<8 ; i++) {
            tx= xx+dirx[i];
            ty= yy+diry[i];
            if( a[tx][ty]== '*' && visit[tx][ty]==0) {
                visit[tx][ty]=1;
                a[tx][ty]= '.';
                q1.push(tx);
                q2.push(ty);
            }
            else if(a[tx][ty]=='X' && visit[tx][ty]==0) {
                //printf("i=%d j=%d dot=%d\n", tx, ty, dot);
                bbfs(tx, ty);
                //visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
                dot++;
            }
        }
    }
    //printf("dot=%d\n", dot);
}

int main()
{
    freopen("input.txt", "r", stdin);

    int m, n, k, i, j, t=1;;
    while(scanf("%d %d", &m, &n) && m && n) {
        for(i=0 ; i<n ; i++) {
            scanf("%s", a[i]);
        }
        memset(visit, 0, sizeof(visit));
        memset(v, 0, sizeof(v));
        k=0;
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if( a[i][j]=='*') {
                    bfs(i, j);
                    dott[k++]= dot;
                }
                else if( a[i][j]=='X') {
                    bbfs(i,j);
                    dott[k++]= 1;
                }

            }
        }
        sort(dott, dott+k);
        printf("Throw %d\n%d",t++, dott[0]);
        for(i=1 ; i<k ; i++) {
            printf(" %d", dott[i]);
        }
        printf("\n");
    }
    return 0;
}
