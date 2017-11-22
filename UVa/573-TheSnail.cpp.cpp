#include <stdio.h>

int main()
{
    double h,m,u,d,f,i,sum,q;
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f )!=EOF)
    {
        if(h==0) break;
        else {
            sum=0;
            q=u*(f/100);
            for(i=1; ; i++) {
                m=sum+u;
                sum= sum+ u - d;
                u= u-q;
                if(u<0) u=0;
                if( m>h) break;
                else if(m<0 || sum<0) break;
            }
            if(m<0 || sum<0) printf("failure on day %.0lf\n", i);
            else printf("success on day %.0lf\n", i);
        }
    }
    return 0;
}
