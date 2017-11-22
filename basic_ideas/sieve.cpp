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

int a[500][500], g[500][500];

int main()
{
    freopen("input.txt", "r", stdin);

    int n, k, i, j, indx, indy, tmp, c=0, f, t, inPlace, p, T;
    scanf("%d", &T);
    for(t=1; t<=T; t++) {

        scanf("%d", &n);
        k=0;
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<n ; j++) {
                scanf("%d", &a[i][j]);
                if(a[i][j]==0) {
                    indx = i;
                    indy = j;
                }
                g[i][j] = k++;
            }
        }
        c= 0 ;
        while(1) {
            f=0;
            inPlace = 0;
            p=0;
            if( !indx && !indy ) {
                inPlace = 1;
                for(i=0 ; i<n ; i++) {
                    for(j=0 ; j<n ; j++) {
                        if( a[i][j] != g[i][j]) {
                            tmp = a[indx][indy];
                            a[indx][indy] = a[i][j];
                            a[i][j] = tmp;
                            c++;
                            f=1;
                            indx = i;
                            indy = j;
                            break;
                        }
                    }
                    if(f==1) break;
                }
                if(f==0) p=1;
            }
            //printf("indx=%d indy=%d\n", indx, indy);
            if(p && inPlace) break;
            f=0;
            for(i=0 ; i<n ; i++) {
                for(j=0 ; j<n ; j++) {
                    if( a[i][j] == g[indx][indy]) {
                        tmp = a[indx][indy];
                        a[indx][indy] = a[i][j];
                        a[i][j] = tmp;
                        indx = i;
                        indy = j;
                        c++;
                        f=1;
                        break;
                    }
                }
                if(f==1) break;
            }
            //printf("in while\n");
        }
        printf("Case %d: %d\n", t, c);
    }
    return 0;
}
