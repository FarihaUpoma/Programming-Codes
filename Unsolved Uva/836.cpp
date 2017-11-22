#include <stdio.h>
#include <string.h>

char a[100][100], q[10];
int g[100][100];
int l;

void dp()
{
    int i, j;
    g[0][0]=a[0][0]-'0';
    for(i=0 ; i<l ; i++) {
        g[0][i]= g[0][i-1]+a[0][i]-'0';
        g[i][0]= g[i-1][0]+a[i][0]-'0';
    }
    for(i=1 ; i<l ; i++)
        for(j=1 ; j<l ; j++)
            g[i][j]= g[i][j-1]+g[i-1][j]-g[i-1][j-1]+a[i][j]-'0';
}

int main()
{
    freopen("input.txt", "r", stdin);
    int i, j ,k, t, max, c, d, sum=0, b, in, p, f, m, r;
    scanf("%d", &t);
    getchar();

    for(i=0 ; i<t ; i++) {
        getchar();
        scanf("%s", a[0]);
        l= strlen(a[0]);

        for(in=1 ; in<l ; in++) {
            scanf("%s", a[in]);
        }
        dp();

int w,x,y,z;
        for(max=0,r=0  ; r<l ; r++) {
            for(b=0 ; b<l ; b++)
                for(c=r ; c<l ; c++)
                    for(d=b ; d<l ; d++) {
                        p=c-r;f=d-b;
                        m= (p+1)*(f+1);
                        sum= g[c][d]-g[r-1][d]-g[c][b-1]+g[r-1][b-1];

                        if(sum>max && sum==m) {w=r;x=b;y=c;z=d;max= sum;}
                    }
        }

        printf("(%d,%d)-(%d,%d)= %d\n",w,x,y,z, max);
        //printf("%d\n", max);
        if(i<t-1) printf("\n");
        /*memset(a,0, sizeof(a));
        for(j=0 ; j<l ; j++)
            for(k=0 ; k<l ; k++) g[j][k]=0;*/
        l=0;

    }
}
