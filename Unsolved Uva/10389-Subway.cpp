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

int b[100][100];
char a[100][100];

int main()
{
    freopen("input.txt", "r", stdin);

    int t_case, sx, sy, tx, ty, n, i, j, k;
    scanf("%d", &t_case);
    while(t_case--) {
        scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
        n=0;
        getchar();
        while(1) {
            gets(a[n]);
            if(strlen(a[n])==0) break;
            n++;
        }
        k=2;
        for(i=0 ; i<n ; i++) {
            j=0;
            char *p;
            p= strtok(a[i], " ");
            while(p) {
                b[i][j++]= atoi(p);
                p= strtok(NULL, " ");
            }
            k = k+(j/2-1);
        }
        for(i=0 ; i<n; i++) printf("b = %d\n", b[0][i]);
        printf("tracks= %d\n", k);

    }
    return 0;
}
