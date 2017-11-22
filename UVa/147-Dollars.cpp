#include <stdio.h>
#include <math.h>

long long int status[50000];
int c[50], n;

void dp()
{
    int i, j, coin;
    status[0]=1;
    for(i=0 ; i<11 ; i++) {
        coin= c[i];
        for(j=0 ; j<=30000 ; j++) {
            if(j-coin<0) continue;
            status[j]= status[j]+status[j-coin];
        }
    }
}

int main()
{
    double m;
    c[0]=1;c[1]=2;c[2]=4;c[3]=10;c[4]=20;c[5]=40;c[6]=100;c[7]=200;c[8]=400;c[9]=1000;c[10]=2000;
    dp();
    while(scanf("%lf", &m)&&m) {
        n= (m*100+.05)/5;
        printf("%6.2lf%17lld\n",m, status[n]);
    }
    return 0;
}
