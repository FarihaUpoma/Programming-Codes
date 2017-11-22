#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int b[100];
char a[100][1010], indc, q[1010];

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, n, m, i, j, max, k, c;
    scanf("%d", &t);
    for(i=0 ; i<t;  i++) {
        scanf("%d %d", &n, &m);
        for(j=0 ; j<n ; j++)
            scanf("%s", a[j]);
        for(j=0 ; j<m ; j++) {
            max=0;
            for(k=60 ; k<95 ; k++) b[k]=0;
            for(k=0 ; k<n ; k++) {
                b[ a[k][j] ]++;
                if(b[ a[k][j] ]==max && a[k][j]<indc)
                {
                    max= b[ a[k][j] ];
                    indc= a[k][j];
                }
                if( b[ a[k][j] ]>max) {
                    max= b[ a[k][j] ];
                    indc= a[k][j];
                }
            }
            q[j]= indc;
        }
        q[m]=0;
        for(c=0,j=0 ; j<m ; j++)
        {
            for(k=0 ; k<n ; k++)
            {
                if(q[j]!=a[k][j]) c++;
            }
        }
        printf("%s\n%d\n", q, c);
    }
    return 0;
}
