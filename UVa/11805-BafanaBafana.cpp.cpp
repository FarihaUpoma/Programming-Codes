#include <stdio.h>

int main()
{
    long long int n, k ,p, t, i, m;
    scanf("%lld", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%lld %lld %lld", &n, &k, &p);
        if(k+p <= n)
            m=k+p;
        else
            m=(k+p)%n;
        if(m==0) m=n;
        printf("Case %lld: %lld\n", i+1, m);
    }
    return 0;
}
