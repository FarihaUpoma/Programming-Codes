#include <stdio.h>

int solve( int n)
{
    int i, c=1;
    for(i=1 ; ; i= ( (i*10)+1)%n ) {
        if( i%n==0) break;
        c++;
    }
    return c;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        printf("%d\n", solve(n) );
    }
    return 0;
}
