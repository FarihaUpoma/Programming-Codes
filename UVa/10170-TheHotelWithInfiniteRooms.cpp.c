#include <stdio.h>

int main()
{
    long long int d, sum;
    int s, i;
    while(scanf("%d %lld", &s, &d)!=EOF)
    {
        long long int c=0;
        for(i=s, sum= 0 ; sum<d ; i++) {
            sum=sum+i;
        }
        printf("%d\n", i-1);
    }
    return 0;
}
