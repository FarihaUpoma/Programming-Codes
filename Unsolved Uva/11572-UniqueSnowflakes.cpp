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

map <int, int> mp;
int a[10000], g[10000];

int main()
{
    int t, n, x, cnt, m, max, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
            if( mp[ a[i] ] == 0) {
                mp[ a[i] ] = 1;
                g[i] = 1;
            }
            else {
                mp[ a[i] ]++;
                g[i] = mp[ a[i] ];
            }
        }
        for(i=0 ; i<n ; i++) {
                printf("%d ", g[i]);
        }
        printf("\n");



        mp.clear();
    }
    return 0;
}
