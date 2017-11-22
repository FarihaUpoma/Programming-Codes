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

int visit[210], cost[210];
char g[5][15], a[210][15], b[30];

void bfs(int x, int y, int n)
{
    int u, i, l, c, f, j;
    memset(visit, 0, sizeof(visit));
    memset(cost, 0, sizeof(cost));
    f=0;
    queue <int> q;
    visit[x]= 1;
    cost[x]=0;
    q.push(x);
    while( !q.empty() ) {
        u= q.front();
        l= strlen( a[u] );
        q.pop();
        for(i=0 ; i<n ; i++) {
            if( strlen(a[i])==l) {
                for(c=0,j=0 ; j<l ; j++)
                    if(a[i][j] != a[u][j])
                        c++;
                if(c==1 && visit[i]==0) {
                    visit[i]=1;
                    cost[i]= cost[u]+1;
                    q.push(i);
                    if( strcmp( a[i], a[y])==0) {
                        f=1;
                        break;
                    }
                }
            }
            if(f==1) break;
        }
        if(f==1) break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, k, l, i, x, y;
    scanf("%d", &t);
    k=0;
    while(t--) {
        k=0;
        while(scanf("%s", a[k])) {
            if(a[k][0]=='*') break;
            k++;
        }
        getchar();
        while(gets(b)) {
            l= strlen(b);
            if(l==0) break;
            char *p;
            int j=0;
            p= strtok( b, " ");
            while(p) {
                strcpy( g[j++], p);
                p= strtok(NULL, " ");
            }
            //for(i=0 ; i<j ; i++) printf("g[i]= %s\n", g[i]);
            for(i=0 ; i<k ; i++) {
                if( strcmp(a[i], g[0])==0) x= i;
                if( strcmp(a[i], g[1])==0) y= i;
            }
            //for(i=0 ; i<k ; i++) strcpy( g[i], a[i]);
            bfs(x, y, k);
            printf("%s %s %d\n", a[x], a[y],cost[y]);
        }
        if(t>0) printf("\n");
    }
    return 0;
}
