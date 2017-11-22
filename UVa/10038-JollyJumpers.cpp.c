#include <stdio.h>

 int a[5000] , b[5000];

int main()
{
    int n, c;
    int i,j,k;
    while(scanf("%d", &n)!= EOF)
    {
        c=0;
        for(i=0 ; i<n ; i++)
            scanf("%d", &a[i] );
        for(i=0; i<n-1 ; i++)
            b[i] = 1;
        for(i=0, j=i+1 ; i<n-1 ; i++, j++) {
            if(a[i] > a[j])
                b[ a[i]-a[j] -1 ]= 0;
            else
                b[ a[j]- a[i] -1]= 0;
        }
        for(i=0 ; i<n-1 ; i++)
            if(b[i]==1) c++;
        if( c==0 )
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
