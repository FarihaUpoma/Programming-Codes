#include <stdio.h>

int main()
{
    int t, a[1000] , i, n, p, k, tmp;
    while(scanf("%d", &t)!=EOF)
    {
        if(t==0) break;
        else {
            n=0;
            for(i=0 ; i<t ; i++)
                scanf("%d", &a[i] );
            for(k=0 ; k<t ; k++) {
                for(p=k+1 ; p<t ; p++) {
                    if( a[k] > a[p] ) {
                        tmp= a[p];
                        a[p]= a[k];
                        a[k]= tmp;
                    }
                }
            }
            for(i=0 ; i<t ; i++) {
                if( a[i+1]-a[i] >200)
                    n=1;
            }

            if(( 1422-a[t-1] )*2 >200 || n==1) printf("IMPOSSIBLE\n");
            else if( (1422-a[t-1])*2 <=200  && n==0) printf("POSSIBLE\n");

        }
    }
    return 0;
}
