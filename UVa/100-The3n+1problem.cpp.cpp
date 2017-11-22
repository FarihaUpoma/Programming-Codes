#include <stdio.h>

int main()
{
    long long int max, c, i, j, l, h, temp, m, n;
    while(scanf("%lld %lld", &l, &h)!=EOF)
    {
        if ( l > h ) {
                    m=l;n=h;
                    temp = l;
                    l = h;
                    h = temp;
        }
        else {m=l;n=h;}
        max=0;
        for(i=l ; i<=h ; i++) {
            c=1;
            for(j=i ; j>1 ; ) {
                if(j%2==0) {
                    j=j/2;
                    c++;
                }
                else {
                    j=3*j+1;
                    c++;
                }
            }
            if(c>max) max=c;
        }
        printf("%lld %lld %lld\n", m, n, max);
    }
    return 0;
}
