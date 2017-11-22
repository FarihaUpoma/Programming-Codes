#include <stdio.h>
#include <string.h>

int sopf( int n )
{
    int i,j, l, sum;
    char b[100000];
    //scanf("%d", &n);
    for(i=1, j=0 ; i<n ; i++)
        if(n%i==0) {
            b[j] = n/i+48;
            j++;
        }
    b[j]=0;
    l=strlen(b);
    //printf("%s %d %d\n", b, j, l);
    for(j=l-1, sum=0 ; j>0 ; j--)
        sum=sum+b[j]-48;
    //printf("%d\n", sum);
    return sum;
}

int main()
{
    int n, i, j, c=0, m, max=0;
    scanf("%d %d", &n, &m);
    for(j=n ; j<=m ; j++) {
        c=0;
        for(i=j ; ; i=sopf(i)) {
            c++;
            if(sopf(i) == 0) break;
        }
        printf("%d\n", c);
        if(c>max) max=c;
    }
    printf("%d", max);
    return 0;
}
