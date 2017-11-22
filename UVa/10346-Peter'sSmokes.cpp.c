#include <stdio.h>

int main()
{
    int n, k,a,b, sum;
    while(scanf("%d %d", &n, &k)!=EOF)
    {
        for(a=n,sum=a ;  ; a=a/k+a%k) {
            sum=sum+a/k;
            if( (a/k+a%k) <k ) break;}
        printf("%d\n", sum);
    }
    return 0;
}
