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

char a[1009], m[33][33];

void bitmap(int x, int y)
{
    int k;
    memset( m, '.' , sizeof( m));
    for(k=0 ;  ; k++) {
        if( a[k]=='.') break;
        if( a[k]=='E') {
            //if(a[k-1]=='E' || a[k+1]=='E')
                m[x-1][y]='X';
            y++;
        }
        else if( a[k]=='S') {
            m[x-1][y-1]= 'X';
            x--;
        }
        else if( a[k]=='W') {
            //if(a[k-1]=='W' || a[k+1]=='W')
                m[x][y-1]= 'X';
            y--;
        }
        else {
            m[x][y]= 'X';
            x++;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int t, i, j, x, y, k=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &x, &y);
        scanf("%s", a);
        printf("Bitmap #%d\n", k++);
        bitmap(y, x);
        for(i=31 ; i>=0 ; i--) {
            for(j=0 ; j<32 ; j++) {
                printf("%c", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
