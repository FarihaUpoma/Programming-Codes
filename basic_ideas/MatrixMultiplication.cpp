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

int a[1000][1000], b[1000][1000], c[1000][1000];

int main()
{
    int n, m, p, q, i, j, k;
    scanf("%d %d", &n, &m);
    for(i=0 ; i<n ; i++)
        for(j=0 ; j<m ; j++)
            scanf("%d", &a[i][j]);
    scanf("%d %d", &p, &q);
    for(i=0 ; i<p ; i++)
        for(j=0 ; j<q ; j++)
            scanf("%d", &b[i][j]);
    memset(c, 0, sizeof(c));
    for(i=0 ;i<n ; i++) {
        for(k=0 ; k<q ; k++) {
            for(j=0 ; j<m ; j++) {
                c[i][k] += a[i][j]*b[j][k];
            }
        }
    }
    printf("%d %d\n\n", n, q);
    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<q ; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
