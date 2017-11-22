#include <stdio.h>

long long int f91( int n)
{
    if( n>=101)
        return n-10;
    else if(n<=100)
        return f91(f91(n+11));
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;
        else
            printf("f91(%d) = %lld\n", n, f91(n) );
    }
    return 0;
}
