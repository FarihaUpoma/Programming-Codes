#include <stdio.h>
#include <string.h>

int g[1005][1005], n, m;
char a[1005],b[1005];

void lcs()
{
    int i, j;
    for(i=0 ; i<=n ; i++) g[0][i]=0;
    for(i=0 ; i<=m ; i++) g[i][0]= 0;
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=m ; j++) {
            if(a[i-1]==b[j-1]) {
                g[i][j]= g[i-1][j-1]+1;
            }
            else {
                if( g[i][j-1]>g[i-1][j])
                {
                    g[i][j]= g[i][j-1];
                }
                else
                {
                    g[i][j]= g[i-1][j];
                }
            }
        }
    }
}

int main()
{
    int k=1, i, j;
    while(gets(a)!=NULL)
    {
        gets(b);
        n= strlen(a);
        m= strlen(b);
        lcs();
        /*for(i=0 ; i<=n ; i++) {
            for(j=0 ; j<=m ; j++)
                printf("%d ", g[i][j]);
            printf("\n");
        }*/
        printf("%d\n", g[n][m]);

    }
    return 0;
}
