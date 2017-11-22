#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int a[1000009];

int main()
{
    int t, i, n, j, d, indx, c, max;
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%d", &n);
        a[0]=0;
        for(max=0,j=1 ; j<=n ; j++)
        {
            scanf("%d", &a[j]);
            if(a[j]-a[j-1]>max) max= a[j]-a[j-1];
        }
        int s;
        while(1)
        {
            s=max;
            for(j=1 ; j<=n ; j++)
            {
                if(a[j]-a[j-1]==s) s--;
                else if(a[j]-a[j-1]>s) {
                    max++;
                    break;
                }
                //printf("s=%d\n", s);
                if(s==0) {
                    max++;
                    break;
                }
            }
            if(j==n+1) break;
        }
        printf("Case %d: %d\n",i+1, max);
    }
    return 0;
}
