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

int b[100], c;
char a[100], g[100][100];
int visit[100][100];

void bfs(int x, int y)
{
    int xx, yy, i, tx, ty;
    memset(visit, 0, sizeof(visit));
    queue <int> q1;
    queue <int> q2;
    visit[x][y]=1;
    q1.push(x);
    q2.push(y);
    c=1;
    //printf("x=%d y=%d %s\n", x, y, g[x]);
    while( !q1.empty() ) {
        xx = q1.front();
        yy = q2.front();
        q1.pop();
        q2.pop();
        for(i=0 ; i<8 ; i++) {
            tx= xx+dirx[i];
            ty= yy+diry[i];

            if( g[tx][ty]=='W' && visit[tx][ty]==0) {
                //printf("i=%d j=%d %s\n", i, j, g[i]);
                c++;
                visit[tx][ty]=1;
                q1.push(tx);
                q2.push(ty);
            }
        }
    }
    printf("%d\n", c);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, l, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", g[0]);
        l= strlen(g[0]);
        for(i=1 ; i<l ; i++)
            scanf("%s\n", g[i]);
        //getchar();
        while(gets(a)) {
            l= strlen(a);
            if(l==0) break;
            char *p;
            int k=0;
            p= strtok(a, " ");
            while(p) {
                b[k++]= atoi(p);
                p= strtok(NULL, " ");
            }
            //printf("%d %d\n", b[k-2], b[k-1]);
            bfs(b[k-2]-1, b[k-1]-1);
            //printf("c=%d\n", c);
        }
        if(t>0) printf("\n");
    }
    return 0;
}
