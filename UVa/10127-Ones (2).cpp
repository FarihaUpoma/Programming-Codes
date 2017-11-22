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

int main()
{
    long long int i;
    int n, r;
    while(scanf("%d", &n) != EOF) {
        int c = 0;
        r = 1;
        if(n != 0) {
            for(i = 1 ; ; i = r*10+1) {
                c++;
                r = i%n;
                if( r==0) {
                    break;
                }
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
