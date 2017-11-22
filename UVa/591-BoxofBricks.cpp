#include <stdio.h>

int a[1000009];

int main()
{
    int t, sum,i, b, q=1;
    while(scanf("%d", &t)!=EOF)
    {
        if(t==0) break;
        else {
            sum=0;
            b=0;
            for(i=0 ; i<t ; i++) {
                scanf("%d", &a[i] );
                sum= sum+a[i];
            }

            for(i=0 ; i<t ; i++) {
                if( a[i]< (sum/t) )
                    b=b+(sum/t)- a[i];
            }
            printf("Set #%d\n", q);
            printf("The minimum number of moves is %d.\n\n", b);
            q++;
        }
    }
    return 0;
}
