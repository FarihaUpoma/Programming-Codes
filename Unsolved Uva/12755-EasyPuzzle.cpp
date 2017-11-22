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

int a[250000];

int main()
{
    freopen("input.txt", "r", stdin);

    int n, k, i, j, indx, tmp, c=0, f, t, inPlace, p, T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        scanf("%d", &n);
        n=n*n;
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
            if(a[i]==0) {
                indx = i;
            }
        }
        c= 0 ;
        while(1) {
            f=0;
            inPlace = 0;
            p=0;
            if( !indx ) {
                inPlace = 1;
                for(i=0 ; i<n ; i++) {
                    if( a[i] != i) {
                        tmp = a[indx];
                        a[indx] = a[i];
                        a[i] = tmp;
                        c++;
                        f=1;
                        indx = i;
                        break;
                    }
                    if(f==1) break;
                }
                if(f==0) p=1;
            }
            //printf("indx=%d\n", indx);
            if(p && inPlace) break;

            f=0;
            for(i=0 ; i<n ; i++) {
                if( a[i] == indx) {
                    tmp = a[indx];
                    a[indx] = a[i];
                    a[i] = tmp;
                    indx = i;
                    c++;
                    f=1;
                    break;
                }
                if(f==1) break;
            }
            //printf("in while\n");
        }
        printf("Case %d: %d\n", t, c);
    }
    return 0;
}
