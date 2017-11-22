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

int visit[110][110], c, row, col;
char a[110][110];

int X[8] = {-1,-1,-1,0, 0, 1, 1, 1,};
int Y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int x, int y)
{
    int xx, yy, i, j;
    memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int> q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    c=0;
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2. front();
        q1.pop();
        q2.pop();
        for(int t=0 ; t<8 ; t++) {
            i= xx+ X[t];
            j= yy+ Y[t];
            if( a[i][j]=='*' && visit[i][j]==0 && (i>=0 && i<row && j>=0 && j<col) ) {
                visit[i][j]=1;
                a[i][j]='.';
                q1.push(i);
                q2.push(j);
                c++;
            }
        }
    }
}

int main()
{
    int i, j, star;

    while(scanf("%d %d", &row, &col) && row && col)
    {
        for(i=0 ; i<row; i++)
            scanf("%s", a[i]);
        for(star=0,i=0 ; i<row; i++) {
            for(j=0 ; j<col ; j++) {
                if( a[i][j]=='*') {
                    bfs( i, j);
                    if(c==0) star++;
                }
            }
        }
        printf("%d\n", star);
    }
    return 0;
}
