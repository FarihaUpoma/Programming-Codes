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
    //freopen("input.txt", "r", stdin);

    int l, f, i, j, k, p;
    while(gets(a)) {
        p=-1;
        l= strlen(a);
        for(i=0 ; i<l ; i++) {
            if(a[i]==' ') {
                for(j=i-1 ; j>p ; j--) {
                    printf("%c", a[j]);
                }
                printf(" ");
                p= i;
            }
        }
        for(i=l-1 ; i>p ; i--) printf("%c", a[i]);
        printf("\n");
    }
    return 0;
}
