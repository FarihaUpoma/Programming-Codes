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

char a[100][100];

int visit[100][100];
int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

void bfs(int x, int y, char c)
{
    int xx, yy, tx, ty, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q1, q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    while( !q1.empty() ) {
        xx= q1.front();
        yy= q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<4 ; i++) {
            tx= xx+dx[i];
            ty= yy+dy[i];
            if( a[tx][ty]==' ' && visit[tx][ty]==0) {
                visit[tx][ty]=1;
                a[tx][ty]= c;
                q1.push(tx);
                q2.push(ty);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int k=0, l, i, ll ,j;
    while(gets(a[k++])!=NULL) {
        l= strlen(a[k-1]);
        if( strcmp(a[k-1], "_____________________________")==0 ) {
            //for(i=0 ; i<k ; i++) printf("%s\n", a[i]);
            //printf("a[0][1]=%c\n", a[0][2]);
            for(i=0 ; i<k ; i++) {
                ll= strlen(a[i]);
                for(j=0 ; j<ll ; j++) {
                    if( !(a[i][j] ==' ' || a[i][j]== 'X' || a[i][j]=='_')) {
                        bfs(i, j, a[i][j]);
                    }
                }
            }
            for(i=0 ; i<k ; i++) printf("%s\n", a[i]);
            k=0;
        }
    }
    return 0;
}
