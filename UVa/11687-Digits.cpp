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

char a[1000009];

int main()
{
    int x, i, l, k, cnt;
    while(scanf("%s", a)) {
        if( strcmp( a, "END")==0) break;
        l= strlen(a);
        if(atoi(a)==1) printf("1\n");
        else {
            for(i= l , k=1 ; ; i= cnt, k++) {
                cnt=0;
                x=i;
                while(x) {
                    x= x/10;
                    cnt++;
                }
                //printf("i=%d\n", i);
                if(i==cnt) break;
            }
            printf("%d\n", k+1);
        }
    }
    return 0;
}
