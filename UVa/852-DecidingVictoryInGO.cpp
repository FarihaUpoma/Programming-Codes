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

int visit[100][100], b, w, wh, bl, st;
char a[100][100];

void bfs(int x, int y)
{
    int xx, yy, tx, ty, i;
    queue <int> q1, q2;
    visit[x][y]=1;
    a[x][y]='1';
    q1.push(x);
    q2.push(y);
    st=1;
    w=0;
    b=0;
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if(tx<0 || tx>8 || ty<0 || ty>8) continue;
            if( a[tx][ty]=='.' && visit[tx][ty]==0) {
                visit[tx][ty]=1;
                a[tx][ty]= '1';
                st++;
                q1.push(tx);
                q2.push(ty);
            }
            else if( a[tx][ty]=='O') w=1;
            else if( a[tx][ty]=='X') b=1;
        }
    }
}

int main()
{
    int t, i, j;
    scanf("%d", &t);
    while(t--) {
        bl=0;
        wh=0;
        for(i=0 ; i<9 ; i++) scanf("%s", a[i]);
        for(i=0 ; i<9 ; i++) {
            for(j=0 ; j<9 ; j++) {
                if( a[i][j]=='O') wh++;
                else if( a[i][j]=='X') bl++;
            }
        }
        //printf("bl %d wh %d\n", bl, wh);
        memset(visit, 0, sizeof(visit));
        for(i=0 ; i<9 ; i++) {
            for(j=0 ; j<9 ; j++) {
                if( a[i][j]=='.') {
                    bfs(i, j);
                    //printf("st %d\n", st);
                    if(w==1 && b==0) wh += st;
                    else if(b==1 && w==0) bl += st;
                }
            }
        }
        printf("Black %d White %d\n", bl, wh);
    }
    return 0;
}
