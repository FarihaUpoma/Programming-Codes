#include <stdio.h>

long long int status[10000];
int c[10], n;

void dp()
{
    int i, j, coin;
    status[0]= 1;
    for(i=0 ; i<5 ; i++) {
        coin= c[i];
        for(j=0 ; j<8000 ; j++) {
            if(j-coin<0) continue;
            status[j]= status[j]+status[j-coin];
        }
    }
}

int main()
{
    c[0]=1;c[1]=5;c[2]=10;c[3]=25;c[4]=50;
    dp();
    while(scanf("%d", &n)==1)
    {
        printf("%lld\n", status[n]);
    }
    return 0;
}
