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

long long int f( long long int N, long long int P, long long int M)
{
    if(P==0) return 1;
    if(P%2==0) {
        long long int ret = f(N, P/2, M);
        return ((ret%M)*(ret%M))%M;
    }
    else {
        return ((N%M)*( f( N, P-1, M )%M))%M;
    }
}

int main()
{
    long long int b, p, m;
    while(scanf("%lld %lld %lld", &b, &p, &m) !=EOF) {
        long long int ans = f(b, p, m);
        printf("%lld\n", ans);
    }
    return 0;
}
