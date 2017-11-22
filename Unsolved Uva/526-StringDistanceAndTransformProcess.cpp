#include <stdio.h>
#include <string.h>

int g[100][100], p[100][100], n, m;
char a[100], b[100];

void lcs()
{
    int i, j;
    for(i=0 ; i<=m ; i++) {
        g[i][0]=0;
        p[i][0]=1;
    }
    for(i=0 ; i<=n ; i++) {
        g[0][i]=0;
        p[0][i]=1;
    }
    p[0][0]=0;
    for(i=1 ; i<=m ; i++) {
        for(j=1 ; j<=n ; j++) {
            if( a[j]==b[i]) {
                g[i][j]= g[i-1][j-1]+1;
                p[i][j]=2;
            }
            else {
                if( g[i-1][j]> g[i][j-1]) {
                    g[i][j]= g[i-1][j];
                    p[i][j]= 3;
                }
                else {
                    g[i][j]= g[i][j-1];
                    p[i][j]= 1;
                }
            }
        }
    }
}

void print()
{
    int i=m, j=n;
    for( ; i>=0 ; ) {
        for( ; j>=0 ; )  {
            if(p[i][j]==1 && p[i][j-1]!=3) {
                printf("Delete %d\n", j);
                j--;
            }
            else if(p[i][j]==1 && p[i][j-1]==3) {
                printf("Replace %d, %c\n",j, b[i]);
                j--;
            }
            else if(p[i][j]==3) i--;
            else if( p[i][j]==2) {
                i--;
                j--;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%s %s", a, b);
    n= strlen(a);
    m= strlen(b);
    lcs();
    print();
    return 0;
}
