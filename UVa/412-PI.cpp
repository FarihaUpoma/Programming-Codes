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

int st[40009];

int gcd ( int a, int b )
{
    int c;
    while ( a != 0 ) {
        c = a;
        a = b%a;
        b = c;
  }
  return b;
}

int a[100];

int main()
{
    int n, i, j, c, f, k, t;
    double x;

    while(scanf("%d", &n) && n)
    {
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        for(t=0,c=0,i=0 ; i<n-1 ; i++) {
            for(j=i+1 ; j<n ; j++) {
                if(gcd( a[i], a[j])==1) c++;
                t++;
            }
        }

        if(c==0) printf("No estimate for this data set.\n");
        else {
            x= 6.0/c*t;
            printf("%.6lf\n", sqrt(x));
        }
    }
    return 0;
}
