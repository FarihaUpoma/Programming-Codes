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

char a[20][30];
int b[20];

int main()
{
    int n, i, max, c, j, cnt;
    while(scanf("%d", &n) && n)
    {
        memset(a, 0, sizeof(a));
        getchar();
        for(i=0 ; i<n ; i++) {
            gets(a[i]);
        }
        //for(i=0 ; i<n ; i++) printf("%s\n", a[i]);
        max=0;
        for(i=0 ; i<n ; i++) {
            c=0;
            for(j=0 ; j<25 ; j++) {
                if(a[i][j]=='X') c++;
            }
            b[i]= c;
            if(c>max) max=c;
        }
        cnt=0;
        for(i=0 ; i<n ; i++) {
            cnt= cnt+ (max- b[i]);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
