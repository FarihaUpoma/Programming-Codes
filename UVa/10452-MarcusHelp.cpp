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

int dx[3]= {-1, 0, 0};
int dy[3]= {0, -1, 1};

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

#define mem(a,n) memset(a, n, sizeof(a))

char a[] = "IEHOVA#";
char g[10][10];

void bfs(int x, int y, int m, int n)
{
    int k, xx, yy, tx, ty, i;
    queue <int> q1, q2;
    q1.push(x);
    q2.push(y);
    k = 0;
    while(!q1.empty() ) {
        //printf("while\n");
        xx = q1.front() , q1.pop();
        yy = q2.front() , q2.pop();
        //printf("xx=%d yy=%d\n", xx, yy);
        for(i=0 ; i<3 ; i++) {
            tx = xx + dx[i];
            ty = yy + dy[i];
            if(tx<0 || ty<0 || tx>=m || ty>=n) continue;
            //printf("tx=%d ty=%d\n", tx, ty);
            //printf("%d %d %c %c\n", tx, ty, a[k], g[tx][ty]);
            if( g[tx][ty] == a[k]) {
                k++;
                q1.push(tx);
                q2.push(ty);
                if(i==0)
                    printf("forth");
                else if(i==1)
                    printf("left");
                else
                    printf("right");
                if(k<=6) printf(" ");
            }
        }
    }
    printf("\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, m, n, i, j;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d %d", &m, &n);
        for(j=0 ; j<m ; j++) {
            scanf("%s", g[j]);
        }
        for(j=0 ; j<n ; j++) {
            if( g[m-1][j] == '@') {
                bfs( m-1, j, m, n);
                break;
            }
        }
    }
    return 0;
}
