#include <stdio.h>

int g[10009], a[10009], n;

void dp()
{
    int i;
    g[0]= a[0];
    for(i=1 ; i<n ; i++)
        g[i]= g[i-1]+a[i];
}

int main()
{
    int i, j, k, sum, max;
    while(scanf("%d", &n)&&n)
    {
        for(i=0 ; i<n ; i++)
            scanf("%d", &a[i]);
        dp();
        for(j=0, max=0 ; j<n ; j++) {
            for(k=n-1 ; k>=j ; k--) {
                sum= g[k]-g[j-1];
                if(sum>max) max=sum;
               // printf("(%d,%d)->sum=%d\n",j,k, sum);
            }
            //if(sum>max) max=sum;
            //printf("max=%d\n", max);
        }
        if(max>0) printf("The maximum winning streak is %d.\n", max);
        else printf("Losing streak.\n");
    }
    return 0;
}
