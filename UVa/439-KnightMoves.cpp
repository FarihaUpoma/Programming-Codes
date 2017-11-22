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

char a[5],b[5];

int visit[10][10], cost[10][10];

void bfs(int x, int y, int tr, int tc)
{
    int xx, yy, i, j;
    memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int> q2;
    visit[x][y]=1;
    cost[x][y]=0;
    q1.push(x);
    q2.push(y);
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        i= xx-1; j= yy+2;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx+1;j= yy+2;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx+2; j= yy+1;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx+2; j= yy-1;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx-1; j= yy-2;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx+1; j= yy-2;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx-2; j=yy+1;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        i= xx-2; j= yy-1;
        if(visit[i][j]==0 && (i>0 && i<9) && (j>0 && j<9) ) {
            visit[i][j]=1;
            cost[i][j]= cost[xx][yy]+1;
            q1.push(i);
            q2.push(j);
        }
        if( i== tr && j==tc) break;
    }
}

int main()
{
    int irow, trow, icol, tcol;
    while(scanf("%s %s", a, b)!=EOF)
    {
        irow= a[1]-'0';
        icol= a[0]-96;
        //printf("%d %d\n", irow, icol);
        trow= b[1]-'0';
        tcol= b[0]-96;
        bfs(irow, icol, trow, tcol);
        printf("To get from %s to %s takes %d knight moves.\n",a, b, cost[trow][tcol]);
    }
    return 0;
}
