#include <stdio.h>

int main()
{
    long long int a,b,c ,n  , i;
    scanf("%lld", &n);
    for(i=0 ; i <n ; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a+b <= c || b+c <= a || c+a <= b)
            printf("Case %lld: Invalid\n", i+1);
        else if(a==b && b==c)
            printf("Case %lld: Equilateral\n", i+1);
        else if( a==b && a!=c || a==c && a!=b || b==c && b!=a)
            printf("Case %lld: Isosceles\n", i+1);
        else if( a!= b && b!=c && c!=a)
            printf("Case %lld: Scalene\n", i+1);
    }
    return 0;
}
