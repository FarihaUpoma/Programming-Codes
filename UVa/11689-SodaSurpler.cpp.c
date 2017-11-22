#include <stdio.h>

int main()
{
    int e,f,t,c,a,b,n,i, sum;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++)
    {
        scanf("%d %d %d", &e, &f, &c);
        n=e+f;
        for(a=n,sum=a ;  ; a=a/c+a%c) {
            sum=sum+a/c;
            if( (a/c+a%c) <c ) break;
        }
        printf("%d\n", sum-n);
    }
    return 0;
}
