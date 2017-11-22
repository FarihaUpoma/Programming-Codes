#include <stdio.h>

int main()
{
    int n , i , q , s, g , t=1;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;
        else {
        s=0;
        g=0;
            for(i=0 ; i<n ; i++) {
                scanf("%d", &q);
                if(q>0 && q<100) s++;
                else if(q==0) g++;
            }
            printf("Case %d: %d\n",t, s-g);
            t++;
        }
    }
    return 0;
}
