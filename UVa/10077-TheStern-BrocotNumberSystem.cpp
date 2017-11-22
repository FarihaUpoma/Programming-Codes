#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    double m, n, u1,l1,u2,l2,mid, x, m1,n1;
    while(scanf("%lf %lf", &m, &n))
    {
        if(m==1 && n==1) break;
        u1=0;l1=1;u2=1;l2=0;
        x= m/n;
        while(1)
        {
            m1=u1+u2;
            n1= l1+l2;
            mid= m1/n1;
            if(x<mid) {
                printf("L");
                u2= m1;
                l2=n1;
            }
            else if(x>mid) {
                printf("R");
                u1=m1;
                l1=n1;
            }
            if(m1==m && n1==n) break;
        }
        printf("\n");
    }
    return 0;
}
