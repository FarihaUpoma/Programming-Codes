#include <stdio.h>

int main()
{
    long long int n, b, h, w, min,i,p,k,s,q, f;
    while(scanf("%lld %lld %lld %lld", &n, &b, &h, &w)!=EOF)
    {
        min=b;f=0;
        for(i=0 ; i<h ; i++) {
            scanf("%lld", &p);
            for(k=0 ; k<w ; k++) {
                scanf("%lld", &s);
                if(s>=n) {
                    q= p*n;
                    if(q<=min) {
                        min=q;
                        f=1;
                    }
                }
            }
        }
        if(f==0) printf("stay home\n");
        else printf("%lld\n", min);
    }
    return 0;
}
