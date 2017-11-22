#include <stdio.h>

int sum( long long int x)
{
    int b , c;
    for(c=x, b=0 ;  ; c=c/10) {
        b=b+(c%10);
        if(c==0) break;
    }
    return b;
}

int main()
{
    long long int x;
    int i;
    while(scanf("%lld", &x))
    {
        if(x==0) break;
        for(i=x ; i>9 ; i=sum(i));
        printf("%d\n", i);
    }
    return 0;
}
