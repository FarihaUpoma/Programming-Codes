#include <stdio.h>
#include <math.h>

int main()
{
    int t, l, i;
    double w,r,area_red, area_green;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &l);
        w=l*.6;
        r=l*.2;
        area_red= acos(-1) *r*r;
        area_green= l*w - area_red;
        printf("%.2lf %.2lf\n", area_red, area_green);
    }
    return 0;
}
