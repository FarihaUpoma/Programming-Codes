#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int  l, i;
    int sum;
    char a[1000009];
    while( gets(a)!=NULL)
    {
        if ( strcmp( a, "0") == 0 ) break;
        else {
            l=strlen(a);
            for(i=0, sum=0 ; i<l ; i++){
                sum= sum+( (a[i]-48) * (pow(2, l-i)-1) );
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
