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

int n, visit[105];
double g[105][105], b[105][2], res;

struct Node {
    int u;
    double cost;
    bool operator < (Node a) const
    {
        return cost > a.cost;
    }
};

void prim(int x)
{
    int i;
    memset(visit, 0, sizeof(visit));
    priority_queue <Node > pq;
    Node u;
    u.u= x;
    u.cost=0;
    pq.push(u);
    res=0;
    while( !pq.empty() ) {
        u= pq.top(), pq.pop();
        if(visit[u.u]==1) continue;
        visit[u.u]= 1;
        res += u.cost;
        for(i=0 ; i<n ; i++) {
            if( visit[i]==1) continue;
            Node v;
            v.u= i;
            v.cost= g[u.u][i];
            pq.push(v);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, i, j;
    double dis;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i=0 ; i<n ; i++)
            scanf("%lf %lf", &b[i][0], &b[i][1]);
        for(i=0 ; i<n ; i++) {
            for(j=i+1 ; j<n ; j++) {
            dis= sqrt((b[i][0]-b[j][0])*(b[i][0]-b[j][0]) + (b[i][1]-b[j][1])*(b[i][1]-b[j][1]));
            g[i][j]=g[j][i]= dis;
            }
        }
        /*for(i=0 ; i<n ; i++) {
            for(j=0 ; j<n ; j++)
                printf("%.2lf ", g[i][j]);
            printf("\n");
        }*/
        prim(0);
        printf("%.2lf\n", res);
        if(t>0) printf("\n");
    }
    return 0;
}
