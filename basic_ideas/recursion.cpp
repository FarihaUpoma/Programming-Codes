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

int a[1000][5], b[1000];

void p(int n)
{
    if(n==-1) return ;
    p( a[n][2]);
    p( a[n][1]);
    printf("%d\n", n);
    //p(a[n][0]);
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n, i;
    /*a[1][0]=5;a[1][1]=a[1][2]=-1;
    a[5][0]=10;a[5][1]=1;a[5][2]=7;
    a[7][0]=5;a[7][1]=a[7][2]=-1;
    a[10][0]=-1;a[10][1]=5;a[10][2]=20;
    a[20][0]=10;a[20][2]=25;a[20][1]=-1;
    a[21][0]=22;a[21][1]=a[21][2]=-1;
    a[22][0]=25;a[22][1]=21;a[22][2]=-1;
    a[25][0]=20;a[25][1]=22; a[25][2]=27;
    a[27][0]=25;a[27][1]=a[27][2]=-1;
    p(10);*/
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    int max=0, x;
    for(i=0 ; i<n ; i++) {
        scanf("%d", &x);
        if(x>max) max= x;
        b[i]=x;
    }
    for(i=0 ; i<n-1 ; ) {
        if( b[i+2] > b[i] && b[i+2] < b[i+1] && b[i+2]!=b[n-1]) {
            a[ b[i+1] ][0]=a[ b[i] ][0]= b[i+2];
            a[ b[i+2] ][1]= b[i];
            a[ b[i+2] ][2]= b[i+1];
            i=i+3;
        }
        else {
            a[ b[i] ][0]= b[i+1];
            if( b[i] > b[i+1] ) {
                a[ b[i+1] ][2]= b[i];
                a[ b[i+1] ][1]=-1;
            }
            else {
                a[ b[i+1] ][1]= b[i];
                a[ b[i+1] ][2]=-1;
            }
            i=i+1;
        }
    }
    for(i=0 ; i<n-1 ; i++) {
        if( a[ b[i] ][0]==0 ) {
            a[ b[i] ][0]= b[n-1];
            if( b[i] < b[n-1]) a[ b[n-1] ][1]= b[i];
            else a[ b[n-1] ][2]= b[i];
        }
        if(a[ b[i] ][1]==0) a[ b[i] ][1]= -1;
        if( a[ b[i] ][2]==0) a[ b[i] ][2]=-1;
    }
    a[ b[n-1] ][0]= -1;
    p(b[n-1]);
    printf("%d\n", b[n-1]);
    printf("node\tparent\tleft_child\tright_child\n");
    for(i=0 ; i<n ; i++) {
        printf("%d\t%d\t%d\t%d\n", b[i], a[ b[i] ][0], a[ b[i] ][1], a[ b[i] ][2]);
    }
    return 0;
}
