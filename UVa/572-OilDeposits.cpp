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

int visit[105][105], n, m;
char a[105][105];

void bfs(int x, int y)
{
    int xx, yy, i, j;
    memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int > q2;
    visit[x][y]=1;
    a[x][y]='*';
    q1.push(x);
    q2.push(y);
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        i= xx; j=yy+1;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx;j=yy-1;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx+1;j= yy;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx+1; j= yy+1;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx+1;j=yy-1;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx-1;j= yy;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx-1;j= yy+1;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
        i= xx-1; j= yy-1;
        if( a[i][j]=='@' && visit[i][j]==0 && (i>=0 && i<m && j>=0 && j<n)) {
            visit[i][j]=1;
            a[i][j]='*';
            q1.push(i);
            q2.push(j);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, j, c;
    while(scanf("%d %d", &m, &n) && m)
    {
        for(i=0 ; i<m ; i++)
            scanf("%s", a[i]);
        for(c=0,i=0 ; i<m ; i++) {
            for(j=0 ; j<n ; j++) {
                if( a[i][j]=='@') {
                    bfs(i, j);
                    c++;
                }
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
