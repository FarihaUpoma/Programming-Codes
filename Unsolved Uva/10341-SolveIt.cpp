#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

#define PI acos(-1)
#define eps 1e-100

int main()
{
    freopen("input.txt", "r", stdin);
    double p, q, r, s, t,u, start, end, mid, w, x, c=0, y;
    scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u);
    start = 0;
    end = 1;
    x=0;
    y= p*(exp(-x))+q*sin((PI/180)*x)+r*cos((PI/180)*x) +s*tan((PI/180)*x)+t*x*x+u;
printf("y=%lf\n", y);
    while(true) {
        mid= (start+end)/2;
        x= mid;

        w= p*(exp(-x))+q*sin((PI/180)*x)+r*cos((PI/180)*x) +s*tan((PI/180)*x)+t*x*x+u;
        printf("x=%lf w=%lf\n", x,w);
        if(w==0.0) break;
        else {
            if(y*w<eps) {
                end= mid;
                y=w;
            }
            else {
                y=w;
                start=mid;
            }
        }
        if(c==25) break;
        c++;

    }
    printf("%.4lf\n", x);

    return 0;
}
