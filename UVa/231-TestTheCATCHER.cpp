#include <stdio.h>

int status[100000], a[100000], n;

void lds()
{
    int i, j, maxVal;
    status[0]=1;
    for(i=1 ; i<n ; i++) {
        maxVal= 0;
        for(j=0 ; j<i ; j++)
            if(status[j]>maxVal && a[i]<a[j]) maxVal= status[j];
        status[i]= maxVal+1;
    }
}

int main()
{
  //freopen("input.txt", "r", stdin);
    int i, max, k=1;
    for( ; ; ) {
        n=0;
            scanf("%d", &a[n]);
            if(a[n]==-1) break;
            if(k>1) printf("\n");
        while(scanf("%d", &a[++n])&&a[n]!=-1);
        //n--;
        //printf("n=%d\n", n);
        lds();
        for(max=0,i=0 ; i<n ; i++) if(status[i]>max) max= status[i];
        printf("Test #%d:\n  maximum possible interceptions: %d\n", k++,max);
       for(i=0 ; i<n-1 ; i++) a[i]=0;
        //n=0;
    }
}
