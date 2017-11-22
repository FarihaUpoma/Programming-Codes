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

char a[105][300];
int b[105][200], visit[110], n, g[110][110];

void bfs(int k)
{
    int u, i, s;
    memset(visit, 0, sizeof(visit));
    queue <int> q;
    s= k+1;
    if(k==n) s=1;
    visit[s]=1;
    q.push(s);
    while( !q.empty() ) {
        u= q.front();
        q.pop();
        for(i=1 ; i<=n ; i++) {
            if(i==k) continue;
            else if( g[u][i]==1 && visit[i]==0) {
                visit[i]=1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int k, i, m, f, c;
    while(scanf("%d", &n) && n)
    {
        getchar();
        k=0;
        while(gets(a[k++]))
        {
            if( strcmp(a[k-1], "0")==0) break;
        }
        int j;
        char *p;
        for(i=0 ; i<k ; i++) {
            p= strtok(a[i], " ");
            j=0;
            while(p) {
                b[i][j++]= atoi(p);
                p= strtok(NULL, " ");
            }
            for(m=1 ; m<j ; m++) {
                g[ b[i][0] ][ b[i][m] ]= g[ b[i][m] ][ b[i][0] ]=1;
            }
        }
        c=0;
        for(i=1 ; i<=n ; i++) {
            bfs(i);
            f=0;
            //for(j=1; j<=n ; j++) printf("%d ", visit[j]);printf("\n");
            for(j=1 ; j<=n ; j++) {
                if( visit[j]==0) f++;
            }
            if(f>1) c++;
        }
        printf("%d\n", c);
        memset(g, 0, sizeof(g));
    }
    return 0;
}
