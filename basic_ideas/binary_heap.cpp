#include <stdio.h>

int a[100], g[100], n;

void insert()
{
    int i, x, temp, p;
    for(i=2 ; i<n ; i++ ) {
        x=i;
        for(p=x/2 ; p>=1 ; p=p/2 ) {
            if( g[x]< g[p]) {
                temp= g[p];
                g[p]= g[x];
                g[x]= temp;
            }
            x=p;
        }
    }
}

int extractMean()
{
    int r, i, temp, k;
    r= g[1];
    g[1]=g[n-1];
    g[n-1]= r;
    n--;
    for(i=1 ; i<n ; ) {
        if(g[2*i]<g[2*i+1]) k=2*i;
        else k= 2*i+1;
        if(g[i]<g[k]) {
            temp= g[i];
            g[i]= g[k];
            g[k]= temp;
        }
    }
    return r;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int i, x, p, temp, mean;
    scanf("%d", &n);
    for(i=1 ; i<=n ; i++)
        scanf("%d", &g[i]);
    insert();
    for(i=1 ;i<n+1 ; i++) printf("%d ", g[i]);
    printf("\n");
    mean= extractMean();
    printf("mean=%d\n", mean);
    for(i=1 ;i<n+1 ; i++) printf("%d ", g[i]);
    printf("\n");

    return 0;
}
