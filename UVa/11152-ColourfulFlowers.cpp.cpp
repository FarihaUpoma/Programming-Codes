#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,c;
    double s, area_triangle , area_circle1 , area_circle2 , r1, r2, k , m, d;
    while(scanf("%lf %lf %lf", &a, &b, &c)!=EOF)
    {
        d=a+b+c;
        s= d/2;
        m= sqrt( s*(s-a) * (s-b) * (s-c) );
        r1 = m/s;
        k= sqrt( (a+b+c) * (a+b-c) * (a+c-b) * (b+c-a) );
        r2= (a*b*c)/k;
        area_circle1= 2*acos(0) * r1 *r1;
        area_triangle= m- area_circle1;
        area_circle2= (2*acos(0) *r2*r2 )- m;

        printf("%.4lf %.4lf %.4lf\n", area_circle2 , area_triangle, area_circle1 );
    }
    return 0;
}
