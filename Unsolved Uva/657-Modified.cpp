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

queue <int> q1,q2;
int visit[60][60], dott[100], dot;
char a[60][60];

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

void bbfs(int x, int y)
{
    int xx, yy, tx, ty, i;

    queue <int> q11, q22;
    visit[x][y]=1;
    a[x][y]='#';
    q1.push(x);
    q2.push(y);
    q11.push(x);
    q22.push(y);
    while(!q11.empty() ) {
        xx= q11.front();
        yy= q22.front();
        q11.pop();
        q22.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]=='X' && visit[tx][ty]==0) {
                a[tx][ty]= '#';
                visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
                q11.push(tx);
                q22.push(ty);
            }
        }
    }
}

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i;
    //queue <int> q1, q2;
    visit[x][y]=1;
    a[x][y]='.';
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
            if( (a[xx][yy] == '#' || a[xx][yy]=='*') && a[tx][ty]=='*' && visit[tx][ty]==0) {
                a[tx][ty]= '.';
                visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
            }
            else if(a[xx][yy] !='#' && a[tx][ty]=='X' && visit[tx][ty]==0 ) {
                bbfs(tx, ty);
                dot++;
                //printf("i= %d j= %d dot= %d\n", tx, ty, dot);
            }
        }
    }
}

int main()
{
    int m, n, i, j, k, w=1;
    while(scanf("%d %d", &m, &n) && m && n)
    {
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);

        memset(visit, 0, sizeof(visit));
        k=0;
        printf("\n");
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if( a[i][j]=='*') {
                    bfs(i,j);
                    for(int p=0 ; p<n ; p++) printf("%s\n", a[p]);printf("\n");
                    dott[k++]= dot;
                    printf("dot = %d\n", dot);
                }
            }
        }
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                if(a[i][j]=='X') {
                    bbfs(i,j);
                    dott[k++]= 1;
                }
            }
        }
        sort(dott, dott+k);
        printf("Throw %d\n%d", w++, dott[0]);
        for(i=1 ; i<k ; i++) printf(" %d", dott[i]);
        printf("\n\n");
    }
    return 0;
}
