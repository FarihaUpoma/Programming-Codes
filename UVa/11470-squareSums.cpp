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

int a[100][100], sum, s[100];

int main()
{
    int i, j, k, p, f, h, n, x, y, r=1;

    while(scanf("%d", &n) && n)
    {
        for(i=1 ; i<=n ; i++) {
            for(j=1 ; j<=n ; j++)
                scanf("%d", &a[i][j]);
        }
        x= (n/2)+1;

        y=0;
        p=1;

        for(i=1 , j=n, h=2 ; i<x ; i++, j--, p++, h=h+2) {
            for(sum=0,f=0,k=1 ; k<=j ; k++) {
                if(i==k) f=1;
                if(f==1) sum += a[i][k]+ a[k][i]+ a[j][k]+ a[k][j];
            }
            s[y]= sum- a[i][i]-a[j][j]-a[j][i]-a[i][j];
            y++;
        }
        if(n%2 != 0) s[y++] = a[x][x];
        printf("Case %d: %d", r++, s[0]);
        for(i=1 ; i<y ; i++) printf(" %d", s[i]);
        printf("\n");
    }
    return 0;
}
