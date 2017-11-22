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
#define pb push_back
#define mem(a, n) memset(a, n, sizeof(a))

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

int a[10009];

int main()
{
    int n, i, j, max, sum;
    while(scanf("%d", &n) && n) {
        max = 0;
        sum = 0;
        mem(a,0);
        for(i=0 ; i<n ; i++)
            scanf("%d", &a[i]);
        for(i=0 ; i<n ; i++) {
            sum = a[i];
            for(j=i+1 ; j<n ; j++) {
                sum += a[j];
                if(sum>max)
                    max = sum;
            }
        }
        if(max>0)
            printf("The maximum winning streak is %d.\n", max);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
