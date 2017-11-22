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

int a[30500], b[600];

int main()
{
    int t, i, n;
    double v, sum, dis;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        sum=0;
        v=0;
        for(i=0 ; i<n ; i++) {
            scanf("%d", &b[i]);
            a[ b[i] ]++;
            if( a[ b[i] ] ==1) {
                sum += b[i];
                v++;
                printf("%d %.2lf\n", b[i],v);
            }
        }
        sum= sum/v;
        printf("%.2lf %.2lf %.2lf\n", sum*v, v, sum);
        dis=0;
        for(i=0 ; i<n ; i++)
            dis += fabs(b[i]-sum);
        printf("%.2lf\n", dis);
        memset(a, 0, sizeof(a));
    }
    return 0;
}
