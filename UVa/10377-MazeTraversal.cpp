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

char a[100][100], b[100][100];

int main()
{
    //freopen("input.txt", "r", stdin);

    int t, n, m, i, k, xs, ys, l, j;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        getchar();
        for(i=0 ; i<n ; i++) {
            gets(a[i]);
        }
        scanf("%d %d", &xs, &ys);
        k=0;
        getchar();
        while(gets(b[k++])) {
            l= strlen(b[k-1]);
            if(b[k-1][l-1]=='Q')
                break;
        }
        char d= 'N';
        int x= xs-1, y= ys-1;
        for(i=0 ; i<k ; i++) {
            l= strlen(b[i]);
            for(j=0 ; j<l ; j++) {
                if( b[i][j]=='F') {
                    if( d=='N') {
                        if( a[x-1][y] !='*' )
                            x--;
                    }
                    else if( d=='E') {
                        if( a[x][y+1] != '*')
                            y++;
                    }
                    else if( d=='S') {
                        if( a[x+1][y] != '*')
                            x++;
                    }
                    else {
                        if( a[x][y-1] != '*')
                            y--;
                    }
                }
                else {
                    if(d=='N') {
                        if(b[i][j]=='R')
                            d= 'E';
                        else if(b[i][j]=='L')
                            d= 'W';
                    }
                    else if( d=='E') {
                        if( b[i][j]=='R')
                            d= 'S';
                        else if( b[i][j]=='L')
                            d= 'N';
                    }
                    else if( d=='S') {
                        if( b[i][j]=='R')
                            d= 'W';
                        else if( b[i][j]=='L')
                            d= 'E';
                    }
                    else if( d=='W') {
                        if( b[i][j]=='R')
                            d= 'N';
                        else if( b[i][j]=='L')
                            d= 'S';
                    }
                }
            }
        }
        printf("%d %d %c\n", x+1, y+1, d);
        if(t>0) printf("\n");
    }
    return 0;
}
