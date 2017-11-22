#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main()
{
    freopen("input.txt", "r", stdin);
    double xp,yp, vp, x,y,v, r, R, alpha, t, d, q1, w, a1, a2, q2, q, xx , yy, s, tt, start, end, mid;
    scanf("%lf %lf %lf", &xp, &yp, &vp);
    scanf("%lf %lf %lf %lf", &x, &y, &v, &r);
    //alpha= (v*v)/(2*r);
    t= 15;
printf("%lf\n", t);
    d= sqrt( (xp-x)*(xp-x) + (yp-y)*(yp-y) );

    q1=yp/xp;
    R=sqrt( xp*xp + yp*yp);
    w= vp/R;
    a1= w*w*R;

    start=0;
    end=t;

    while( true) {


        mid= (start+end)/2;
        printf("%lf\n", mid);
        q2= q1+ w*mid + 0.5*a1*mid*mid;
        q= q1+q2;
        xx= R*cos((PI/180)*q);
        yy= R*sin((PI/180)*q);
        s= sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
        a2= (v*v)/2*s;
        tt= v/a2;
        if(mid==tt) break;
        else if(mid > tt)
            end= mid;
        else start= mid;
    }
    printf("%lf\n", tt);
    return 0;
}
