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

char a[2000009];

int main()
{
    int n, i, min ,indr, indd;
    while(scanf("%d", &n) && n) {
        scanf("%s", a);
        indr=indd=-1;
        min = 3000000;
        for(i=0 ; i<n ; i++) {
            if(a[i] == 'Z') {
                min=0;
                break;
            }
            else if(a[i] == 'R') {
                indr = i;
                if(indd != -1) {
                    if( i-indd <min) {
                        min = i-indd;
                    }
                }
            }
            else if(a[i] == 'D') {
                indd = i;
                if(indr != -1) {
                    if( i-indr <min) {
                        min = i-indr;
                    }
                }
            }
        }
        printf("%d\n", min);
    }
    return 0;
}
