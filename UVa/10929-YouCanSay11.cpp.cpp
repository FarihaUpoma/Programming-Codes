#include <stdio.h>
#include <string.h>

int main()
{
    int sum1, sum2 , diff, i,k;
    char a[1000009];
    while(scanf("%s", a)!=EOF)
    {
        if( strcmp(a , "0") == 0) break;
        else {
            sum1=0; sum2=0;
            for(i=0 ; i<strlen(a) ; i=i+2) {
                sum1=sum1+ a[i]-48;
            }
            for(k=1 ; k<strlen(a) ; k=k+2) {
                sum2=sum2+ a[k]-48;
            }
            diff=sum1-sum2;
            if(diff%11==0) printf("%s is a multiple of 11.\n", a);
            else printf("%s is not a multiple of 11.\n", a);
        }
    }
    return 0;
}
