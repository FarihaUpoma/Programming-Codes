#include <stdio.h>

long long int status[50000];
int c[10], n;

void dp()
{
    int i, coin, j;
    status[0]=1;
    for(i=0 ; i<5 ; i++) {
        coin= c[i];
        for(j=0 ; j<=30000 ; j++) {
            if(j-coin<0) continue;
            status[j]= status[j]+status[j-coin];
        }
    }
}

int main()
{

    c[0]= 1;c[1]=5;c[2]=10;c[3]=25;c[4]=50;
    dp();
    while(scanf("%d", &n)==1)
    {
        if(status[n]==1) printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", status[n], n);

    }
    return 0;
}
