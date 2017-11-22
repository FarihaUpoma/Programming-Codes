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

int par[100009];

int findPar(int i)
{
    if(par[i] == i)
        return i;
    else
        return par[i] = findPar(par[i]);
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int a, b, u, v, cnt, i, f;
    char str[10];
    //getchar();
    while( gets(str)!= NULL ) {
        for(i=0 ; i<100000 ; i++)
            par[i] = i;
        //mem(par, -1);
        cnt = 0;
        if(strlen(str)>0) {
            sscanf(str, "%d %d", &a, &b);
            par[a] = b;
            //printf("a=%d b=%d\n", a, b);
        }
        f = 0;
        while(scanf("%d", &a)) {
            if(a==-1)
                break;
            f = 1;
            scanf("%d", &b);
            //printf("a=%d b=%d\n", a, b);
            u = findPar(a);
            v = findPar(b);
            //printf("u=%d v=%d\n", u, v);
            if(u!=v) {
                par[u] = v;
            }
            else cnt++;
            //printf("a=%d b=%d\n", a, b);
        }
        if(f)
            printf("%d\n", cnt);
        //getchar();
    }
    return 0;
}
