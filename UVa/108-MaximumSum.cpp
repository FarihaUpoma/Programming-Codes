#include <stdio.h>

int g[111][111], a[111][111], n;

void dp()
{
    int i, j;
    g[0][0]= a[0][0];
    for(i=1 ; i<n ; i++)
        g[0][i]= g[0][i-1]+a[0][i];
    for(i=1 ; i<n ; i++)
        g[i][0]= g[i-1][0]+a[i][0];
    for(i=1 ; i<n ; i++)
        for(j=1; j<n ; j++)
            g[i][j]= g[i][j-1]+g[i-1][j]-g[i-1][j-1]+a[i][j];
}

int main()
{
    int i, j, max,b,c,d, sum=0;
    scanf("%d", &n);
    for(i=0 ; i<n ; i++)
        for(j=0 ; j<n ; j++)
            scanf("%d", &a[i][j]);
    dp();
    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<n ; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
    for(max=0,i=0  ; i<n ; i++) {
        for(b=0 ; b<n ; b++)
            for(c=i ; c<n ; c++)
                for(d=b ; d<n ; d++) {
                    sum= g[c][d]-g[i-1][d]-g[c][b-1]+g[i-1][b-1];
                    if(sum>max) max= sum;
                    }
    }
    printf("%d\n", max);
    return 0;
}
