#include <stdio.h>

long long int status[20000];
int c[50], n;

void dp()
{
    int i, j, coin;
    status[0]=1;
    for(i=0 ; i<21 ; i++) {
        coin= c[i];
        for(j=0 ; j<=10000 ; j++) {
            if(j-coin<0) continue;
            status[j]= status[j]+status[j-coin];
        }
    }
}

int main()
{
    int i, j;
    for(i=0,j=1 ; j<22 ; i++, j++)
        c[i]= j*j*j;
    dp();
    while(scanf("%d", &n)==1)
    {
    printf("%lld\n", status[n]);
    }
    return 0;
}
