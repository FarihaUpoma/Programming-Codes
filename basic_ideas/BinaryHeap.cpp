#include <stdio.h>

int g[2000000], n=1;

void insert(int a)
{
    int i, temp, x;
    g[n]= a;
    x=n;
    for(i=x/2 ; i>=1 ; i=i/2) {
        if( g[x]<g[i] ) {
            temp= g[x];
            g[x]= g[i];
            g[i]= temp;
        }
        x= i;
    }
    n++;
}

int extractMean()
{
    int r, i, temp, k;
    r= g[1];
    g[1]=g[n-1];
    g[n-1]= r;
    n--;
    for(i=1 ; i<n ; i= k) {
        if(g[2*i]<g[2*i+1]) k=2*i;
        else k= 2*i+1;
        if(k>=n) break;
        if(g[i]>g[k]) {
            temp= g[i];
            g[i]= g[k];
            g[k]= temp;
        }
    }
    return r;
}

void decrease_key(int pos, int k)
{
    int b, p, tmp;
    if( g[pos] < k) return;
    g[pos]= k;
    b= pos;
    for( ; ; ) {
        if( g[b/2] > g[b]) {
            tmp= g[b];
            g[b]= g[b/2];
            g[b/2]= tmp;
            b= b/2;
        }
        else break;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int d, i, mean, x, t, pos, k;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &d);
        insert(d);
    }
    x=t;
    for(i=1 ; i<=x ; i++) printf("%d ",g[i]);printf("\n");
    //for(i=1 ; i<n ; i++) printf("%d ", g[i]);
    for(i=1 ; i<=x ; i++)  {
        mean= extractMean();
        printf("%d\n", mean);
    }
    scanf("%d %d" , &pos, &k);
    decrease_key(pos, k);
    for(i=1 ; i<=x ; i++)  {
        mean= extractMean();
        printf("%d\n", mean);
    }
    /*mean= extractMean();
    printf("\n%d\n", mean);
    for(i=1 ; i<n ; i++) printf("%d ", g[i]);*/
    return 0;
}
