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

int n, m, v[25][10005], keep[25][10005], a[25], g[25];

void KnapSack()
{
    memset(v, 0, sizeof(v));
    memset(keep, 0, sizeof(keep));
    memset(g, 0, sizeof(g));
    int i, j, x;
    for(i=1 ;  i<=n ; i++) {
        v[0][i]=0;
        keep[0][i]=0;
    }
    for(i=1 ; i<=m ; i++) {
        for(j=1 ; j<=n ; j++) {
            if( a[i] > j) {
                v[ i ][ j ]= v[i-1][j];
                keep[i][j]= 0;
            }
            else if( a[i] == j) {
                v[i][j]= a[i];
                keep[i][j]= 1;
            }
            else {
                x= j- a[i];
                x= v[i-1][x]+ a[i];
                //printf("x=%d\n", x);
                if( x> v[i-1][j] && x<=j) {
                    v[i][j]= x;
                    keep[i][j]=1;
                }
                else if(a[i]>=v[i-1][j]){
                    v[i][j]= a[i];
                    keep[i][j]=1;
                }
                else {
                    v[i][j]= v[i-1][j];
                    keep[i][j]=0;
                }
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int j, i, w, sum;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        for(i=1 ; i<=m ; i++) {
            scanf("%d", &a[i]);
        }
        KnapSack();

        i=m;
        w= n;

        while(i) {

            if( keep[i][w]==1) {
                w= w- a[i];
                g[i]= -1;
            }
            i--;
        }
        for(sum=0, i=1 ; i<=m ; i++) {
            if( g[i]==-1) {
                printf("%d ", a[i]);
                sum= sum+ a[i];
            }
        }
        printf("sum:%d\n", sum);
    }
    return 0;
}
