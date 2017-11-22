/*
    The angle – The absolute hour hand angle is hd= = 30*h + m / 2.
    The absolute angle for the minute hand is md = 6* m. The difference d = (60 *h + 11* m) / 2.
    Minimum difference – The angle we’re calculating is always positive.
    The problem is when it exceeds 180. If this happens, simply apply a = 360 - a.
*/
#include <stdio.h>

int main()
{
    double h, m, hd, md, d1, d2;
    while(scanf("%lf:%lf", &h, &m)!=EOF)
    {
        if(h==0 && m==00) break;
        else {
            hd=30*h + (m/2);
            md= m*6;
            if( hd>md) {
                d1= hd-md;
                d2= 360-hd + md;
            }
            else {
                d1= md-hd;
                d2= 360-md+hd;
            }
            if(d1<d2) printf("%.3lf\n", d1);
            else printf("%.3lf\n", d2);
        }
    }
    return 0;
}
