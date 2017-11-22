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

char mine[20][20], a[20][20];
int fin[20][20];

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, n, i, j, k, f, x, y;
    scanf("%d", &t);
    while(t--) {
        f=0;
        memset(fin, -1, sizeof(fin));
        memset(mine, 0, sizeof(mine));
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for(i=0 ; i<n ; i++)
            scanf("%s", mine[i]);
        for(i=0 ; i<n ; i++)
            scanf("%s", a[i]);
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<n ; j++) {
                if(a[i][j] == 'x' || a[i][j]=='X') {
                    if( mine[i][j]=='*') {
                        f=1;
                        //break;
                    }
                    else {
                        fin[i][j]=0;
                        for(k=0 ; k<8 ; k++) {
                            x= dirx[k]+i;
                            y= diry[k]+j;
                            if(mine[x][y]=='*')
                                fin[i][j]++;
                        }
                    }
                }
                else {
                    fin[i][j]=-1;
                    //break;
                }
            }
            //if(f==1) break;
        }
        if(f==1) {
            for(i=0 ; i<n ; i++) {
                for(j=0 ; j<n ; j++) {
                    if(mine[i][j]=='*')
                        printf("*");
                    else {
                        if(fin[i][j]==-1)
                                printf(".");
                        else
                            printf("%d", fin[i][j]);
                        //printf("%s\n", mine[i]);
                    }
                }
                printf("\n");
            }
        }
        else {
            for(i=0 ; i<n ; i++) {
                for(j=0 ; j<n ; j++) {
                    if(fin[i][j]==-1)
                        printf(".");
                    else
                        printf("%d", fin[i][j]);
                }
                printf("\n");
            }
        }
        if(t>0) printf("\n");
    }
    return 0;
}
