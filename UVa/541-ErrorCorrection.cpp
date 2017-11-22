#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int row[101], col[101], a[101][101];

int main()
{
    int n, c, i, sum,k, j, f, indx, indy, d ;
    while(scanf("%d", &n) && n)
    {
        for(f=0,c=0,i=0 ; i<n ; i++) {
            for(sum=0,j=0 ; j<n ; j++) {
                scanf("%d", &a[i][j]);
                sum= sum+a[i][j];
            }
            row[i]= sum;
            if( sum%2==1) {
                c++;
                if(f==0) indx=i;
                f=1;
            }
        }
        for(d=0,f=0,j=0 ; j<n ; j++) {
            for(sum=0,i=0 ; i<n ; i++) {
                sum= sum+a[i][j];
            }
            col[j]= sum;
            if(sum%2==1) {
                d++;
                if(f==0) indy=j;
                f=1;
            }
        }
        /*for(i=0 ; i<n ; i++)
            printf("%d ", row[i]); printf("\n");
        for(i=0 ; i<n ; i++) printf("%d ", col[i]);
        printf("c=%d d=%d\n", c, d);*/
        if( c!=d) printf("Corrupt\n");
        else
        {
            if(c==0 && d==0) printf("OK\n");
            else if(c>1 && d>1) printf("Corrupt\n");
            else printf("Change bit (%d,%d)\n", indx+1, indy+1);
        }
    }
    return 0;
}
