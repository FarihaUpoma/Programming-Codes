#include <stdio.h>

int g[1000][1000], q[1000][1000], n;

void dp()
{
    int i, j;
    g[0][0]= q[0][0];
    for(i=0 ; i<2*n ; i++) {
        g[0][i]= g[0][i-1]+q[0][i];
        g[i][0]= g[i-1][0]+q[i][0];
    }
    for(i=0 ; i<2*n ; i++)
        for(j=0 ; j<2*n ; j++)
            g[i][j]= g[i-1][j]+g[i][j-1]- g[i-1][j-1]+q[i][j];
}

int main()
{
    int t, i, j, k, a, b, c, d, max, sum;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        for(j=0 ; j<n ; j++)
            for(k=0 ; k<n ; k++)
                scanf("%d", &q[j][k]);
        for(k=0 ; k<n ; k++)
            for(a=0, j=a+n ; a<n ; j++,a++)
                q[k][j]= q[k][a];
        for(k=0,a=k+n ; k<n ; k++, a++)
            for(j=0 ; j<2*n ; j++)
                q[a][j]= q[k][j];
        /*for(j=0 ; j<2*n ; j++) {
            for(k=0 ; k<2*n ; k++) printf("%d ", q[j][k]);
            printf("\n");
        }*/
        dp();
        for(max=0 , a=0 ; a<2*n ; a++) {
            for(b=0 ; b<2*n ; b++)
                for(c= a ; c<2*n ; c++) {
                    if(c-a>=n) break;
                    for(d=b ; d<2*n ; d++) {
                        if(d-b>=n) break;
                        sum= g[c][d]- g[c][b-1]-g[a-1][d]+g[a-1][b-1];
                        if(sum>max) {
                            max=sum;
                        }
                    }
                }
        }
        printf("%d\n",max);
}    }
