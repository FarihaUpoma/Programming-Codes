#include <stdio.h>
#include <math.h>

int main()
{
    long long int n, s;
    while(scanf("%lld", &n)!=EOF)
    {
        if(n==0) break;
        s=sqrt(n);
        if( s*s == n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
