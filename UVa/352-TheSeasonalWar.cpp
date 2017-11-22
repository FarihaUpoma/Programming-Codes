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

int t, visit[30][30];
char a[30][30];

void bfs(int x, int y)
{
    int xx, yy, i, j;
    memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int > q2;
    visit[x][y]=1;
    a[x][y]='0';
    q1.push(x);
    q2.push(y);
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        i= xx; j=yy+1;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx;j=yy-1;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx+1;j= yy;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx+1; j= yy+1;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx+1;j=yy-1;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx-1;j= yy;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx-1;j= yy+1;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
        i= xx-1; j= yy-1;
        if( a[i][j]=='1' && visit[i][j]==0) {
            visit[i][j]=1;
            a[i][j]='0';
            q1.push(i);
            q2.push(j);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, count, k=1;
    while(scanf("%d", &t)!=EOF)
    {
        for(i=0 ; i<t ; i++) {
            scanf("%s", a[i]);
        }

        for(count=0,i=0 ; i<t ; i++) {
            for(j=0 ; j<t ; j++) {
                if( a[i][j]=='1') {
                    bfs(i, j);
                    count++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",k++, count);
    }
    return 0;
}
