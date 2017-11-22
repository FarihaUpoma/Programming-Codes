#include <stdio.h>

int g[111][111], q[111][111], s;

void dp()
{
    int i, j;
    g[0][0]=q[0][0];
    for(i=1 ; i<s ; i++) {
        g[0][i]= g[0][i-1]+ q[0][i];
        g[i][0]= g[i-1][0]+ q[i][0];
    }
    for(i=0 ; i<s ; i++)
        for(j=1 ; j<s ; j++)
            g[i][j] = g[i-1][j]+g[i][j-1]-g[i-1][j-1]+ q[i][j];
}

int main()
{
    int p, n, i, j, c, d, k, l, a, b, m, max, sum;
    scanf("%d", &p);
    for(i=0 ; i<p ; i++) {
        scanf("%d %d", &s, &n);
        for(j=0 ; j<n ; j++) {
            scanf("%d %d %d %d", &a,&b,&c,&d);
            for(k=a-1; k<c; k++)
                for(l=b-1; l<d ; l++)
                    q[k][l]=1;
        }
        /*for(i=0 ; i<s; i++) {
            for(j=0 ; j<s ; j++)
                printf("%d ", q[i][j]);
            printf("\n");
        }*/
        //printf("alwhf\n");
        dp();
        /*for(i=0 ; i<s; i++) {
            for(j=0 ; j<s ; j++)
                printf("%d ", g[i][j]);
            printf("\n");
        }*/
        int w,x,y,z;
        for(max=0 , a=0 ; a<s ; a++) {
            for(b=0 ; b<s ; b++)
                for(c=a ; c<s ; c++)
                    for(d=b ; d<s ;d++) {
                        k= c-a;l= d-b;
                        m= (k+1)*(l+1);
                        sum= g[c][d]- g[c][b-1]-g[a-1][d]+g[a-1][b-1];
                        if( sum==0 && m>max)max= m;
                    }
        }
        printf("%d\n", max);
        for(k=0 ; k<s ; k++)
            for(l=0 ; l<s ; l++) g[k][l]=0;
        for(k=0 ; k<s ; k++)
            for(l=0 ; l<s ; l++) q[k][l]=0;
    }
}
