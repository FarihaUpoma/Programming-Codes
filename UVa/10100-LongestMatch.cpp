#include <stdio.h>
#include <string.h>
#include <ctype.h>

int g[1009][1009], n, m;
char a[1009],b[1009], x[2][1009][100];

int parseWord( char *st, int pos)
{
    int i, j=0, k=0, l;
    for(i=0 ;  ; i++)
    {
        if( isalpha(st[i]) || isdigit(st[i]))
            x[pos][k][j++]= st[i];
        else {
            if(j) {
                x[pos][k][j]='\0';
                j=0;
                k++;
            }
            if( !st[i])
                break;
        }
    }
    return k;
}

void lcs()
{
    int i, j;
    n= parseWord( a, 0);
    m= parseWord( b, 1);
    for(i=0 ; i<=n ; i++) g[i][0]= 0;
    for(j=0 ; j<=m ; j++) g[0][j]= 0;
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=m ; j++)
        {
            if( strcmp(x[0][i-1], x[1][j-1])==0)
                g[i][j]= g[i-1][j-1]+1;
            else
            {
                if( g[i-1][j]>g[i][j-1]) g[i][j]= g[i-1][j];
                else g[i][j]= g[i][j-1];
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, k=1;
    while(gets(a)!=NULL)
    {
        gets(b);
        lcs();
        /*for(i=0 ; i<=n ; i++) {
            for(j=0 ; j<=m ; j++)
                printf("%d ", g[i][j]);
            printf("\n");
        }*/
        printf("%2d. ", k++);
        if(n==0 || m==0) printf("Blank!\n");
        else
            printf("Length of longest match: %d\n", g[n][m]);
    }
    return 0;
}
