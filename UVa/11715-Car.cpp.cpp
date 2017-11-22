#include <stdio.h>
#include <math.h>

int main()
{
    int n, c=1;
    double u,v,t,s,a;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;
        else {
            printf("Case %d: ", c);
            c++;
            if(n==1) {
                scanf("%lf %lf %lf", &u, &v, &t);
                a = (v-u)/t;
                s= u*t + (a*t*t)/2;
                printf("%.3lf %.3lf\n", s, a);
            }
            else if(n==2) {
                scanf("%lf %lf %lf", &u, &v, &a);
                s = (v*v-u*u)/(2*a);
                t= (v-u)/a;
                printf("%.3lf %.3lf\n", s, t);
            }
            else if(n==3) {
                scanf("%lf %lf %lf", &u, &a, &s);
                v= sqrt( u*u + 2*a*s);
                t= (v-u)/a;
                printf("%.3lf %.3lf\n", v, t);
            }
            else if(n==4) {
                scanf("%lf %lf %lf", &v, &a, &s);
                u= sqrt( v*v - 2*a*s);
                t= (v-u)/a;
                printf("%.3lf %.3lf\n", u, t);
            }
        }
    }
    return 0;
}
