#include <stdio.h>
#include <math.h>

int main()
{
    //freopen("input.txt", "r", stdin);
    double a, b, c, d, e, f, A1, B1, C1, A2, B2, C2, D, x, y, r, q, g, f1;
    while(scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e ,&f)!=EOF)
    {
        A1= a-c;
        B1= b-d;
        C1= (a*a+b*b-c*c-d*d)/2;
        A2= c-e;
        B2= d-f;
        C2= ((c*c+d*d)-(e*e+f*f))/2;
        //printf("%lf  %lf %lf\n", A2, B2, C2);
        D= A1*B2-A2*B1;
        x= (C1*B2-B1*C2)/D;
        y= (A1*C2-A2*C1)/D;
        r= sqrt( (x-a)*(x-a)+(y-b)*(y-b));
        //q= x*x+y*y-r*r;
    //printf("%lf  %lf %lf\n", A2, B2, C2);
        //g=2*x*(-1);
        f1=2*y*(-1);
        printf("%.2lf\n", 2*r*3.141592653589793);
        //printf("(x - %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n", x, y, r);
        //printf("x^2 + y^2 - %.3lfx + %.3lfy + %.3lf = 0\n", g, f1, c);
    }
    return 0;
}
