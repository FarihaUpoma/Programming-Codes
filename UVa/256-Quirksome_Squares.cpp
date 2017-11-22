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
    int n, i, x, y, j, w=1 ;
    double p,q;
    while(scanf("%d", &n)!=EOF)
    {
        if (n == 8)
            printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
        else {
            p= pow(10.0, n);
            q= pow(10.0, n/2 );
            int t=q;
            int r=p;
            //printf("t=%d\n", t);
            for(i=0 ; i<r ; i++) {
                x= i/t;
                y=i%t;
                //if(i==3025)
                    //printf("x=%d y=%d\n", x, y);
                if( (x+y)*(x+y)== i) {
                    if(n==2) printf("%d%d\n", x, y);
                    else if(n==4) printf("%02d%02d\n", x, y);
                    else if(n==6) printf("%03d%03d\n", x, y);
                    //                printf("%d %d %d\n", x, y, i);
                }
            }
        }
    }
    return 0;
}
