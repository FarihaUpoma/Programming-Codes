#include <stdio.h>

long long int ack( long long int a )
{
    long long int c=0;
    long long int i;
    for(i=a ;  ; ) {
        if(i%2==0) {i=i/2;c++;}
        else {i=3*i+1;c++;}
        if(i==1) break;
    }
    return c;
}

int main()
{
    long long int l, h, v, s, j, i;
    long long int max, temp;
    while(scanf("%lld %lld", &l, &h)!= EOF)
    {
        if(l==0 && h==0) break;
        else {
            if ( l > h ) {
                temp = l;
                l = h;
                h = temp;
            }
            max=ack(l);
            j=l;
            for(i=l ; i<=h ; i++) {
                if( ack(i)>max) {
                    max=ack(i);
                    j=i;
                }
            }
            printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l, h, j, max);
        }
    }
    return 0;
}
