#include <stdio.h>

int a[100], b[100];

int main()
{
    int k, i, t=1, sum;
    while(scanf("%d", &k)!=EOF)
    {
        if( k<0 ) break;
        else {
            printf("Case %d:\n", t);
            t++;
            for(i=0 ; i<12 ;i++)
                scanf("%d", &a[i] );
            for(i=0 ; i<12 ; i++)
                scanf("%d", &b[i] );
            if(k>=b[0]) {
                printf("No problem! :D\n");
                k= k-b[0];
            }
            else
                printf("No problem. :(\n");
            for(i=1,sum=k ; i<12 ; i++) {
                sum=sum+ a[i-1];
                if(sum>= b[i]) {
                    printf("No problem! :D\n");
                    sum= sum-b[i];
                }
                else
                    printf("No problem. :(\n");
            }
        }
    }
    return 0;
}
