#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c;
    double r , s , A;
    while(scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
    {
        if(a==0 && b==0 && c==0) r=0.000;
        else {
            s=(a+b+c)/2;
            A= sqrt( s*(s-a) * (s-b) * (s-c) );
            r= A/s;
        }
        printf("The radius of the round table is: %.3lf\n", r);
    }
    return 0;
}
