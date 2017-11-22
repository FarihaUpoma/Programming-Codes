#include <stdio.h>

int n, m, g[105][105], a[105], b[105];

void lcs()
{
    int i, j;
    for(i=0 ; i<=n ; i++) g[i][0]=0;
    for(i=0 ; i<=m ; i++) g[0][i]= 0;
    for(i=1 ; i<=n ; i++) {
        for(j=1 ;j<=m ; j++) {
            if( a[i]==b[j])
                g[i][j]= g[i-1][j-1]+1;
            else {
                if( g[i-1][j]>g[i][j-1]) g[i][j]= g[i-1][j];
                else g[i][j]= g[i][j-1];
            }
        }
    }
}

int main()
{
    int i, k=1;
    while(scanf("%d %d", &n,&m)&& n && m)
    {
        for(i=1 ; i<=n ; i++)
            scanf("%d", &a[i]);
        for(i=1 ; i<=m ; i++)
            scanf("%d", &b[i]);
        printf("Twin Towers #%d\n", k++);
        lcs();
        printf("Number of Tiles : %d\n\n", g[n][m]);
    }
    return 0;
}
