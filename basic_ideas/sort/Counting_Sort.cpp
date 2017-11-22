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

int a[100], b[100], c[100], n;

void counting_sort(int a[], int b[], int c[], int p,int k)
{
    int i, j;
    for(i=p ; i<=k ; i++) c[i] = 0;
    for(i=1 ; i<=n ; i++) c[ a[i] ] = c[ a[i] ] + 1;
    for(i=p ; i<=k ; i++) c[i] = c[i] + c[i-1];
    for(j=n ; j>0 ; j--) {
        b[ c[ a[j] ] ] = a[j];
        c[ a[j] ] = c[ a[j] ]-1;
        /*for(i=1 ; i<=n ; i++) printf("%d ", b[i]);
        printf(":B\n");
        for(i=0 ; i<=k ; i++) printf("%d ", c[i]);
        printf(":C\n");*/
    }
}

int main()
{
    int i, max=0, min = 999999;
    scanf("%d", &n);
    for(i=1 ; i<=n ; i++) {
        scanf("%d", &a[i]);
        if(a[i]>max) max = a[i];
        if(a[i]<min) min = a[i];
    }
    counting_sort(a, b, c, min,max);
    for(i=1 ; i<=n ; i++)
        printf("%d ", b[i]);
    return 0;
}
