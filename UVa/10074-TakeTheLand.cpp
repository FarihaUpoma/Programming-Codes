#include <stdio.h>
#include <string.h>

int g[111][111], a[111][111], n, m;

void dp()
{
    int i, j;
    g[0][0]=a[0][0];
    for(i=1 ; i<n ; i++)
        g[0][i]= g[0][i-1]+a[0][i];
    for(i=1 ; i<m ; i++)
        g[i][0]= g[i-1][0]+a[i][0];
    for(i=1 ; i<m ; i++)
        for(j=1 ; j<n ; j++)
            g[i][j]= g[i-1][j]+g[i][j-1]- g[i-1][j-1]+a[i][j];
}

int main()
{
   /*freopen("input.txt", "r", stdin);*/
    int i, j, max, q, b, c,d, sum, p, f, w;
    while(scanf("%d %d", &m,&n)&&m&&n) {
        for(i=0 ; i<m ; i++)
            for(j=0 ; j<n ; j++)
                scanf("%d", &a[i][j]);
        dp();
        /*for(i=0 ; i<m ; i++){
            for(j=0 ; j<n ; j++) printf("%d ", g[i][j]);
            printf("\n");
        }*/
        for(max=0,q=0 ; q<m ; q++) {
            for(b=0 ; b<n ; b++)
                for(c=q ; c<m ; c++)
                    for(d=b ; d<n ; d++) {
                        p= c-q;f= d-b;
                        w= (p+1)*(f+1);
                        sum= g[c][d]- g[c][b-1]-g[q-1][d]+g[q-1][b-1];
                        if(sum==0 && w>max) max= w;
                    }
        }
        printf("%d\n", max);
    }
    return 0;
}
