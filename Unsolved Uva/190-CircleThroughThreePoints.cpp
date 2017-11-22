#include <stdio.h>
#include <math.h>
#include <algorithm>

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("190_out.txt", "w", stdout);
    double x1, x2, x3, y1, y2, y3, x, y, a, b, c, d, m, k, r, C, g, f, s=0;
    char q1, q2, w1, w2, w3;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF)
    {
        a= x1-x2;
        //printf("%lf\n", a);
        b= y1-y2;
        //printf("%lf\n", b);
        m= (x1*x1+y1*y1-x2*x2-y2*y2)/2;
        //printf("%lf\n", m);
        c= x2-x3;
        //printf("%lf\n", c);
        d= y2- y3;
        //printf("%lf\n", d);
        k= (x2*x2+y2*y2-x3*x3-y3*y3)/2;
        //printf("%lf\n", k);
        y= (m*c-a*k)/(b*c-a*d);
        x= (k-d*y)/c;
        //printf("%lf %lf\n" , x, y);
        r= sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1) );
        C= x*x+y*y- r*r;
        //printf("C=%lf\n", C);
        g= 2*x*(-1);
        f= 2*y*(-1);
        if(x>0) q1= '-';
        else {
            q1= '+';
            x= x*(-1);
        }
        if(y>0) q2= '-';
        else {
            q2= '+';
            y= y*(-1);
        }
        if(s==1) printf("\n");
        s=1;
        if(x==0 && y!=0) printf("x^2 + (y %c %.3lf)^2 = %.3lf^2\n", q2,  y, r);
        else if(x!=0 && y==0) printf("(x %c %.3lf)^2 + y^2 = %.3lf^2\n",q1,  x, r);
        else if(x==0 && y==0) printf("x^2 + y^2 = %.3lf^2\n", r);
        else
            printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",q1,  x, q2,  y, r);
        if(g<0) {
            w1= '-';
            g= g*(-1);
        }
        else w1= '+';
        if(f<0) {
            w2= '-';
            f= f*(-1);
        }
        else w2= '+';
        if(C<0) {
            w3= '-';
            C= C*(-1);
        }
        else w3= '+';

        if(g==0 && f!=0 && C!=0) printf("x^2 + y^2 %c %.3lfy %c %.3lf = 0\n\n", w2, f, w3, C );
        else if(g!=0 && f==0 && C!=0) printf("x^2 + y^2 %c %.3lfx %c %.3lf = 0\n\n",w1, g, w3, C );
        else if(g!=0 && f!=0 && C==0) printf("x^2 + y^2 %c %.3lfx %c %.3lfy = 0\n\n",w1, g, w2, f );
        else if(g==0&&f==0&&C!=0) printf("x^2 + y^2 %c %.3lf = 0\n\n", w3, C );
        else if(g==0&&C==0&&f!=0) printf("x^2 + y^2 %c %.3lfy = 0\n\n",w2, f );
        else if(C==0&&f==0&&g!=0) printf("x^2 + y^2 %c %.3lfx = 0\n\n",w1, g);
        else if(C==0&&f==0&&g==0) printf("x^2 + y^2 = 0\n\n" );
        else
            printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",w1, g, w2, f, w3, C );
    }
    return 0;
}
