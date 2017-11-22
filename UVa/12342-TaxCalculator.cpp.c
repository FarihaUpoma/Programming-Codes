#include <stdio.h>
#include <math.h>

int main()
{
    int t, i;
    long long int n, a, b, c, d, tax;
    scanf("%d", &t);
    for(i=0 ; i<t; i++) {
        scanf("%lld", &n);
        if(n<=180000) tax=0;
        else {
            a=n-180000;
            b=a-300000;
            c=b-400000;
            d=c-300000;
            if(a>=300000) tax= 30000;
            else if(a>0 && a<300000) {
                tax= ceil(a*.1);
                if(tax<=2000) tax= 2000;
            }
            if (b>=400000) tax= tax+60000;
            else if(b>0 && b<400000) tax= tax+ ceil(b*.15);
            if(c>=300000) tax= tax+ 60000;
            else if(c>0 && c<300000) tax= tax+ ceil (c*.2);
            if(d>0 ) tax= tax+ ceil(d*.25);
        }
        printf("Case %d: %lld\n", i+1,tax);
    }
    return 0;
}
