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

char a[1000][1];

int main()
{
    int t, T, i, n, c, f, w;
    scanf("%d", &T);
    for(t=1 ; t<=T ; t++) {
        scanf("%d", &n);
        c = 0;
        f = 0;
        w = 0;
        for(i=0 ; i<n ; i++) {
            scanf("%s", a[i]);
            if( a[i][0] == 'L' || a[i][0] == 'D') {
                c++;
                if(f==0)
                    w++;
            }
            if(c==3) {
                f=1;
            }
            if(a[i][0] == 'W') {
                if(f==0) {
                    w++;
                    c=0;
                }
            }
        }
        if(f==1) printf("Case %d: %d\n", t, w);
        else printf("Case %d: Yay! Mighty Rafa persists!\n", t);
    }
    return 0;
}
